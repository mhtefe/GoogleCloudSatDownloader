/*!
 * \class landsatimagedownloader
 *
 * \author mehmet.efendioglu
 *
 * \version 1.0
 *
 */

#include "GCSatDownloader.h"
#include "ui_gcsatdownloader.h"

using namespace std;

GCSatDownloader::GCSatDownloader(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GcSatDownloader)
{
	setupUiComponents();

	////////////////////////////////////////////////////////////////////////// ui paths
	setupUiPaths();

	////////////////////////////////////////////////////////////////////////// searcher&downloader
	setupUiSearcherDownloader();

	////////////////////////////////////////////////////////////////////////// bands
	setupUiBandCombo();

	//////////////////////////////////////////////////////////////////////////

}

GCSatDownloader::~GCSatDownloader()
{
    delete ui;
}

void GCSatDownloader::setupUiBandCombo()
{
	ui->comboBox_Bands_LS8->addItem("All");
	ui->comboBox_Bands_LS8->addItem("Band 1 - Coastal aerosol");
	ui->comboBox_Bands_LS8->addItem("Band 2 - Blue");
	ui->comboBox_Bands_LS8->addItem("Band 3 - Green");
	ui->comboBox_Bands_LS8->addItem("Band 4 - Red");
	ui->comboBox_Bands_LS8->addItem("Band 5 - Near Infrared (NIR)");
	ui->comboBox_Bands_LS8->addItem("Band 6 - SWIR 1");
	ui->comboBox_Bands_LS8->addItem("Band 7 - SWIR 2");
	ui->comboBox_Bands_LS8->addItem("Band 8 - Panchromatic");
	ui->comboBox_Bands_LS8->addItem("Band 9 - Cirrus");
	ui->comboBox_Bands_LS8->addItem("Band 10 - Thermal Infrared (TIRS) 1");
	ui->comboBox_Bands_LS8->addItem("Band 11 - Thermal Infrared (TIRS) 2");
	ui->comboBox_Bands_LS8->addItem("BQA");
	ui->comboBox_Bands_LS8->addItem("ANG");
	ui->comboBox_Bands_LS8->addItem("MTL");

	ui->comboBox_Bands_S2->addItem("All");
	ui->comboBox_Bands_S2->addItem("Band 1  ");
	ui->comboBox_Bands_S2->addItem("Band 2  ");
	ui->comboBox_Bands_S2->addItem("Band 3  ");
	ui->comboBox_Bands_S2->addItem("Band 4  ");
	ui->comboBox_Bands_S2->addItem("Band 5  ");
	ui->comboBox_Bands_S2->addItem("Band 6  ");
	ui->comboBox_Bands_S2->addItem("Band 7  ");
	ui->comboBox_Bands_S2->addItem("Band 8  ");
	ui->comboBox_Bands_S2->addItem("Band 9  ");
	ui->comboBox_Bands_S2->addItem("Band 10  ");
	ui->comboBox_Bands_S2->addItem("Band 11  ");
	ui->comboBox_Bands_S2->addItem("Band 12  ");
	ui->comboBox_Bands_S2->addItem("Band 8A  ");
	ui->comboBox_Bands_S2->addItem("Band TCI ");
}

