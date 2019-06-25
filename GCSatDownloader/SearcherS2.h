#pragma once

#include "SearcherBase.h"

class SearcherS2 : public SearcherBase
{
	Q_OBJECT
public:
	SearcherS2();
	SearcherS2(QString _indexFile);

	void DoSetup(QThread &cthread);
	void DoTerminate(void);

	std::vector<GCP_SENTINEL2_LABEL> m_vlb;

signals:
	void searchStarted();
	void searchFinished();
	void currentStatus(int i, int j);
	void foundElementsSize(int i);

public slots:
	void DoWork(void);
};