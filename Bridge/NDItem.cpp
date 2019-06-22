#include "NDItem.h"
#include "qlogging.h"
#include <QGraphicsSceneEvent>
#include "AttributeForm.h"
#include <string>
#include "QFile"
#include "QMessageBox"
#include <QtCharts/QtCharts>
#include <QtCharts/QLineSeries>


// �Զ��� Item
NDItem::NDItem(QGraphicsItem *parent)
	: Item(parent)
{
	//Ĭ�ϳ�ʼ������
	unit = "cm";
	//λ�ƴ����� Ĭ����ɫ
	setBrush(QBrush(Qt::green));
}

void NDItem::change() {
	AttributeForm *changeform = new AttributeForm();
	connect(changeform, SIGNAL(change(QStringList)), this, SLOT(setAttribute(QStringList)));
	changeform->ui.minLabel->hide();
	changeform->ui.maxLabel->hide();
	changeform->ui.minText->hide();
	changeform->ui.maxText->hide();
	changeform->ui.proWaveLabel->hide();
	changeform->ui.proWaveText->hide();

	changeform->ui.nameText->setText(getName());
	changeform->ui.modelText->setText(getModel());
	changeform->ui.produceText->setText(getProduce());
	changeform->ui.dateText->setText(getDate().toString("yyyy/MM/dd"));
	changeform->ui.unitText->setText(unit);

	changeform->setWindowFlags(changeform->windowFlags() | Qt::WindowStaysOnTopHint);
	changeform->show();
}

void NDItem::setAttribute(QStringList info) {
	setName(info[0]);
	setModel(info[1]);
	setProduce(info[2]);
	qDebug() << QDate::fromString(info[3], "yyyy/M/d");
	setDate(QDate::fromString(info[3], "yyyy/M/d"));
	qDebug() << info[4];
	unit = info[4];
}

//����
QString NDItem::getInfo() {
	return QStringLiteral("���������: ") + getName() + QStringLiteral("\n�������ͺ�: ") + getModel() + QStringLiteral("\n��������: ")
		+ getProduce() + QStringLiteral("\n��������: ") + getDate().toString() + QStringLiteral("\n��λ��: ") + unit;
}

void NDItem::display() {
	// ���ļ�
	QFile file(":/Bridge/nd.txt");
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

		qDebug() << str;
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
	if (!flag) {
		QMessageBox::question(NULL, "WARNINGS", "NOT FIND", QMessageBox::Yes);
		return;
	}


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
	axisX->setTickCount(10);
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