void GCSatDownloader::setupUiComponents()
{
	ui->setupUi(this);

	setAcceptDrops(true);

	QDate tdy = QDate::currentDate();
	ui->dateEdit_first_LS8->setDate(QDate(2013, 1, 1));
	ui->dateEdit_last_LS8->setDate(tdy);
	ui->LineEdit_Cloud_LS8->setText(QString("10"));
	ui->dateEdit_first_S2->setDate(QDate(2015, 6, 23));
	ui->dateEdit_last_S2->setDate(tdy);
	ui->LineEdit_Cloud_S2->setText(QString("10"));


	ui->tableWidget_datas_LS8->setSelectionBehavior(QAbstractItemView::SelectRows);
	QStringList labels;
	labels << tr("Scene ID") << tr("Date Acquired") << tr("Cloud");
	ui->tableWidget_datas_LS8->setHorizontalHeaderLabels(labels);
	ui->tableWidget_datas_LS8->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
	ui->tableWidget_datas_LS8->setShowGrid(false);
	connect(ui->tableWidget_datas_LS8, SIGNAL(cellClicked(int, int)), this, SLOT(showFileOfItem_LS8(int, int)));

	ui->tableWidget_datas_S2->setSelectionBehavior(QAbstractItemView::SelectRows);
	QStringList labels2;
	labels2 << tr("Product Id") << tr("Date Acquired") << tr("Cloud");
	ui->tableWidget_datas_S2->setHorizontalHeaderLabels(labels2);
	ui->tableWidget_datas_S2->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
	ui->tableWidget_datas_S2->setShowGrid(false);
	connect(ui->tableWidget_datas_S2, SIGNAL(cellClicked(int, int)), this, SLOT(showFileOfItem_S2(int, int)));

	//ui->tableWidget_datas_S2->insertRow(ui->tableWidget_datas_S2->rowCount());
	//CustomProgressBarTableWidgetItem *pgbar = new CustomTableWCustomProgressBarTableWidgetItemidgetItem();
	//pgbar->setText(QString("asdasd"));
	//pgbar->setValue(50);
	//ui->tableWidget_datas_S2->setCellWidget(ui->tableWidget_datas_S2->rowCount() - 1, 0, pgbar);
	//ui->tableWidget_datas_S2->setItem(ui->tableWidget_datas_S2->rowCount() - 1, 0, pgbar);
	
	ui->LineEdit_Lat_LS8->setValidator(new QDoubleValidator(-90, 90, 5, this)); // latitude (-90, 90)
	ui->LineEdit_Lon_LS8->setValidator(new QDoubleValidator(-180, 180, 5, this));  // longitude (-180, 180)
	ui->LineEdit_Cloud_LS8->setValidator(new QDoubleValidator(0, 100, 2, this));
	ui->LineEdit_Lat_S2->setValidator(new QDoubleValidator(-90, 90, 5, this)); // latitude (-90, 90)
	ui->LineEdit_Lon_S2->setValidator(new QDoubleValidator(-180, 180, 5, this));  // longitude (-180, 180)
	ui->LineEdit_Cloud_S2->setValidator(new QDoubleValidator(0, 100, 2, this));
}

void GCSatDownloader::setupUiPaths()
{
	m_workingDirectory = QString::fromStdString(getWorkingDIR());
	m_scene_dir = m_workingDirectory + QString("\\") + Settings::getGeneral_SceneFolderName();
	if (!QDir(m_scene_dir).exists())
	{
		QDir().mkdir(m_scene_dir);
	}

	m_LS8_scene_rawFile = m_scene_dir + QString("\\") + QString("LS8_index.csv.gz");
	m_LS8_scene_extractFile = m_scene_dir + QString("\\") + QString("LS8_index.csv");
	m_LS8_ls8Index = QString("https://storage.googleapis.com/gcp-public-data-landsat/index.csv.gz");
	if (QFileInfo(m_LS8_scene_extractFile).exists())
		ui->lineEdit_Index_LS8->insert(m_LS8_scene_extractFile);


	m_S2_scene_rawFile = m_scene_dir + QString("\\") + QString("S2_index.csv.gz");
	m_S2_scene_extractFile = m_scene_dir + QString("\\") + QString("S2_index.csv");
	m_S2_ls8Index = QString("https://storage.googleapis.com/gcp-public-data-sentinel-2/index.csv.gz");
	if (QFileInfo(m_S2_scene_extractFile).exists())
		ui->lineEdit_Index_S2->insert(m_S2_scene_extractFile);


	//////////////////////////////////////////////////////////////////////////
	m_images_dir = m_workingDirectory + QString("\\") + Settings::getGeneral_ImagesFolderName();
	if (!QDir(m_images_dir).exists())
	{
		QDir().mkdir(m_images_dir);
	}
}

