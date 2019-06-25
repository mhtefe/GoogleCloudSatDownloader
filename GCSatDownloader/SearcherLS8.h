#pragma once

#include "SearcherBase.h"

class SearcherLS8 : public SearcherBase
{
	Q_OBJECT
public:
	SearcherLS8();
	SearcherLS8(QString _indexFile);

	void DoSetup(QThread &cthread);
	void DoTerminate(void);

	std::vector<GCP_LANDSAT8_LABEL> m_vlb;

signals:
	void searchStarted();
	void searchFinished();
	void currentStatus(int i, int j);
	void foundElementsSize(int i);

public slots:
	void DoWork(void);
};