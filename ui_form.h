/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <Src/cammerwidget.h>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_Open;
    QPushButton *pushButton_Close;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Start;
    QPushButton *pushButton_Stop;
    CammerWidget *widget;
    QLabel *label_Statistic;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(608, 600);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Form->sizePolicy().hasHeightForWidth());
        Form->setSizePolicy(sizePolicy);
        Form->setMinimumSize(QSize(600, 600));
        Form->setMaximumSize(QSize(608, 600));
        verticalLayout_2 = new QVBoxLayout(Form);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(9, 9, 9, 9);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        comboBox = new QComboBox(Form);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setMinimumSize(QSize(250, 23));
        comboBox->setMaximumSize(QSize(16777215, 23));

        horizontalLayout->addWidget(comboBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton_Open = new QPushButton(Form);
        pushButton_Open->setObjectName(QString::fromUtf8("pushButton_Open"));
        pushButton_Open->setMinimumSize(QSize(75, 23));
        pushButton_Open->setMaximumSize(QSize(75, 23));

        horizontalLayout->addWidget(pushButton_Open);

        pushButton_Close = new QPushButton(Form);
        pushButton_Close->setObjectName(QString::fromUtf8("pushButton_Close"));
        pushButton_Close->setMinimumSize(QSize(75, 23));
        pushButton_Close->setMaximumSize(QSize(75, 23));

        horizontalLayout->addWidget(pushButton_Close);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_Start = new QPushButton(Form);
        pushButton_Start->setObjectName(QString::fromUtf8("pushButton_Start"));
        pushButton_Start->setMinimumSize(QSize(75, 23));
        pushButton_Start->setMaximumSize(QSize(75, 23));

        horizontalLayout->addWidget(pushButton_Start);

        pushButton_Stop = new QPushButton(Form);
        pushButton_Stop->setObjectName(QString::fromUtf8("pushButton_Stop"));
        pushButton_Stop->setMinimumSize(QSize(75, 23));
        pushButton_Stop->setMaximumSize(QSize(75, 23));

        horizontalLayout->addWidget(pushButton_Stop);


        verticalLayout->addLayout(horizontalLayout);

        widget = new CammerWidget(Form);
        widget->setObjectName(QString::fromUtf8("widget"));

        verticalLayout->addWidget(widget);

        label_Statistic = new QLabel(Form);
        label_Statistic->setObjectName(QString::fromUtf8("label_Statistic"));

        verticalLayout->addWidget(label_Statistic);

        verticalLayout->setStretch(1, 1);

        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        pushButton_Open->setText(QCoreApplication::translate("Form", "OpenDevice", nullptr));
        pushButton_Close->setText(QCoreApplication::translate("Form", "CloseDevice", nullptr));
        pushButton_Start->setText(QCoreApplication::translate("Form", "StartGrab", nullptr));
        pushButton_Stop->setText(QCoreApplication::translate("Form", "StopGrab", nullptr));
        label_Statistic->setText(QCoreApplication::translate("Form", "Statistics", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