void GCSatDownloader::setupUiSearcherDownloader()
{
	searchThread_LS8 = new QThread();
	m_LS8_Searcher = new SearcherLS8(m_LS8_scene_extractFile);
	connect(m_LS8_Searcher, SIGNAL(searchStarted()), this, SLOT(afterSearchStarted()));
	connect(m_LS8_Searcher, SIGNAL(searchFinished()), this, SLOT(afterSearchFinished()));
	connect(m_LS8_Searcher, SIGNAL(currentStatus(int, int)), this, SLOT(updateCurrentStatus(int, int)));
	connect(m_LS8_Searcher, SIGNAL(foundElementsSize(int)), this, SLOT(afterFoundSize(int)));
	m_LS8_Searcher->moveToThread(searchThread_LS8);
	m_LS8_Searcher->DoSetup(*searchThread_LS8);

	searchThread_S2 = new QThread();
	m_S2_Searcher = new SearcherS2(m_S2_scene_extractFile);
	connect(m_S2_Searcher, SIGNAL(searchStarted()), this, SLOT(afterSearchStarted()));
	connect(m_S2_Searcher, SIGNAL(searchFinished()), this, SLOT(afterSearchFinished()));
	connect(m_S2_Searcher, SIGNAL(currentStatus(int, int)), this, SLOT(updateCurrentStatus(int, int)));
	connect(m_S2_Searcher, SIGNAL(foundElementsSize(int)), this, SLOT(afterFoundSize(int)));
	m_S2_Searcher->moveToThread(searchThread_S2);
	m_S2_Searcher->DoSetup(*searchThread_S2);

	m_datas_Index_LS8 = -1;
	m_datas_Index_S2 = -1;

	downloadthread = new QThread();
	downloadManager = new DownloadManager();
	connect(downloadManager, SIGNAL(finishedSaveFile(QString)), this, SLOT(afterDownloadFinished(QString)));
	connect(downloadManager, SIGNAL(finished()), this, SLOT(afterAllDownloadsFinished()));
	downloadManager->moveToThread(downloadthread);
	downloadManager->DoSetup(*downloadthread);
}

void GCSatDownloader::on_pushButton_search_LS8_clicked()
{
	if (!QFileInfo(m_LS8_scene_extractFile).exists())
	{
		ui->lineEdit_Info_LS8->setStyleSheet("background-color: orange");
		ui->lineEdit_Info_LS8->setText(QString("Index file does not exist."));
		return;
	}

	if (ui->tableWidget_datas_LS8->rowCount() > 0)
	{
		ui->tableWidget_datas_LS8->model()->removeRows(0, ui->tableWidget_datas_LS8->rowCount());
		ui->tableWidget_datas_LS8->setRowCount(0);
		m_datas_Index_LS8 = -1;
	}
	
	double clo;
	if (!ui->LineEdit_Cloud_LS8->text().isEmpty())
		clo = ui->LineEdit_Cloud_LS8->text().toDouble();
	else
		clo = Nan;

	QDate fdt = ui->dateEdit_first_LS8->date();
	QDate ldt = ui->dateEdit_last_LS8->date();

	double lat;
	if (!ui->LineEdit_Lat_LS8->text().isEmpty())
		lat = ui->LineEdit_Lat_LS8->text().toDouble();
	else
		lat = Nan;

	double lon;
	if (!ui->LineEdit_Lon_LS8->text().isEmpty())
		lon = ui->LineEdit_Lon_LS8->text().toDouble();
	else
		lon = Nan;

	m_LS8_Searcher->setSearchParameters(clo, fdt, ldt, lat, lon);
	searchThread_LS8->start();
}

void GCSatDownloader::on_pushButton_search_S2_clicked()
{
	if (!QFileInfo(m_S2_scene_extractFile).exists())
	{
		ui->lineEdit_Info_S2->setStyleSheet("background-color: orange");
		ui->lineEdit_Info_S2->setText(QString("Index file does not exist."));
		return;
	}

	if (ui->tableWidget_datas_S2->rowCount() > 0)
	{
		ui->tableWidget_datas_S2->model()->removeRows(0, ui->tableWidget_datas_S2->rowCount());
		ui->tableWidget_datas_S2->setRowCount(0);
		m_datas_Index_S2 = -1;
	}

	double clo;
	if (!ui->LineEdit_Cloud_S2->text().isEmpty())
		clo = ui->LineEdit_Cloud_S2->text().toDouble();
	else
		clo = Nan;

	QDate fdt = ui->dateEdit_first_S2->date();
	QDate ldt = ui->dateEdit_last_S2->date();

	double lat;
	if (!ui->LineEdit_Lat_S2->text().isEmpty())
		lat = ui->LineEdit_Lat_S2->text().toDouble();
	else
		lat = Nan;

	double lon;
	if (!ui->LineEdit_Lon_S2->text().isEmpty())
		lon = ui->LineEdit_Lon_S2->text().toDouble();
	else
		lon = Nan;

	m_S2_Searcher->setSearchParameters(clo, fdt, ldt, lat, lon);
	searchThread_S2->start();
}

