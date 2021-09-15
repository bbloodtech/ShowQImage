#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent)
    ,ui(new Ui::Form)
{
    ui->setupUi(this);

    connect(&m_staticTimer, &QTimer::timeout, this, &Form::onTimerStreamStatistic);//每1000ms刷新一次状态栏

    initUi();//调用初始化函数
}

Form::~Form()
{
	delete ui;
}
//初始化函数
void Form::initUi()
{
    //label_Statistic为一个label
    ui->label_Statistic->setText("");//连接相机之前不显示状态栏


	CSystem &systemObj = CSystem::getInstance();
    //发现相机失败返回false
	if (false == systemObj.discovery(m_vCameraPtrList))
	{
		printf("discovery fail.\n");
		return;
	}
    //返回的相机列表数小于1
	if (m_vCameraPtrList.size() < 1)
	{
		ui->comboBox->setEnabled(false);
		ui->pushButton_Open->setEnabled(false);
	}

	else
	{
		ui->comboBox->setEnabled(true);
		ui->pushButton_Open->setEnabled(true);

		for (int i = 0; i < m_vCameraPtrList.size(); i++)
		{
            ui->comboBox->addItem(m_vCameraPtrList[i]->getKey());//添加下拉条目
		}

		ui->widget->SetCemera(m_vCameraPtrList[0]->getKey());
	}
    //初始化时将后三个按钮禁用
	ui->pushButton_Close->setEnabled(false);
	ui->pushButton_Start->setEnabled(false);
	ui->pushButton_Stop->setEnabled(false);
}

// 设置要连接的相机
void Form::on_comboBox_currentIndexChanged(int nIndex)//下拉列表改变
{
	ui->widget->SetCemera(m_vCameraPtrList[nIndex]->getKey());
}

// 连接
void Form::on_pushButton_Open_clicked()
{

	if (!ui->widget->CameraOpen())
	{
		return;
	}
    //相机打开失败则return
    ui->pushButton_Open->setEnabled(false);//禁用打开相机按钮
	ui->pushButton_Close->setEnabled(true);
	ui->pushButton_Start->setEnabled(true);
	ui->pushButton_Stop->setEnabled(false);
    ui->comboBox->setEnabled(false);//禁用下拉菜单

	/*连接相机之后显示统计信息，所有值为0*/
	ui->widget->resetStatistic();
	QString strStatic = ui->widget->getStatistic();
    ui->label_Statistic->setText(strStatic);
}

// 断开
void Form::on_pushButton_Close_clicked()
{
	on_pushButton_Stop_clicked();
	ui->widget->CameraClose();

    ui->label_Statistic->setText("");//断开相机以后不显示状态栏

	ui->pushButton_Open->setEnabled(true);
	ui->pushButton_Close->setEnabled(false);
	ui->pushButton_Start->setEnabled(false);
	ui->pushButton_Stop->setEnabled(false);
	ui->comboBox->setEnabled(true);
}

// 开始
void Form::on_pushButton_Start_clicked()
{
	// 设置连续拉流
	//ui->widget->CameraChangeTrig(CammerWidget::trigContinous);

	ui->widget->CameraStart();

    ui->pushButton_Start->setEnabled(false);//禁用开始
    ui->pushButton_Stop->setEnabled(true);//启用停止

    ui->widget->resetStatistic();//显示状态栏信息
	m_staticTimer.start(100);
}

// 停止
void Form::on_pushButton_Stop_clicked()
{
    m_staticTimer.stop();//定时器停止

    ui->widget->CameraStop();//相机采图停止

    ui->pushButton_Start->setEnabled(true);//启用开始
    ui->pushButton_Stop->setEnabled(false);//禁用停止
}

void Form::onTimerStreamStatistic()//定时器刷新流
{
	QString strStatic = ui->widget->getStatistic();
    ui->label_Statistic->setText(strStatic);
}

void Form::closeEvent(QCloseEvent * event)//关闭事件，包括停止采图和关闭相机
{
	on_pushButton_Stop_clicked();
	ui->widget->CameraClose();
}

