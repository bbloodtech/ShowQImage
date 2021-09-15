/********************************************************************************
** Form generated from reading UI file 'cammerwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMMERWIDGET_H
#define UI_CAMMERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CammerWidget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_Pixmap;

    void setupUi(QWidget *CammerWidget)
    {
        if (CammerWidget->objectName().isEmpty())
            CammerWidget->setObjectName(QString::fromUtf8("CammerWidget"));
        CammerWidget->resize(400, 300);
        verticalLayout = new QVBoxLayout(CammerWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_Pixmap = new QLabel(CammerWidget);
        label_Pixmap->setObjectName(QString::fromUtf8("label_Pixmap"));
        label_Pixmap->setScaledContents(false);

        verticalLayout->addWidget(label_Pixmap);


        retranslateUi(CammerWidget);

        QMetaObject::connectSlotsByName(CammerWidget);
    } // setupUi

    void retranslateUi(QWidget *CammerWidget)
    {
        CammerWidget->setWindowTitle(QCoreApplication::translate("CammerWidget", "CammerWidget", nullptr));
        label_Pixmap->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CammerWidget: public Ui_CammerWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMMERWIDGET_H