void GCSatDownloader::on_pushButton_stop_LS8_clicked()
{
	m_LS8_Searcher->DoTerminate();
	searchThread_LS8->terminate();
}

void GCSatDownloader::on_pushButton_stop_S2_clicked()
{
	m_S2_Searcher->DoTerminate();
	searchThread_S2->terminate();
}

void GCSatDownloader::afterSearchFinished()
{
	QObject * obj = sender();
	SearcherLS8 *s1 = dynamic_cast<SearcherLS8 *>(obj);
	if (s1 != nullptr)
	{
		m_LS8_Searcher->DoTerminate();
		searchThread_LS8->terminate();
		listSearchResults_LS8();
	}

	SearcherS2 *s2 = dynamic_cast<SearcherS2 *>(obj);
	if (s2 != nullptr)
	{
		m_S2_Searcher->DoTerminate();
		searchThread_S2->terminate();
		listSearchResults_S2();
	}
}

void GCSatDownloader::updateCurrentStatus(int i, int j)
{
	QObject * obj = sender();
	SearcherLS8 *s1 = dynamic_cast<SearcherLS8 *>(obj);
	if (s1 != nullptr)
	{
		ui->lineEdit_Info_LS8->setText(QString::number(j).append(tr(" / ")).append(QString::number(i)));
	}

	SearcherS2 *s2 = dynamic_cast<SearcherS2 *>(obj);
	if (s2 != nullptr)
	{
		ui->lineEdit_Info_S2->setText(QString::number(j).append(tr(" / ")).append(QString::number(i)));
	}
}

void GCSatDownloader::listSearchResults_LS8()
{
	if (m_LS8_Searcher->m_vlb.size() == 0)
	{
		ui->lineEdit_Info_LS8->setStyleSheet("background-color: red");
		ui->lineEdit_Info_LS8->setText(tr("Listelenecek Veri Bulunamadi..."));
		return;
	}

	int i;
	for (i = 0; i < m_LS8_Searcher->m_vlb.size(); ++i)
	{
		GCP_LANDSAT8_LABEL scn = m_LS8_Searcher->m_vlb[i];

		QTableWidgetItem *sceneId = new QTableWidgetItem(QString(scn.LS8_SCENE_ID));
		sceneId->setFlags(sceneId->flags() ^ Qt::ItemIsEditable);

		QTableWidgetItem *acqDate = new QTableWidgetItem(QString(scn.LS8_DATE_ACQUIRED.toString("dd.MM.yyyy")));
		acqDate->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
		acqDate->setFlags(acqDate->flags() ^ Qt::ItemIsEditable);

		QTableWidgetItem *cloud = new QTableWidgetItem(QString::number(scn.LS8_CLOUD_COVER));
		cloud->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		cloud->setFlags(cloud->flags() ^ Qt::ItemIsEditable);


		int row = ui->tableWidget_datas_LS8->rowCount();
		ui->tableWidget_datas_LS8->insertRow(row);
		ui->tableWidget_datas_LS8->setItem(row, 0, sceneId);
		ui->tableWidget_datas_LS8->setItem(row, 1, acqDate);
		ui->tableWidget_datas_LS8->setItem(row, 2, cloud);
	}
}

