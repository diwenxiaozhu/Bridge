#pragma once
#include "Item.h"
#include <QString.h>

class YBItem : public Item
{
	Q_OBJECT;
public:
	explicit YBItem(QGraphicsItem *parent = 0);
	//void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
	void change();
	void display();
	QString getInfo();

private:
	double proWave;        //出厂中心波长
public slots:
	void setAttribute(QStringList info);
};