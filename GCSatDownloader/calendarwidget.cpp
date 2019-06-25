/*!
 * \class CalendarWidget
 *
 *
 * \brief 
 *  
    Basit CalendarWidget uygulamasi. Qcalendarwidget uzerinden julian day alarak mainwidget (LandsatImageDownloader)'a signal emit eder.
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
#include "calendarwidget.h"

CalendarWidget::CalendarWidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CalendarWidget)
{
    ui->setupUi(this);
	connect(ui->calendarWidget, SIGNAL(clicked(const QDate&)), this, SLOT(setDate(const QDate&)));
}

CalendarWidget::~CalendarWidget()
{
    delete ui;
}

void CalendarWidget::on_okPushButton_clicked()
{
	if (comingFrom == First)
        emit goingToFirst(m_date);
	else
        emit goingToSecond(m_date);
	
	this->close();
	return;
}

void CalendarWidget::on_cancelPushButton_clicked()
{
    this->close();
}

void CalendarWidget::setDate(const QDate& date)
{
	m_date = date;
}
