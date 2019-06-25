/*!
 * \class Settings
 *
 *
 * \brief : Genel parametreleri tutan, parse eden class
 *
 * \note 
 *
 * \author mehmet.efendioglu
 *
 * \version 1.0
 *
 * \date Haziran 2015
 *
 * Contact: mehmet.efendioglu@tubitak.gov.tr
 * TUBITAK UZAY
 */

#ifndef SETTINGS_H_
#define SETTINGS_H_

#include <string>
#include <QtCore/QMap>
#include <QtCore/QVariant>
#include <QtCore/QByteArray>

typedef QMap<QString, QVariant> ParametersMap; // Key, value
typedef QMap<QString, QString> ParametersType; // Key, type

typedef unsigned int uint;

// MACRO BEGIN

#define PARAMETER_GETTER_bool(PREFIX, NAME) \
	static bool get##PREFIX##_##NAME() {return parameters_.value(#PREFIX "/" #NAME).toBool();}
#define PARAMETER_GETTER_int(PREFIX, NAME) \
	static int get##PREFIX##_##NAME() {return parameters_.value(#PREFIX "/" #NAME).toInt();}
#define PARAMETER_GETTER_uint(PREFIX, NAME) \
	static uint get##PREFIX##_##NAME() {return parameters_.value(#PREFIX "/" #NAME).toUInt();}
#define PARAMETER_GETTER_float(PREFIX, NAME) \
	static float get##PREFIX##_##NAME() {return parameters_.value(#PREFIX "/" #NAME).toFloat();}
#define PARAMETER_GETTER_double(PREFIX, NAME) \
	static double get##PREFIX##_##NAME() {return parameters_.value(#PREFIX "/" #NAME).toDouble();}
#define PARAMETER_GETTER_QString(PREFIX, NAME) \
	static QString get##PREFIX##_##NAME() {return parameters_.value(#PREFIX "/" #NAME).toString();}

#define PARAMETER(PREFIX, NAME, TYPE, DEFAULT_VALUE) \
	public: \
		static QString k##PREFIX##_##NAME() {return QString(#PREFIX "/" #NAME);} \
		static TYPE default##PREFIX##_##NAME() {return DEFAULT_VALUE;} \
		static QString type##PREFIX##_##NAME() {return QString(#TYPE);} \
		PARAMETER_GETTER_##TYPE(PREFIX, NAME) \
		static void set##PREFIX##_##NAME(const TYPE & value) {parameters_[#PREFIX "/" #NAME] = value;} \
	private: \
		class Dummy##PREFIX##_##NAME { \
		public: \
			Dummy##PREFIX##_##NAME() { \
				defaultParameters_.insert(#PREFIX "/" #NAME, QVariant(DEFAULT_VALUE)); \
				parameters_.insert(#PREFIX "/" #NAME, DEFAULT_VALUE); \
				parametersType_.insert(#PREFIX "/" #NAME, #TYPE);} \
		}; \
		Dummy##PREFIX##_##NAME dummy##PREFIX##_##NAME;
// MACRO END


class Settings
{
	//List format : [Index:item0;item1;item3;...]

	//PARAMETER(General, cardType, QString, "0:Turkcell;Avea");
	//PARAMETER(General, Y2, int, 400);
	//PARAMETER(General, autoUpdateObjects, bool, true);
	PARAMETER(General, nextObjID, uint, 1);
	PARAMETER(General, SceneFolderName, QString, "SceneList");
	PARAMETER(General, SceneFileName, QString, "scene_list");
	PARAMETER(General, ImagesFolderName, QString, "Images");
	PARAMETER(General, ImagesNetworkFolderName, QString, "//kappa/geoportal");
	PARAMETER(General, CloudLink, QString, "http://landsat-pds.s3.amazonaws.com/scene_list.gz");
	PARAMETER(General, TempFolderName, QString, "TempFiles");

	//PARAMETER(General, controlsShown, bool, false);

public:
	virtual ~Settings(){}

	static QString workingDirectory();
	static QString iniDefaultPath();
	static QString iniDefaultFileName() {return "config.ini";}

	static void loadSettings(const QString & fileName = QString(), QByteArray * windowGeometry = 0, QByteArray * windowState = 0);
	static void saveSettings(const QString & fileName = QString(), const QByteArray & windowGeometry = QByteArray(), const QByteArray & windowState = QByteArray());

	static const ParametersMap & getDefaultParameters() {return defaultParameters_;}
	static const ParametersMap & getParameters() {return parameters_;}
	static const ParametersType & getParametersType() {return parametersType_;}
	static void setParameter(const QString & key, const QVariant & value) {if(parameters_.contains(key))parameters_[key] = value;}
	static void resetParameter(const QString & key) {if(defaultParameters_.contains(key)) parameters_.insert(key, defaultParameters_.value(key));}
	static QVariant getParameter(const QString & key) {return parameters_.value(key, QVariant());}

private:
	Settings(){}

private:
	static ParametersMap defaultParameters_;
	static ParametersMap parameters_;
	static ParametersType parametersType_;
	static Settings dummyInit_;
};


#endif /* SETTINGS_H_ */
