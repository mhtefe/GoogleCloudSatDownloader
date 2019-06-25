#include "DownloadManager.h"

#include <QFileInfo>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QString>
#include <QStringList>
#include <QTimer>
#include <stdio.h>

DownloadManager::DownloadManager( ) :  downloadedCount(0), totalCount(0)
{
}

void DownloadManager::append(QString _dLink, QString _fPath, DownloadType _type)
{
	QUrl url = QUrl::fromEncoded(_dLink.toLocal8Bit());
	DownloadQueueType qtp;
	qtp.m_url = url;
	qtp.m_type = _type;
	qtp.m_file = _fPath;

	downloadQueue.enqueue(qtp);

	++totalCount;
}

QString DownloadManager::saveFileName(const QUrl &url)
{
	QString path = url.path();
	QString basename = QFileInfo(path).fileName();

	if (basename.isEmpty())
		basename = "download";

	if (QFile::exists(basename)) {
		// already exists, don't overwrite
		int i = 0;
		basename += '.';
		while (QFile::exists(basename + QString::number(i)))
			++i;

		basename += QString::number(i);
	}

	return basename;
}

void DownloadManager::startNextDownload(void)
{
	if (downloadQueue.isEmpty()) 
	{
		printf("%d/%d files downloaded successfully\n", downloadedCount, totalCount);
		emit finished();
		return;
	}

	DownloadQueueType urlPlusType = downloadQueue.dequeue();

	output.setFileName(urlPlusType.m_file);

	if (!output.open(QIODevice::WriteOnly)) 
	{
		fprintf(stderr, "Problem opening save file '%s' for download '%s': %s\n",
			qPrintable(urlPlusType.m_file), urlPlusType.m_url.toEncoded().constData(),
			qPrintable(output.errorString()));

		startNextDownload();
		return;                 // skip this download
	}

	QNetworkRequest request(urlPlusType.m_url);
	currentDownload = manager.get(request);
	connect(currentDownload, SIGNAL(downloadProgress(qint64, qint64)),
		SLOT(downloadProgress(qint64, qint64)));
	connect(currentDownload, SIGNAL(finished()),
		SLOT(downloadFinished()));
	connect(currentDownload, SIGNAL(readyRead()),
		SLOT(downloadReadyRead()));

	// prepare the output
	printf("Downloading %s...\n", urlPlusType.m_url.toEncoded().constData());
	downloadTime.start();
}

void DownloadManager::downloadProgress(qint64 bytesReceived, qint64 bytesTotal)
{
	progressBar.setStatus(bytesReceived, bytesTotal);

	// calculate the download speed
	double speed = bytesReceived * 1000.0 / downloadTime.elapsed();
	QString unit;
	if (speed < 1024) {
		unit = "bytes/sec";
	}
	else if (speed < 1024 * 1024) {
		speed /= 1024;
		unit = "kB/s";
	}
	else {
		speed /= 1024 * 1024;
		unit = "MB/s";
	}

	progressBar.setMessage(QString::fromLatin1("%1 %2")
		.arg(speed, 3, 'f', 1).arg(unit));
	progressBar.update();
}

void DownloadManager::downloadFinished()
{
	progressBar.clear();
	output.close();

	if (currentDownload->error()) {
		// download failed
		fprintf(stderr, "Failed: %s\n", qPrintable(currentDownload->errorString()));
	}
	else {
		printf("Succeeded.\n");
		++downloadedCount;
	}

	emit finishedSaveFile(output.fileName());

	currentDownload->deleteLater();
	startNextDownload();
}

void DownloadManager::DoSetup(QThread &cthread)
{
	connect(&cthread, SIGNAL(started()), this, SLOT(startNextDownload()) );
}

void DownloadManager::downloadReadyRead()
{
	output.write(currentDownload->readAll());
}