void GCSatDownloader::listSearchResults_S2()
{
	if (m_S2_Searcher->m_vlb.size() == 0)
	{
		ui->lineEdit_Info_S2->setStyleSheet("background-color: red");
		ui->lineEdit_Info_S2->setText(tr("No data found in query."));
		return;
	}

	int i;
	for (i = 0; i < m_S2_Searcher->m_vlb.size(); ++i)
	{
		GCP_SENTINEL2_LABEL scn = m_S2_Searcher->m_vlb[i];

		QTableWidgetItem *sceneId = new QTableWidgetItem(QString(scn.S2_PRODUCT_ID));
		sceneId->setFlags(sceneId->flags() ^ Qt::ItemIsEditable);

		QTableWidgetItem *acqDate = new QTableWidgetItem(QString(scn.S2_SENSING_TIME.toString("dd.MM.yyyy")));
		acqDate->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
		acqDate->setFlags(acqDate->flags() ^ Qt::ItemIsEditable);

		QTableWidgetItem *cloud = new QTableWidgetItem(QString::number(scn.S2_CLOUD_COVER));
		cloud->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		cloud->setFlags(cloud->flags() ^ Qt::ItemIsEditable);

		int row = ui->tableWidget_datas_S2->rowCount();
		ui->tableWidget_datas_S2->insertRow(row);
		ui->tableWidget_datas_S2->setItem(row, 0, sceneId);
		ui->tableWidget_datas_S2->setItem(row, 1, acqDate);
		ui->tableWidget_datas_S2->setItem(row, 2, cloud);
	}
}

void GCSatDownloader::showFileOfItem_LS8(int row, int /* column */)
{
	m_datas_Index_LS8 = row;
	updateInfoTags_LS8(row);
}

void GCSatDownloader::showFileOfItem_S2(int row, int /* column */)
{
	m_datas_Index_S2 = row;
	updateInfoTags_S2(row);
}

void GCSatDownloader::updateInfoTags_LS8(int row)
{
	GCP_LANDSAT8_LABEL scn = m_LS8_Searcher->m_vlb[row];
	ui->label_1_LS8->setText(scn.LS8_SCENE_ID);
	ui->label_2_LS8->setText(scn.LS8_PRODUCT_ID);
	ui->label_3_LS8->setText(scn.LS8_SPACECRAFT_ID);
	ui->label_4_LS8->setText(scn.LS8_SENSOR_ID);
	ui->label_5_LS8->setText(scn.LS8_DATE_ACQUIRED.toString("dd.MM.yyyy"));
	ui->label_6_LS8->setText(scn.LS8_SENSING_TIME.toString("hh:mm:ss"));
	ui->label_7_LS8->setText( QString::number(scn.LS8_CLOUD_COVER));

	ui->LineEdit_North_LS8->setText( QString::number( scn.LS8_NORTH_LAT) );
	ui->LineEdit_South_LS8->setText( QString::number( scn.LS8_SOUTH_LAT) );
	ui->LineEdit_East_LS8->setText(QString::number(scn.LS8_EAST_LON));
	ui->LineEdit_West_LS8->setText(QString::number(scn.LS8_WEST_LON));

	ui->lineEdit_Info_LS8->setText(scn.LS8_BASE_URL);
}

void GCSatDownloader::updateInfoTags_S2(int row)
{
	GCP_SENTINEL2_LABEL scn = m_S2_Searcher->m_vlb[row];
	ui->label_1_S2->setText(scn.S2_GRANULE_ID);
	ui->label_2_S2->setText(scn.S2_PRODUCT_ID);
	ui->label_3_S2->setText(scn.S2_MGRS_TILE);
	ui->label_4_S2->setText(scn.S2_SENSING_TIME.toString("dd.MM.yyyy"));
	ui->label_5_S2->setText(QString::number(scn.S2_CLOUD_COVER));

	ui->LineEdit_North_S2->setText(QString::number(scn.S2_NORTH_LAT));
	ui->LineEdit_South_S2->setText(QString::number(scn.S2_SOUTH_LAT));
	ui->LineEdit_East_S2->setText(QString::number(scn.S2_EAST_LON));
	ui->LineEdit_West_S2->setText(QString::number(scn.S2_WEST_LON));

	ui->lineEdit_Info_S2->setText(scn.S2_BASE_URL);
}

