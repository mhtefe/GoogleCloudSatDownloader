#ifndef CALENDARWIDGET_H
#define CALENDARWIDGET_H

#include <QDialog>
#include "ui_calendarwidget.h"

namespace Ui {
class CalendarWidget;
}

enum Listing
{
	First,
	Second
};

class CalendarWidget : public QDialog
{
    Q_OBJECT

public:
    explicit CalendarWidget(QWidget *parent = 0);
    ~CalendarWidget();
	void SetComingFrom(Listing lst){ comingFrom = lst; };

private slots:
    void on_okPushButton_clicked();
    void on_cancelPushButton_clicked();
	void setDate(const QDate&);

signals:
    void goingToFirst(QDate&);     // which button to go
    void goingToSecond( QDate&);

private:
    Ui::CalendarWidget *ui;
	Listing comingFrom;     // which botton has triggered
	QDate m_date;
};

#endif // CALENDARWIDGET_H
