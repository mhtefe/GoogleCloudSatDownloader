/********************************************************************************
** Form generated from reading UI file 'calendarwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALENDARWIDGET_H
#define UI_CALENDARWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CalendarWidget
{
public:
    QCalendarWidget *calendarWidget;
    QPushButton *okPushButton;
    QPushButton *cancelPushButton;

    void setupUi(QDialog *CalendarWidget)
    {
        if (CalendarWidget->objectName().isEmpty())
            CalendarWidget->setObjectName(QStringLiteral("CalendarWidget"));
        CalendarWidget->resize(288, 240);
        calendarWidget = new QCalendarWidget(CalendarWidget);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));
        calendarWidget->setGeometry(QRect(10, 10, 264, 183));
        okPushButton = new QPushButton(CalendarWidget);
        okPushButton->setObjectName(QStringLiteral("okPushButton"));
        okPushButton->setGeometry(QRect(120, 200, 71, 31));
        cancelPushButton = new QPushButton(CalendarWidget);
        cancelPushButton->setObjectName(QStringLiteral("cancelPushButton"));
        cancelPushButton->setGeometry(QRect(200, 200, 71, 31));

        retranslateUi(CalendarWidget);

        QMetaObject::connectSlotsByName(CalendarWidget);
    } // setupUi

    void retranslateUi(QDialog *CalendarWidget)
    {
        CalendarWidget->setWindowTitle(QApplication::translate("CalendarWidget", "Takvim", Q_NULLPTR));
        okPushButton->setText(QApplication::translate("CalendarWidget", "Tamam", Q_NULLPTR));
        cancelPushButton->setText(QApplication::translate("CalendarWidget", "Vazge\303\247", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CalendarWidget: public Ui_CalendarWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALENDARWIDGET_H
