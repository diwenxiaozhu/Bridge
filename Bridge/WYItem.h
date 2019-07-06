#pragma once
#include "Item.h"
class WYItem : public Item
{
	Q_OBJECT;
public:
	explicit WYItem(QGraphicsItem *parent = 0);
	//void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
	void change();
	void display();
	QString getInfo();
private:
	double maxD;        //量程上限
	double minD;        //量程下限
public slots:
	//修改属性槽函数
	void setAttribute(QStringList info);
};