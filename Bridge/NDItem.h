#pragma once
#include "Item.h"
class NDItem : public Item
{
	Q_OBJECT;
public:
	explicit NDItem(QGraphicsItem *parent = 0);
	//绘制节点数据图像
	void display();
	//修改属性
	void change();
	//返回节点信息
	QString getInfo();
private:
	QString unit;        //单位
public slots:
	//修改属性槽函数
	void setAttribute(QStringList info);
};