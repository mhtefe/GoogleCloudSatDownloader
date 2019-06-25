#ifndef SEARCHER_H
#define SEARCHER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <atomic>
#include <thread>

#include <QMainWindow>
#include <QThread>
#include <QString>
#include <QDir>
#include <QDate>

#include "csv.h"

using namespace std;

enum DataSource
{
	GCP_LANDSAT8,
	GCP_SENTINEL2
};

const double Nan = std::numeric_limits<double>::quiet_NaN();

typedef struct GCP_LANDSAT8_LABEL
{
	QString LS8_SCENE_ID;
	QString LS8_PRODUCT_ID;
	QString LS8_SPACECRAFT_ID;
	QString LS8_SENSOR_ID;
	QDate LS8_DATE_ACQUIRED;
	QString LS8_COLLECTION_NUMBER;
	QString LS8_COLLECTION_CATEGORY;
	QTime LS8_SENSING_TIME;
	QString LS8_DATA_TYPE;
	QString LS8_WRS_PATH;
	QString LS8_WRS_ROW;
	double LS8_CLOUD_COVER;
	double LS8_NORTH_LAT;
	double LS8_SOUTH_LAT;
	double LS8_WEST_LON;
	double LS8_EAST_LON;
	double LS8_TOTAL_SIZE;
	QString LS8_BASE_URL;
};

typedef struct GCP_SENTINEL2_LABEL
{
	QString S2_GRANULE_ID;
	QString S2_PRODUCT_ID;
	QString S2_DATATAKE_IDENTIFIER;
	QString S2_MGRS_TILE;
	QDate S2_SENSING_TIME;
	QString S2_TOTAL_SIZE;
	double S2_CLOUD_COVER;
	QTime S2_GEOMETRIC_QUALITY_FLAG;
	QString S2_GENERATION_TIME;
	double S2_NORTH_LAT;
	double S2_SOUTH_LAT;
	double S2_WEST_LON;
	double S2_EAST_LON;
	QString S2_BASE_URL;
};

class SearcherBase : public QObject
{
	Q_OBJECT
	
public:
	SearcherBase();
	SearcherBase(QString _indexFile);

	QDate getFirstDate() const { return m_firstDate; }
	void setFirstDate(QDate val) { m_firstDate = val; }

	QDate getLastDate() const { return m_lastDate; }
	void setLastDate(QDate val) { m_lastDate = val; }

	double getCloudCover() const { return m_cloudCover; }
	void setCloudCover(double val) 
	{
		m_cloudCover = val; 
		(val == val) ? m_validCloud = true : m_validCloud = false;
	}

	void setSearchParameters(double _clo, QDate _fdt, QDate _ldt, double _lat, double _lon);

	double getLat() const { return m_lat; }
	void setLat(double val) 
	{ 
		m_lat = val; 
		(val == val) ? m_validLat = true : m_validLat = false;
	}

	double getLon() const { return m_lon; }
	void setLon(double val) 
	{
		m_lon = val;
		(val == val) ? m_validLon = true : m_validLon = false;
	}

	QString m_indexFile;

protected:
	std::atomic<bool> m_go; // thread loop run control
	QString zeroFrontPathRow(string _str);
	bool dateCriteria(QDate _f);
	bool cloudCriteria(double _clo);
	bool latitudeCriteria(double _latMin, double _latMax);
	bool longitudeCriteria(double _lonMin, double _lonMax);
	bool allCriterias(QDate _f, double _clo, double _lat_min, double _lat_max, double _lon_min, double _lon_max);

private:
	QDate m_firstDate;
	QDate m_lastDate;
	double m_cloudCover;
	double m_lat;
	double m_lon;
	bool m_validCloud;
	bool m_validLat;
	bool m_validLon;
};

#endif 