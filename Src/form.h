#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include "GenICam/System.h"
#include <QTimer>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();

private:
	void initUi();

private slots:
	void on_pushButton_Start_clicked();
    void on_pushButton_Stop_clicked();
	void on_pushButton_Open_clicked();
	void on_pushButton_Close_clicked();
	void on_comboBox_currentIndexChanged(int nIndex);
	void closeEvent(QCloseEvent * event);
	void onTimerStreamStatistic();//定时刷新状态栏信息


private:
    Ui::Form *ui;

	Dahua::Infra::TVector<Dahua::GenICam::ICameraPtr> m_vCameraPtrList;	// 发现的相机列表
	QTimer m_staticTimer;	//定时器，定时刷新状态栏信息
};

#endif // FORM_H
