#include "SearcherS2.h"

SearcherS2::SearcherS2()
{
	m_go = true;

	setCloudCover(Nan);
	setLat(Nan);
	setLon(Nan);
}

SearcherS2::SearcherS2(QString _indexFile) : SearcherBase(_indexFile)
{
	m_go = true;

	setCloudCover(Nan);
	setLat(Nan);
	setLon(Nan);
}

void SearcherS2::DoSetup(QThread &cthread)
{
	connect(&cthread, SIGNAL(started()), this, SLOT(DoWork()));
}

void SearcherS2::DoWork()
{
	cout << "Search S2..." << endl;

	emit searchStarted();

	m_go = true;
	int i = 0;
	int foundSize = 0;
	m_vlb.clear();

	time_t _tic, _toc;
	//string csv_google_LS8 = "C:/Users/memo/Desktop/landsat-sentinel/LS_S2downloader/LS_S2downloader/indexLS8.csv";
	string csv_google_S2 = m_indexFile.toStdString();

	GCP_SENTINEL2_LABEL lb;

	io::CSVReader<14> inS2(csv_google_S2);
	inS2.read_header(io::ignore_extra_column,
		"GRANULE_ID",
		"PRODUCT_ID",
		"DATATAKE_IDENTIFIER",
		"MGRS_TILE",
		"SENSING_TIME",
		"TOTAL_SIZE",
		"CLOUD_COVER",
		"GEOMETRIC_QUALITY_FLAG",
		"GENERATION_TIME",
		"NORTH_LAT",
		"SOUTH_LAT",
		"WEST_LON",
		"EAST_LON",
		"BASE_URL");

	std::string S2_GRANULE_ID;
	std::string S2_PRODUCT_ID;
	std::string S2_DATATAKE_IDENTIFIER;
	std::string S2_MGRS_TILE;
	std::string S2_SENSING_TIME;
	std::string S2_TOTAL_SIZE;
	std::string S2_CLOUD_COVER;
	std::string S2_GEOMETRIC_QUALITY_FLAG;
	std::string S2_GENERATION_TIME;
	std::string S2_NORTH_LAT;
	std::string S2_SOUTH_LAT;
	std::string S2_WEST_LON;
	std::string S2_EAST_LON;
	std::string S2_BASE_URL;

	QDate dateF = getFirstDate();
	QDate dateL = getLastDate();
	double clo = getCloudCover();

	int tester = 0;

	_tic = time(0);
	while (inS2.read_row(S2_GRANULE_ID,
		S2_PRODUCT_ID,
		S2_DATATAKE_IDENTIFIER,
		S2_MGRS_TILE,
		S2_SENSING_TIME,
		S2_TOTAL_SIZE,
		S2_CLOUD_COVER,
		S2_GEOMETRIC_QUALITY_FLAG,
		S2_GENERATION_TIME,
		S2_NORTH_LAT,
		S2_SOUTH_LAT,
		S2_WEST_LON,
		S2_EAST_LON,
		S2_BASE_URL) && m_go /*&& tester++ < 1000000*/)
	{
		if (i++ % 10000 == 0)
		{
			emit currentStatus(i, foundSize);
		}

		QDate dateAcquired_incoming = QDate::fromString(QString::fromStdString(S2_SENSING_TIME).mid(0,10), "yyyy-MM-dd");
		double cloud_incoming = std::stod(S2_CLOUD_COVER);
		double lat_min_incoming = std::stod(S2_SOUTH_LAT);
		double lat_max_incoming = std::stod(S2_NORTH_LAT);
		double lon_min_incoming = std::stod(S2_WEST_LON);
		double lon_max_incoming = std::stod(S2_EAST_LON);

		if (allCriterias(dateAcquired_incoming, cloud_incoming, lat_min_incoming, lat_max_incoming, lon_min_incoming, lon_max_incoming))
		{
			std::cout << "S2_MGRS_TILE: " << S2_MGRS_TILE << std::endl;

			lb.S2_GRANULE_ID = QString::fromStdString(S2_GRANULE_ID);
			lb.S2_PRODUCT_ID = QString::fromStdString(S2_PRODUCT_ID);
			lb.S2_DATATAKE_IDENTIFIER = QString::fromStdString(S2_DATATAKE_IDENTIFIER);
			lb.S2_MGRS_TILE = QString::fromStdString(S2_MGRS_TILE);
			lb.S2_SENSING_TIME = dateAcquired_incoming;
			lb.S2_CLOUD_COVER = std::stod(S2_CLOUD_COVER);

			lb.S2_NORTH_LAT = lat_max_incoming;
			lb.S2_SOUTH_LAT = lat_min_incoming;
			lb.S2_EAST_LON = lon_max_incoming;
			lb.S2_WEST_LON = lon_min_incoming;

			lb.S2_BASE_URL = QString::fromStdString(S2_BASE_URL);

			m_vlb.push_back(lb);

			foundSize++;
			emit currentStatus(i, foundSize);
		}
	}
	_toc = time(0);
	std::cout << "Elapsed Time: " << difftime(_toc, _tic) << " sec. " << std::endl;

	emit searchFinished();
}


void SearcherS2::DoTerminate(void)
{
	m_go = false;
}
