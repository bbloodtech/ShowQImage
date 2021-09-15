#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent)
    ,ui(new Ui::Form)
{
    ui->setupUi(this);

    connect(&m_staticTimer, &QTimer::timeout, this, &Form::onTimerStreamStatistic);//ÿ1000msˢ��һ��״̬��

    initUi();//���ó�ʼ������
}

Form::~Form()
{
	delete ui;
}
//��ʼ������
void Form::initUi()
{
    //label_StatisticΪһ��label
    ui->label_Statistic->setText("");//�������֮ǰ����ʾ״̬��


	CSystem &systemObj = CSystem::getInstance();
    //�������ʧ�ܷ���false
	if (false == systemObj.discovery(m_vCameraPtrList))
	{
		printf("discovery fail.\n");
		return;
	}
    //���ص�����б���С��1
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
            ui->comboBox->addItem(m_vCameraPtrList[i]->getKey());//���������Ŀ
		}

		ui->widget->SetCemera(m_vCameraPtrList[0]->getKey());
	}
    //��ʼ��ʱ����������ť����
	ui->pushButton_Close->setEnabled(false);
	ui->pushButton_Start->setEnabled(false);
	ui->pushButton_Stop->setEnabled(false);
}

// ����Ҫ���ӵ����
void Form::on_comboBox_currentIndexChanged(int nIndex)//�����б�ı�
{
	ui->widget->SetCemera(m_vCameraPtrList[nIndex]->getKey());
}

// ����
void Form::on_pushButton_Open_clicked()
{

	if (!ui->widget->CameraOpen())
	{
		return;
	}
    //�����ʧ����return
    ui->pushButton_Open->setEnabled(false);//���ô������ť
	ui->pushButton_Close->setEnabled(true);
	ui->pushButton_Start->setEnabled(true);
	ui->pushButton_Stop->setEnabled(false);
    ui->comboBox->setEnabled(false);//���������˵�

	/*�������֮����ʾͳ����Ϣ������ֵΪ0*/
	ui->widget->resetStatistic();
	QString strStatic = ui->widget->getStatistic();
    ui->label_Statistic->setText(strStatic);
}

// �Ͽ�
void Form::on_pushButton_Close_clicked()
{
	on_pushButton_Stop_clicked();
	ui->widget->CameraClose();

    ui->label_Statistic->setText("");//�Ͽ�����Ժ���ʾ״̬��

	ui->pushButton_Open->setEnabled(true);
	ui->pushButton_Close->setEnabled(false);
	ui->pushButton_Start->setEnabled(false);
	ui->pushButton_Stop->setEnabled(false);
	ui->comboBox->setEnabled(true);
}

// ��ʼ
void Form::on_pushButton_Start_clicked()
{
	// ������������
	//ui->widget->CameraChangeTrig(CammerWidget::trigContinous);

	ui->widget->CameraStart();

    ui->pushButton_Start->setEnabled(false);//���ÿ�ʼ
    ui->pushButton_Stop->setEnabled(true);//����ֹͣ

    ui->widget->resetStatistic();//��ʾ״̬����Ϣ
	m_staticTimer.start(100);
}

// ֹͣ
void Form::on_pushButton_Stop_clicked()
{
    m_staticTimer.stop();//��ʱ��ֹͣ

    ui->widget->CameraStop();//�����ͼֹͣ

    ui->pushButton_Start->setEnabled(true);//���ÿ�ʼ
    ui->pushButton_Stop->setEnabled(false);//����ֹͣ
}

void Form::onTimerStreamStatistic()//��ʱ��ˢ����
{
	QString strStatic = ui->widget->getStatistic();
    ui->label_Statistic->setText(strStatic);
}

void Form::closeEvent(QCloseEvent * event)//�ر��¼�������ֹͣ��ͼ�͹ر����
{
	on_pushButton_Stop_clicked();
	ui->widget->CameraClose();
}

