#ifndef DOWNLOADMANAGER3_H
#define DOWNLOADMANAGER3_H

#include <QFile>
#include <QObject>
#include <QQueue>
#include <QTime>
#include <QUrl>
#include <QThread>
#include <QNetworkAccessManager>

#include "textprogressbar.h"

typedef enum DownloadType
{
	ConfigFile,
	ImageFile
};

typedef struct DownloadQueueType
{
	QUrl m_url;
	QString m_file;
	DownloadType m_type;
};

class DownloadManager : public QObject
{
	Q_OBJECT
public:
	DownloadManager();
	void append(QString dlink, QString _fPath, DownloadType _type);
	QString saveFileName(const QUrl &url);
	void DoSetup(QThread &cthread);

signals:
	void finished();
	void finishedSaveFile(QString);

public slots:
	void startNextDownload(void);

private slots:
	void downloadProgress(qint64 bytesReceived, qint64 bytesTotal);
	void downloadFinished();
	void downloadReadyRead();

private:
	QNetworkAccessManager manager;
	QQueue<DownloadQueueType> downloadQueue;
	QNetworkReply *currentDownload;
	QFile output;
	QTime downloadTime;
	TextProgressBar progressBar;

	int downloadedCount;
	int totalCount;
};

#endif
