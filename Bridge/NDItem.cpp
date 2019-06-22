#include "NDItem.h"
#include "qlogging.h"
#include <QGraphicsSceneEvent>
#include "AttributeForm.h"
#include <string>
#include "QFile"
#include "QMessageBox"
#include <QtCharts/QtCharts>
#include <QtCharts/QLineSeries>


// 自定义 Item
NDItem::NDItem(QGraphicsItem *parent)
	: Item(parent)
{
	//默认初始化属性
	unit = "cm";
	//位移传感器 默认绿色
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

//返回
QString NDItem::getInfo() {
	return QStringLiteral("传感器编号: ") + getName() + QStringLiteral("\n传感器型号: ") + getModel() + QStringLiteral("\n生产厂家: ")
		+ getProduce() + QStringLiteral("\n生产日期: ") + getDate().toString() + QStringLiteral("\n单位是: ") + unit;
}

void NDItem::display() {
	// 打开文件
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
		//分割字符串
		QStringList list = str.split("	");

		if (getName() == list[2]) {
			flag = true;
			//创立
			QDateTime tt;
			tt.setDate(QDate::fromString(list[0], "yyyy/MM/dd"));
			tt.setTime(QTime::fromString(list[1], "hh:mm"));
			qDebug() << list[0] << list[1] << tt.date();
			//插入此数据
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
	// 将图例隐藏
	chart->legend()->hide();
	// 关联series，这一步很重要，必须要将series关联到QChart才能将数据渲染出来：
	chart->addSeries(series);
	// 开启OpenGL，QLineSeries支持GPU绘制，Qt其他有的图表类型是不支持的。
	series->setUseOpenGL(true);
	// 设置图表标题
	chart->setTitle(QStringLiteral("部件数据"));

	//绑定X轴
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
	// 开启抗锯齿，让显示效果更好
	view->setRenderHint(QPainter::Antialiasing);
	view->resize(1000, 900);
	// 显示图表

	view->show();
}