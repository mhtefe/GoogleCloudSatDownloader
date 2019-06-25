#include "SearcherBase.h"

SearcherBase::SearcherBase()
{
	m_go = true;

	setCloudCover(Nan);
	setLat(Nan);
	setLon(Nan);
}

SearcherBase::SearcherBase(QString _indexFile): m_indexFile(_indexFile)
{
	m_go = true;

	setCloudCover(Nan);
	setLat(Nan);
	setLon(Nan);
}

void SearcherBase::setSearchParameters(double _clo,  QDate _fdt, QDate _ldt, double _lat, double _lon) 
{
	setCloudCover(_clo);
	//std::function<bool(double)> fcnPtr_clo = std::bind(&Searcher::cloudCriteria, this, std::placeholders::_1);
	
	setFirstDate(_fdt);
	setLastDate(_ldt);
	//std::function<bool(QDate)> fcnPtr_date = std::bind(&Searcher::dateCriteria, this, std::placeholders::_1);

	setLat(_lat);
	//std::function<bool(double, double)> fcnPtr_lat = std::bind(&Searcher::latitudeCriteria, this, std::placeholders::_1, std::placeholders::_2);

	setLon(_lon);
	//std::function<bool(double, double)> fcnPtr_lon = std::bind(&Searcher::longitudeCriteria, this, std::placeholders::_1, std::placeholders::_2);
}

bool SearcherBase::dateCriteria( QDate _f)
{
	bool retVal = true;

	if (_f < m_firstDate || _f> m_lastDate)
		retVal = false;

	return retVal;
}

bool SearcherBase::cloudCriteria(double _clo)
{
	bool retVal = true;

	if (!m_validCloud)
		retVal = false;

	if (_clo > m_cloudCover)
		retVal = false;

	return retVal;
}

bool SearcherBase::latitudeCriteria(double _lat_min, double _lat_max)
{
	bool retVal = true;
	if (!m_validLat)
		retVal = false;

	if (m_lat < _lat_min || m_lat> _lat_max)
		retVal = false;
	else
		return true;

	return retVal;
}

bool SearcherBase::longitudeCriteria(double _lon_min, double _lon_max)
{
	bool retVal = true;
	if (!m_validLon)
		retVal = false;

	if (m_lon < _lon_min || m_lon> _lon_max)
		retVal = false;

	return retVal;
}

bool SearcherBase::allCriterias(QDate _f, double _clo, double _lat_min, double _lat_max, double _lon_min, double _lon_max)
{
	bool retVal = false;

	if (!dateCriteria(_f))
		return retVal;

	if (!(_clo == _clo) || !cloudCriteria(_clo))
		return retVal;

	if (/*!(_lat_min == _lat_min) || !(_lat_max == _lat_max) ||*/ !latitudeCriteria(_lat_min, _lat_max))
		return retVal;

	if (/*!(_lon_min == _lon_min) || !(_lon_max == _lon_max) ||*/ !longitudeCriteria(_lon_min, _lon_max))
		return retVal;

	return true;
		
}

QString SearcherBase::zeroFrontPathRow(string _str)
{
	int numDigits = _str.length();
	if (numDigits == 3)
		return QString::fromStdString(_str);

	if (numDigits == 2)
		return QString("0").append(QString::fromStdString(_str));
	
	return QString("00").append(QString::fromStdString(_str));
}

