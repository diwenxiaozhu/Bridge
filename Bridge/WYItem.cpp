#include "WYItem.h"
#include "QGraphicsSceneEvent"
#include "AttributeForm.h"
#include "QFile"
#include "QMessageBox"
#include <QtCharts/QtCharts>
#include <QtCharts/QLineSeries>

// �Զ��� Item
WYItem::WYItem(QGraphicsItem *parent)
	: Item(parent)
{
	//Ĭ�ϳ�ʼ������
	maxD = minD = 0.0;
	//λ�ƴ����� Ĭ�ϻ�ɫ
	setBrush(QBrush(Qt::yellow));
}


void WYItem::change() {
	AttributeForm *changeform = new AttributeForm();
	connect(changeform, SIGNAL(change()), this, SLOT(setAttribute(QStringList)));
	changeform->ui.proWaveLabel->hide();
	changeform->ui.proWaveText->hide();
	changeform->ui.unitLabel->hide();
	changeform->ui.unitText->hide();

	changeform->ui.nameText->setText(getName());
	changeform->ui.modelText->setText(getModel());
	changeform->ui.produceText->setText(getProduce());
	changeform->ui.dateText->setText(getDate().toString("yyyy/MM/dd"));
	changeform->ui.minText->setText(QString::number(minD));
	changeform->ui.maxText->setText(QString::number(maxD));


	changeform->setWindowFlags(changeform->windowFlags() | Qt::WindowStaysOnTopHint);
	changeform->show();
}

void WYItem::setAttribute(QStringList info) {
	setName(info[0]);
	setModel(info[1]);
	setProduce(info[2]);
	setDate(QDate::fromString(info[3], "yyyy/M/d"));
	minD = info[4].toDouble();
	maxD = info[5].toDouble();
}

QString WYItem::getInfo() {
		return QStringLiteral("���������: ") + getName() + QStringLiteral("\n�������ͺ�: ") + getModel() + QStringLiteral("\n��������: ")
			+ getProduce() + QStringLiteral("\n��������: ") + getDate().toString() + QStringLiteral("\n��������: ") + 
			QString::number(minD, 10, 3) + QStringLiteral("\n��������: ") + QString::number(maxD, 10, 3);
}

void WYItem::display() {
	// ���ļ�
	QFile file(":/Bridge/wy.txt");
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