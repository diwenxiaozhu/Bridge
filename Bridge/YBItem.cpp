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
	QFile file(":/Bridge/yb2.txt");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QMessageBox::question(NULL, "WARNINGS", "File ERROR", QMessageBox::Yes);
		return;
	}

	QStandardItemModel *model = new QStandardItemModel(10, 4);
	QTableView *tableview = new QTableView();
	tableview->setModel(model);
	model->setHeaderData(0, Qt::Horizontal, QObject::tr("Day"));
	model->setHeaderData(1, Qt::Horizontal, QObject::tr("Time"));
	model->setHeaderData(2, Qt::Horizontal, QObject::tr("Num"));
	model->setHeaderData(3, Qt::Horizontal, QObject::tr("Value"));
	QStandardItemModel *model1 = new QStandardItemModel(10, 4);
	QTableView *tableview1 = new QTableView();
	tableview1->setModel(model1);
	model1->setHeaderData(0, Qt::Horizontal, QObject::tr("Day"));
	model1->setHeaderData(1, Qt::Horizontal, QObject::tr("Time"));
	model1->setHeaderData(2, Qt::Horizontal, QObject::tr("Num"));
	model1->setHeaderData(3, Qt::Horizontal, QObject::tr("Value/us"));
	QLineSeries *series = new QLineSeries(); 
	QLineSeries *series1 = new QLineSeries();
	bool flag = false;
	int row = 0;
	int row1 = 0;
	while (!file.atEnd())
	{
		QByteArray line = file.readLine();
		QString str(line);
		//�ָ��ַ���
		QStringList list = str.split(" ");

		if (getName() == list[2]) {
			flag = true;
			//����
			QDateTime tt;
			tt.setDate(QDate::fromString(list[0], "yyyy/MM/dd"));
			tt.setTime(QTime::fromString(list[1], "hh:mm:ss"));
			qDebug() << list[0] << list[1] << tt.date();
			//���������
			series->append(tt.toMSecsSinceEpoch(), list[3].toDouble());
			model->insertRows(row, 1, QModelIndex());
			model->setData(model->index(row, 0, QModelIndex()), list[0]);
			model->setData(model->index(row, 1, QModelIndex()), list[1]);
			model->setData(model->index(row, 2, QModelIndex()), list[2]);
			model->setData(model->index(row, 3, QModelIndex()), list[3]);
			model1->insertRows(row1, 1, QModelIndex());
			int index = getName().toInt();
			double cul = list[3].toDouble();
			double result = 1000 * (cul - proWave) + 4;
			series1->append(tt.toMSecsSinceEpoch(), result);
			model1->setData(model1->index(row1, 0, QModelIndex()), list[0]);
			model1->setData(model1->index(row1, 1, QModelIndex()), list[1]);
			model1->setData(model1->index(row1, 2, QModelIndex()), list[2]);
			model1->setData(model1->index(row1, 3, QModelIndex()), result);
			row++;
			row1++;
		}
	}
	file.close();


	////chart
	//QChart *chart = new QChart();
	//// ��ͼ������
	//chart->legend()->hide();
	//// ����series����һ������Ҫ������Ҫ��series������QChart���ܽ�������Ⱦ������
	//chart->addSeries(series);
	//// ����OpenGL��QLineSeries֧��GPU���ƣ�Qt�����е�ͼ�������ǲ�֧�ֵġ�
	//series->setUseOpenGL(true);
	//// ����ͼ�����
	//chart->setTitle(QStringLiteral("��������"));

	////��X��
	//QDateTimeAxis *axisX = new QDateTimeAxis;
	//axisX->setTickCount(1000);
	//axisX->setFormat("yyyy/MM/dd hh:mm:ss");
	//axisX->setTitleText("Date");
	//chart->addAxis(axisX, Qt::AlignBottom);
	//series->attachAxis(axisX);

	//QValueAxis *axisY = new QValueAxis;
	//axisY->setLabelFormat("%f");
	//axisY->setTitleText("value");
	//chart->addAxis(axisY, Qt::AlignLeft);
	//series->attachAxis(axisY);

	//QChartView *view = new QChartView(chart);
	//// ��������ݣ�����ʾЧ������
	//view->setRenderHint(QPainter::Antialiasing);
	//view->resize(1000, 900);
	//// ��ʾͼ��
	//view->show();

	//chart
	QChart *chart1 = new QChart();
	// ��ͼ������
	chart1->legend()->hide();
	// ����series����һ������Ҫ������Ҫ��series������QChart���ܽ�������Ⱦ������
	chart1->addSeries(series1);
	// ����OpenGL��QLineSeries֧��GPU���ƣ�Qt�����е�ͼ�������ǲ�֧�ֵġ�
	series1->setUseOpenGL(true);
	// ����ͼ�����
	chart1->setTitle(QStringLiteral("��������(�����)"));

	//��X��
	QDateTimeAxis *axisX1 = new QDateTimeAxis;
	axisX1->setTickCount(1000);
	axisX1->setFormat("yyyy/MM/dd hh:mm:ss");
	axisX1->setTitleText("Date");
	chart1->addAxis(axisX1, Qt::AlignBottom);
	series1->attachAxis(axisX1);

	QValueAxis *axisY1 = new QValueAxis;
	axisY1->setLabelFormat("%f");
	axisY1->setTitleText("value");
	chart1->addAxis(axisY1, Qt::AlignLeft);
	series1->attachAxis(axisY1);

	QChartView *view1 = new QChartView(chart1);
	// ��������ݣ�����ʾЧ������
	view1->setRenderHint(QPainter::Antialiasing);
	view1->resize(1000, 900);
	// ��ʾͼ��
	view1->show();

	tableview->setWindowTitle(QStringLiteral("Ӧ������(����ǰ)"));
	tableview->resize(450, 350);
	tableview->show();

	tableview1->setWindowTitle(QStringLiteral("Ӧ������(�����)"));
	tableview1->resize(450, 350);
	tableview1->show();
}