void GCSatDownloader::on_pushButton_DownloadIndex_LS8_clicked()
{
	this->statusBar()->setStyleSheet("background-color: yellow");
	this->statusBar()->showMessage(tr("Downloading LS8 index file..."));

	QDir dir(m_scene_dir);
	if (QFileInfo().exists(m_LS8_scene_rawFile))
	{
		QDir dir(m_scene_dir);
		dir.remove(m_LS8_scene_rawFile);
	}

	downloadManager->append(m_LS8_ls8Index, m_LS8_scene_rawFile, DownloadType::ConfigFile);
	
	if (!downloadthread->isRunning())
	{
		downloadthread->start();
	}
}

void GCSatDownloader::on_pushButton_DownloadIndex_S2_clicked()
{
	this->statusBar()->setStyleSheet("background-color: yellow");
	this->statusBar()->showMessage(tr("Downloading S2 index file."));

	QDir dir(m_scene_dir);
	if (QFileInfo().exists(m_S2_scene_rawFile))
	{
		QDir dir(m_scene_dir);
		dir.remove(m_S2_scene_rawFile);
	}

	downloadManager->append(m_S2_ls8Index, m_S2_scene_rawFile, DownloadType::ConfigFile);

	if (!downloadthread->isRunning())
	{
		downloadthread->start();
	}
}

void GCSatDownloader::afterAllDownloadsFinished()
{
	this->statusBar()->setStyleSheet("background-color: green");
	this->statusBar()->showMessage(tr("All downloads are finished."));
	
	//downloadthread->terminate();
	downloadthread->quit();
	downloadthread->wait();

	cout << "Download thread terminated" << endl;
}

void GCSatDownloader::afterDownloadFinished(QString str)
{
	if (QFileInfo().exists(m_LS8_scene_rawFile) && QFileInfo(str).suffix() == QString("gz"))
	{
		this->statusBar()->setStyleSheet("background-color: green");
		this->statusBar()->showMessage(tr("Extracting archive."));

		decompress_one_file(m_LS8_scene_rawFile.toStdString().c_str(), m_LS8_scene_extractFile.toStdString().c_str());

		this->statusBar()->showMessage(tr("Extraction done."));
	}
}

int GCSatDownloader::decompress_one_file(const char *infilename, const char *outfilename)
{
	gzFile infile = gzopen(infilename, "rb");
	FILE *outfile = fopen(outfilename, "wb");
	if (!infile || !outfile) return -1;

	char buffer[128];
	int num_read = 0;
	while ((num_read = gzread(infile, buffer, sizeof(buffer))) > 0) 
	{
		 fwrite(buffer, 1, num_read, outfile);
	}

	gzclose(infile);
	fclose(outfile);
}

void GCSatDownloader::afterStatusbarMessage(QString str)
{
	this->statusBar()->setStyleSheet("background-color: yellow");
	this->statusBar()->showMessage(str);
}

void GCSatDownloader::on_pushButton_ShowIndex_LS8_clicked()
{
	if (QFileInfo().exists(m_LS8_scene_extractFile))
	{
		QDesktopServices::openUrl(QUrl::fromLocalFile(m_scene_dir));
		return;
	}

	if (QFileInfo().exists(m_LS8_scene_rawFile))
	{
		QDesktopServices::openUrl(QUrl::fromLocalFile(m_LS8_scene_rawFile));
		return;
	}

	ui->lineEdit_Index_LS8->setText("NaN");
}

void GCSatDownloader::on_pushButton_DownloadImage_LS8_clicked()
{
	// get selected band 
	int bandIndex = ui->comboBox_Bands_LS8->currentIndex();
	if (bandIndex == 0)
	{
		for (int i = 1; i< 14; ++i)
		{
			QString dlink = getDownloadLink_LS8(i);
			QString flink = getImageFolderPath_LS8(i);
			if (QFileInfo().exists(flink))
			{
				continue;
			}
			downloadManager->append(dlink, flink, DownloadType::ImageFile);
		}
	}
	else
	{
		QString dlink = getDownloadLink_LS8(bandIndex);
		QString flink = getImageFolderPath_LS8(bandIndex);
		if (QFileInfo().exists(flink))
		{
			this->statusBar()->setStyleSheet("background-color: yellow");
			this->statusBar()->showMessage(flink + tr(" Image already exists."));
			return;
		}
		this->statusBar()->setStyleSheet("background-color: yellow");
		this->statusBar()->showMessage(dlink + tr(" Downloading file..."));
		downloadManager->append(dlink, flink, DownloadType::ImageFile);
	}

	if (!downloadthread->isRunning())
	{
		downloadthread->start();
	}
}

