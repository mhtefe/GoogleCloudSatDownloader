#include "SearcherLS8.h"

SearcherLS8::SearcherLS8()
{
	m_go = true;

	setCloudCover(Nan);
	setLat(Nan);
	setLon(Nan);
}

SearcherLS8::SearcherLS8(QString _indexFile) : SearcherBase(_indexFile)
{
	m_go = true;

	setCloudCover(Nan);
	setLat(Nan);
	setLon(Nan);
}

void SearcherLS8::DoSetup(QThread &cthread)
{
	connect(&cthread, SIGNAL(started()), this, SLOT(DoWork()));
}

void SearcherLS8::DoWork()
{
	cout << "Search LS8..." << endl;

	emit searchStarted();

	m_go = true;
	int i = 0;
	int foundSize = 0;
	m_vlb.clear();

	time_t _tic, _toc;
	string csv_google_LS8 = m_indexFile.toStdString();

	GCP_LANDSAT8_LABEL lb;

	io::CSVReader<18> inLS8(csv_google_LS8);
	inLS8.read_header(io::ignore_extra_column,
		"SCENE_ID",
		"PRODUCT_ID",
		"SPACECRAFT_ID",
		"SENSOR_ID",
		"DATE_ACQUIRED",
		"COLLECTION_NUMBER",
		"COLLECTION_CATEGORY",
		"SENSING_TIME",
		"DATA_TYPE",
		"WRS_PATH",
		"WRS_ROW",
		"CLOUD_COVER",
		"NORTH_LAT",
		"SOUTH_LAT",
		"WEST_LON",
		"EAST_LON",
		"TOTAL_SIZE",
		"BASE_URL");

	std::string LS8_SCENE_ID;
	std::string LS8_PRODUCT_ID;
	std::string LS8_SPACECRAFT_ID;
	std::string LS8_SENSOR_ID;
	std::string LS8_DATE_ACQUIRED;
	std::string LS8_COLLECTION_NUMBER;
	std::string LS8_COLLECTION_CATEGORY;
	std::string LS8_SENSING_TIME;
	std::string LS8_DATA_TYPE;
	std::string LS8_WRS_PATH;
	std::string LS8_WRS_ROW;
	std::string LS8_CLOUD_COVER;
	std::string LS8_NORTH_LAT;
	std::string LS8_SOUTH_LAT;
	std::string LS8_WEST_LON;
	std::string LS8_EAST_LON;
	std::string LS8_TOTAL_SIZE;
	std::string LS8_BASE_URL;

	QDate dateF = getFirstDate();
	QDate dateL = getLastDate();
	double clo = getCloudCover();

	int tester = 0;

	_tic = time(0);
	while (inLS8.read_row(LS8_SCENE_ID,
		LS8_PRODUCT_ID,
		LS8_SPACECRAFT_ID,
		LS8_SENSOR_ID,
		LS8_DATE_ACQUIRED,
		LS8_COLLECTION_NUMBER,
		LS8_COLLECTION_CATEGORY,
		LS8_SENSING_TIME,
		LS8_DATA_TYPE,
		LS8_WRS_PATH,
		LS8_WRS_ROW,
		LS8_CLOUD_COVER,
		LS8_NORTH_LAT,
		LS8_SOUTH_LAT,
		LS8_WEST_LON,
		LS8_EAST_LON,
		LS8_TOTAL_SIZE,
		LS8_BASE_URL) && m_go /*&& tester++ < 1000000*/)
	{
		//QThread::currentThread()->msleep(1);

		if (i++ % 10000 == 0)
		{
			emit currentStatus(i, foundSize);
		}

		QDate dateAcquired_incoming = QDate::fromString(QString::fromStdString(LS8_DATE_ACQUIRED), "yyyy-MM-dd");
		double cloud_incoming = std::stod(LS8_CLOUD_COVER);
		double lat_min_incoming = std::stod(LS8_SOUTH_LAT);
		double lat_max_incoming = std::stod(LS8_NORTH_LAT);
		double lon_min_incoming = std::stod(LS8_WEST_LON);
		double lon_max_incoming = std::stod(LS8_EAST_LON);

		if (allCriterias(dateAcquired_incoming, cloud_incoming, lat_min_incoming, lat_max_incoming, lon_min_incoming, lon_max_incoming))
		{
			std::cout << "path: " << LS8_WRS_PATH << " - row: " << LS8_WRS_ROW << std::endl;

			lb.LS8_SCENE_ID = QString::fromStdString(LS8_SCENE_ID);
			lb.LS8_PRODUCT_ID = QString::fromStdString(LS8_PRODUCT_ID);
			lb.LS8_SPACECRAFT_ID = QString::fromStdString(LS8_SPACECRAFT_ID);
			lb.LS8_SENSOR_ID = QString::fromStdString(LS8_SENSOR_ID);
			lb.LS8_DATE_ACQUIRED = dateAcquired_incoming;
			lb.LS8_SENSING_TIME = QTime::fromString(QString::fromStdString(LS8_SENSING_TIME));
			lb.LS8_CLOUD_COVER = std::stod(LS8_CLOUD_COVER);

			lb.LS8_WRS_PATH = zeroFrontPathRow(LS8_WRS_PATH);
			lb.LS8_WRS_ROW = zeroFrontPathRow(LS8_WRS_ROW);

			lb.LS8_NORTH_LAT = lat_max_incoming;
			lb.LS8_SOUTH_LAT = lat_min_incoming;
			lb.LS8_EAST_LON = lon_max_incoming;
			lb.LS8_WEST_LON = lon_min_incoming;

			lb.LS8_BASE_URL = QString::fromStdString(LS8_BASE_URL);

			m_vlb.push_back(lb);

			foundSize++;
			emit currentStatus(i, foundSize);
		}
	}
	_toc = time(0);
	std::cout << "Elapsed Time: " << difftime(_toc, _tic) << " sec. " << std::endl;

	emit searchFinished();
}

bool SearcherLS8::compareLS8LabelByDate(GCP_LANDSAT8_LABEL i1, GCP_LANDSAT8_LABEL i2)
{
	return (i1.LS8_DATE_ACQUIRED > i2.LS8_DATE_ACQUIRED);
}


void SearcherLS8::DoTerminate(void)
{
	m_go = false;
}
