#ifndef LANDSATIMAGEDOWNLOADER_H
#define LANDSATIMAGEDOWNLOADER_H

#include <Windows.h>
#include <iostream>
#include <comdef.h>
#include <Wbemidl.h>
#include <stdio.h>  /* defines FILENAME_MAX */
#include <sstream>
#include <string>
#include <fstream>

#include <QMainWindow>
#include <QKeyEvent>
#include <QDesktopServices>
#include <QProgressBar>
#include <QTableWidgetItem>
#include <qfiledialog.h>
#include <qdrag.h>

#include "Settings.h"
#include "SearcherLS8.h"
#include "SearcherS2.h"

#include "DownloadManager.h"
#include "calendarwidget.h"

#include "zlib.h"

namespace Ui {
class GcSatDownloader;
}

class CustomProgressBarTableWidgetItem : public QProgressBar, public QTableWidgetItem
{
	Q_OBJECT
public:
	CustomProgressBarTableWidgetItem(QWidget* parent) : QProgressBar(parent)
	{
	}

	CustomProgressBarTableWidgetItem(const QString txt = QString("0"))
		:QTableWidgetItem(txt)
	{
	}

	bool operator <(const QTableWidgetItem& other) const
	{
		if (other.column() == 0 /* numeric cell */) {
			return QTableWidgetItem::text().toInt() < other.text().toInt();
		}
		else if (other.column() == 4 /* progress bar */) {
			const QProgressBar *p = dynamic_cast<const QProgressBar *>(&other);
			if (p != 0) {
				if (this->value() < p->value())
					return true;
			}
		}

		return false;
	}
};

class GCSatDownloader : public QMainWindow
{
    Q_OBJECT

public:
    explicit GCSatDownloader(QWidget *parent = 0);
    ~GCSatDownloader();
protected:
	void dragEnterEvent(QDragEnterEvent *event) override;
	void dropEvent(QDropEvent *event) override;
private:
    Ui::GcSatDownloader *ui;

	QThread *searchThread_LS8;
	QThread *searchThread_S2;

	QThread *downloadthread;
	SearcherLS8 * m_LS8_Searcher;
	SearcherS2  * m_S2_Searcher;
	DownloadManager * downloadManager;

	void listSearchResults_LS8();
	void listSearchResults_S2();

	void updateInfoTags_LS8(int row);
	void updateInfoTags_S2(int row);

	void displayFolder();

	string getWorkingDIR(void);
	QString m_workingDirectory;

	QString m_images_dir;
	QString m_scene_dir;

	QString m_LS8_scene_rawFile;
	QString m_LS8_scene_extractFile;
	QString m_LS8_ls8Index;

	QString m_S2_scene_rawFile;
	QString m_S2_scene_extractFile;
	QString m_S2_ls8Index;

	int m_jobId;
	int m_datas_Index_LS8;
	int m_datas_Index_S2;
	int searchId;
	int decompress_one_file(const char *infilename, const char *outfilename);

	QString getDownloadLink_LS8(int _bandIndex);
	QString getDownloadLink_S2(int _bandIndex);
	QString getImageFolderPath_LS8(int _bandIndex);
	QString getImageFolderPath_S2(int _bandIndex);
	QString getBandString_LS8(int i);
	QString getBandString_S2(int i);

	void setupUiComponents();
	void setupUiPaths();
	void setupUiSearcherDownloader();
	void setupUiBandCombo();

public slots:
	void afterDownloadFinished(QString str);
	void afterAllDownloadsFinished();

private slots:
	void on_pushButton_search_LS8_clicked();
	void on_pushButton_search_S2_clicked();

	void on_pushButton_stop_LS8_clicked();
	void on_pushButton_stop_S2_clicked();

	void on_pushButton_DownloadIndex_LS8_clicked();
	void on_pushButton_DownloadIndex_S2_clicked();
	
	void on_pushButton_ShowIndex_LS8_clicked();
	void on_pushButton_ShowIndex_S2_clicked();
	void displayFolder(int _ind);
	
	void on_pushButton_DownloadImage_LS8_clicked();
	void on_pushButton_DownloadImage_S2_clicked();

	void afterSearchFinished();
	void afterStatusbarMessage(QString str);
	void updateCurrentStatus(int i, int j);
	
	void showFileOfItem_LS8(int row, int column);
	void showFileOfItem_S2(int row, int column);
};

#endif // LANDSATIMAGEDOWNLOADER_H