void GCSatDownloader::on_pushButton_DownloadImage_S2_clicked()
{
	// get selected band 
	int bandIndex = ui->comboBox_Bands_S2->currentIndex();
	if (bandIndex == 0)
	{
		for (int i = 1; i < 15; ++i)
		{
			QString dlink = getDownloadLink_S2(i);
			QString flink = getImageFolderPath_S2(i);
			if (QFileInfo().exists(flink))
			{
				continue;
			}
			downloadManager->append(dlink, flink, DownloadType::ImageFile);
		}
	}
	else
	{
		QString dlink = getDownloadLink_S2(bandIndex);
		QString flink = getImageFolderPath_S2(bandIndex);
		if (QFileInfo().exists(flink))
		{
			this->statusBar()->setStyleSheet("background-color: yellow");
			this->statusBar()->showMessage(flink + tr(" Image already exists."));
			return;
		}
		this->statusBar()->setStyleSheet("background-color: yellow");
		this->statusBar()->showMessage(dlink + tr(" Downloading file..."));
		downloadManager->append(dlink, flink, DownloadType::ImageFile);
	}

	if (!downloadthread->isRunning())
	{
		downloadthread->start();
	}
}

////////////////////////////////////////////////////////////////////////// ls8 url & dir
QString GCSatDownloader::getImageFolderPath_LS8(int _bandIndex)
{
	GCP_LANDSAT8_LABEL scn = m_LS8_Searcher->m_vlb[m_datas_Index_LS8];

	QString imagePath = m_images_dir + QString("\\");
	imagePath.append( scn.LS8_SPACECRAFT_ID);
	if (!QDir(imagePath).exists())
	{
		QDir().mkdir(imagePath);
	}
	imagePath.append(QString("\\")).append(QString(scn.LS8_WRS_PATH));
	if (!QDir(imagePath).exists())
	{
		QDir().mkdir(imagePath);
	}
	imagePath.append(QString("\\")).append(QString(scn.LS8_WRS_ROW));
	if (!QDir(imagePath).exists())
	{
		QDir().mkdir(imagePath);
	}
	imagePath.append(QString("\\")).append(scn.LS8_SCENE_ID);
	if (!QDir(imagePath).exists())
	{
		QDir().mkdir(imagePath);
	}

	imagePath = imagePath.append(QString("\\")).append(scn.LS8_PRODUCT_ID).append("_").append(getBandString_LS8(_bandIndex));
	if (_bandIndex == 13 || _bandIndex == 14)
		imagePath.append(".txt");
	else
		imagePath.append(".TIF");   // scene id + band name

	return imagePath;
}

QString GCSatDownloader::getDownloadLink_LS8(int _bandIndex)
{
	GCP_LANDSAT8_LABEL scn = m_LS8_Searcher->m_vlb[m_datas_Index_LS8];

	QString baselink = "https://storage.googleapis.com/gcp-public-data-landsat/";
	baselink.append("LC08").append(QString("/"));
	baselink.append(QString("01")).append(QString("/"));
	baselink.append(scn.LS8_WRS_PATH).append(QString("/"));   // path
	baselink.append(scn.LS8_WRS_ROW).append(QString("/"));   // row
	baselink.append(scn.LS8_PRODUCT_ID).append(QString("/"));   // scene id
	baselink.append(scn.LS8_PRODUCT_ID).append(QString("_")).append(getBandString_LS8(_bandIndex));
	if (_bandIndex == 13 || _bandIndex == 14)
		baselink.append(".txt");
	else
		baselink.append(".TIF");   // scene id + band name
	
	return baselink;
}

