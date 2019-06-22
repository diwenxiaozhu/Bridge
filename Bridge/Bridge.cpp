#include "Bridge.h"
#include <QMessageBox>
#include <QImage>
#include <QGraphicsItem>
#include <QPen>
#include <QKeyEvent>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QColorDialog>
#include <QTimer>
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QtCharts/QtCharts>
#include "Scene.h"
#include "Item.h"
#include "YBItem.h"
#include "WYItem.h"
#include "NDItem.h"
#include "QMessageBox"
#include <QFile>
#include <QtCharts/QtCharts>
#include <QtCharts/QLineSeries>
#include "AttributeForm.h"
QT_CHARTS_USE_NAMESPACE


Bridge::Bridge(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//创建场景
	scene = new Scene();
	scene->setSceneRect(0,0,0,0);
	//创建一个Qpixmap 并初始化桥梁图片
	QPixmap *t = new QPixmap(":/Bridge/Resources/bridge.png");
	//将图片绑定到场景上
	scene->addPixmap(*t);
	//将场景绑定到GraphicsView上
	ui.bridgeImage->setScene(scene);
	//重置大小
	ui.bridgeImage->resize(t->width(), t->height());

	ui.bridgeImage->show();
	//取消滚轮
	ui.bridgeImage->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	ui.bridgeImage->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	connect(scene, SIGNAL(delNDsignal()), this, SLOT(delND()));
	connect(scene, SIGNAL(delWYsignal()), this, SLOT(delWY()));
	connect(scene, SIGNAL(delYBsignal()), this, SLOT(delYB()));
}

//添加挠度传感器槽函数
void Bridge::on_AddND_triggered() {
	ui.NDNum->setText(QString::number(ui.NDNum->text().toInt() + 1));
	NDItem *t = new NDItem;
	scene->addItem(t);
	connect(t, SIGNAL(select(QString)), this, SLOT(ItemSelect(QString)));
	QMessageBox::question(NULL, "Tip", "Add Successful", QMessageBox::Yes);
}

//添加应变传感器槽函数
void Bridge::on_AddYB_triggered() {
	ui.YBNum->setText(QString::number(ui.YBNum->text().toInt() + 1));
	YBItem *t = new YBItem;
	scene->addItem(t);
	connect(t, SIGNAL(select(QString)), this, SLOT(ItemSelect(QString)));
	QMessageBox::question(NULL, "Tip", "Add Successful", QMessageBox::Yes);
}

//添加位移传感器槽函数
void Bridge::on_AddWY_triggered() {
	ui.WYNum->setText(QString::number(ui.WYNum->text().toInt() + 1));
	WYItem *t = new WYItem;
	scene->addItem(t);
	connect(t, SIGNAL(select(QString)), this, SLOT(ItemSelect(QString)));
	QMessageBox::question(NULL, "Tip", "Add Successful", QMessageBox::Yes);
}

//删除挠度传感器槽函数
void Bridge::delND() {
	ui.NDNum->setText(QString::number(ui.NDNum->text().toInt() - 1));
}

//删除位移传感器槽函数
void Bridge::delWY() {
	ui.WYNum->setText(QString::number(ui.WYNum->text().toInt() - 1));
}

//删除应变传感器槽函数
void Bridge::delYB() {
	qDebug() << "121212121";
	ui.YBNum->setText(QString::number(ui.YBNum->text().toInt() - 1));
}

//传感器被选中操作函数
void Bridge::ItemSelect(QString info) 
{
	ui.Info->setText(info);
}

//动作关于Qt槽函数
void Bridge::on_actionQT_triggered()
{
	QMessageBox::aboutQt(this, tr("关于Qt"));
}

//动作关于作者槽函数
void Bridge::on_actionAuthor_triggered()
{
	QMessageBox box;
	//QStringLiteral 处理中文字符串
	box.setWindowTitle(QStringLiteral("关于作者"));
	box.setIcon(QMessageBox::Information);
	box.setText(QStringLiteral("作者: 侯捷 朱棣文\n学校: 重庆交通大学"));
	box.addButton(QStringLiteral("确定"), QMessageBox::AcceptRole);
	if (box.exec() == QMessageBox::Accepted)
		box.close();
}