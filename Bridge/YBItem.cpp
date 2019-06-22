#include "YBItem.h"
#include "QGraphicsSceneEvent"
#include "AttributeForm.h"
#include <qobject.h>
#include "qstring.h"
#include <QPainter>
#include <string>
#include <qfile.h>
#include <qmessagebox.h>
#include <qdebug.h>
#include "QFile"
#include "QMessageBox"
#include <QtCharts/QtCharts>
#include <QtCharts/QLineSeries>

// �Զ��� Item
YBItem::YBItem(QGraphicsItem *parent)
	: Item(parent)
{
	//Ĭ�ϳ�ʼ�� ���Ĳ���
	proWave = 0.0;
	//Ӧ�䴫����Ĭ��Ϊ ��ɫ
	setBrush(QBrush(Qt::red));
}



void YBItem::change() {
	AttributeForm *changeform = new AttributeForm();
	connect(changeform, SIGNAL(change(QStringList)), this, SLOT(setAttribute(QStringList)));
	changeform->ui.minLabel->hide();
	changeform->ui.maxLabel->hide();
	changeform->ui.minText->hide();
	changeform->ui.maxText->hide();
	changeform->ui.unitLabel->hide();
	changeform->ui.unitText->hide();

	changeform->ui.nameText->setText(getName());
	changeform->ui.modelText->setText(getModel());
	changeform->ui.produceText->setText(getProduce());
	changeform->ui.dateText->setText(getDate().toString("yyyy/MM/dd"));
	changeform->ui.proWaveText->setText(QString::number(proWave));

	changeform->setWindowFlags(changeform->windowFlags() | Qt::WindowStaysOnTopHint);
	changeform->show();
	
}

void YBItem::setAttribute(QStringList info) {
	qDebug() << info[0];
	setName(info[0]);
	setModel(info[1]);
	setProduce(info[2]);
	setDate(QDate::fromString(info[3], "yyyy/M/d"));
	qDebug() << info[4];
	proWave = info[4].toDouble();
}


QString YBItem::getInfo() {
	return QStringLiteral("���������: ") + getName() + QStringLiteral("\n�������ͺ�: ") + getModel() + QStringLiteral("\n��������: ")
		+ getProduce() + QStringLiteral("\n��������: ") + getDate().toString() + QStringLiteral("\n���Ĳ���: ") + QString::number(proWave, 10, 5);
}

void YBItem::display() {
	// ���ļ�
	QFile file(":/Bridge/yb.txt");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QMessageBox::question(NULL, "WARNINGS", "File ERROR", QMessageBox::Yes);
		return;
	}

	QLineSeries *series = new QLineSeries();
	bool flag = false;
	while (!file.atEnd())
	{
		QByteArray line = file.readLine();
		QString str(line);
		//�ָ��ַ���
		QStringList list = str.split("	");

		if (getName() == list[2]) {
			flag = true;
			//����
			QDateTime tt;
			tt.setDate(QDate::fromString(list[0], "yyyy/MM/dd"));
			tt.setTime(QTime::fromString(list[1], "hh:mm"));
			qDebug() << list[0] << list[1] << tt.date();
			//���������
			series->append(tt.toMSecsSinceEpoch(), list[3].toDouble());
		}
	}
	file.close();


	//chart
	QChart *chart = new QChart();
	// ��ͼ������
	chart->legend()->hide();
	// ����series����һ������Ҫ������Ҫ��series������QChart���ܽ�������Ⱦ������
	chart->addSeries(series);
	// ����OpenGL��QLineSeries֧��GPU���ƣ�Qt�����е�ͼ�������ǲ�֧�ֵġ�
	series->setUseOpenGL(true);
	// ����ͼ�����
	chart->setTitle(QStringLiteral("��������"));

	//��X��
	QDateTimeAxis *axisX = new QDateTimeAxis;
	axisX->setTickCount(1000);
	axisX->setFormat("yyyy/MM/dd hh:mm");
	axisX->setTitleText("Date");
	chart->addAxis(axisX, Qt::AlignBottom);
	series->attachAxis(axisX);

	QValueAxis *axisY = new QValueAxis;
	axisY->setLabelFormat("%.2lf");
	axisY->setTitleText("value");
	chart->addAxis(axisY, Qt::AlignLeft);
	series->attachAxis(axisY);

	QChartView *view = new QChartView(chart);
	// ��������ݣ�����ʾЧ������
	view->setRenderHint(QPainter::Antialiasing);
	view->resize(1000, 900);
	// ��ʾͼ��
	view->show();
}