QString GCSatDownloader::getBandString_LS8(int _i)
{
	switch (_i)
	{
	case 1:
		return QString("B1");
	case 2:
		return QString("B2");
	case 3:
		return QString("B3");
	case 4:
		return QString("B4");
	case 5:
		return QString("B5");
	case 6:
		return QString("B6");
	case 7:
		return QString("B7");
	case 8:
		return QString("B8");
	case 9:
		return QString("B9");
	case 10:
		return QString("B10");
	case 11:
		return QString("B11");
	case 12:
		return QString("BQA");
	case 13:
		return QString("ANG");
	case 14:
		return QString("MTL");
	default:
		break;
	}
}

////////////////////////////////////////////////////////////////////////// s2 url & dir
QString GCSatDownloader::getImageFolderPath_S2(int _bandIndex)
{
	GCP_SENTINEL2_LABEL scn = m_S2_Searcher->m_vlb[m_datas_Index_S2];

	QString imagePath = m_images_dir + QString("\\");
	imagePath.append("SENTINEL_2");
	if (!QDir(imagePath).exists())
	{
		QDir().mkdir(imagePath);
	}
	imagePath.append(QString("\\")).append(scn.S2_MGRS_TILE);
	if (!QDir(imagePath).exists())
	{
		QDir().mkdir(imagePath);
	}
	imagePath.append(QString("\\")).append(scn.S2_PRODUCT_ID);
	if (!QDir(imagePath).exists())
	{
		QDir().mkdir(imagePath);
	}

	imagePath = imagePath.append(QString("\\")).append(scn.S2_PRODUCT_ID).append("_").append(getBandString_S2(_bandIndex));
	imagePath.append(".jp2");   // scene id + band name

	return imagePath;
}

QString GCSatDownloader::getDownloadLink_S2(int _bandIndex)
{
	GCP_SENTINEL2_LABEL scn = m_S2_Searcher->m_vlb[m_datas_Index_S2];

	QString nameOfFile;
	QStringList list = scn.S2_PRODUCT_ID.split(QString("_"));
	if (list[1] == QString("MSIL1C"))
		nameOfFile = list[5] + QString("_") + list[2];
	if (list[1] == QString("OPER"))
		nameOfFile = scn.S2_GRANULE_ID.mid(0, scn.S2_GRANULE_ID.length() - 7);
	QString baselink = scn.S2_BASE_URL;
	baselink.replace(QString("gs://"), QString("https://storage.googleapis.com/"));
	baselink.append("/GRANULE").append(QString("/"));
	baselink.append(scn.S2_GRANULE_ID).append(QString("/"));   // scene id
	baselink.append("IMG_DATA").append(QString("/"));   // scene id
	baselink.append(nameOfFile).append(QString("_")).append(getBandString_S2(_bandIndex));
	baselink.append(".jp2");   // scene id + band name

	return baselink;
}

QString GCSatDownloader::getBandString_S2(int _i)
{
	switch (_i)
	{
	case 1:
		return QString("B01");
	case 2:
		return QString("B02");
	case 3:
		return QString("B03");
	case 4:
		return QString("B04");
	case 5:
		return QString("B05");
	case 6:
		return QString("B06");
	case 7:
		return QString("B07");
	case 8:
		return QString("B08");
	case 9:
		return QString("B09");
	case 10:
		return QString("B10");
	case 11:
		return QString("B11");
	case 12:
		return QString("B12");
	case 13:
		return QString("B8A");
	case 14:
		return QString("TCI");
	default:
		break;
	}
}

string GCSatDownloader::getWorkingDIR(void)
{
	HMODULE hModule = GetModuleHandleW(NULL);
	WCHAR path[MAX_PATH];
	GetModuleFileNameW(hModule, path, MAX_PATH);
	char ch[MAX_PATH];
	char DefChar = ' ';
	WideCharToMultiByte(CP_ACP, 0, path, -1, ch, 260, &DefChar, NULL);
	std::string ss(ch);
	string directory;
	const size_t last_slash_idx = ss.rfind('\\');
	if (std::string::npos != last_slash_idx)
	{
		directory = ss.substr(0, last_slash_idx);
	}
	return directory;
}