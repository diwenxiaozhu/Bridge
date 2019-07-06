#pragma once
#include "Item.h"
#include <QString.h>

class YBItem : public Item
{
	Q_OBJECT;
public:
	explicit YBItem(QGraphicsItem *parent = 0);
	//修改属性
	void change();
	//展示历史数据
	void display();
	//返回节点信息
	QString getInfo();

private:
	double proWave;        //出厂中心波长
public slots:
	//修改属性槽函数
	void setAttribute(QStringList info);
};