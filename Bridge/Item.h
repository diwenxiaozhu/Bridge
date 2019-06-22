#pragma once

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QDate>
#include <QString>
#include <QDebug>

//QGraphicsScene管理QGraphicsItem（单击/选择/移动/缩放/删除）
// 自定义 Item 传感器

class Item : public QObject, public QGraphicsRectItem
{
	Q_OBJECT
signals:
	void select(QString info);

public:
	Item(QGraphicsItem *parent = 0);
	//获取属性
	QString getName();
	QString getModel();
	QString getProduce();
	QDate getDate();
	//设置属性
	void setName(QString _name);
	void setModel(QString _Model);
	void setProduce(QString _produce);
	void setDate(QDate _date);
	//展示数据
	void display();
	//修改数据
	virtual void change();
	// 返回信息
	virtual QString getInfo();

protected:
	//Shift+左键：进行选择  Alt：准备缩放
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	//Alt+拖拽：进行缩放 移动
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
	//重写鼠标双击事件
	virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);

	// 使item可使用qgraphicsitem_cast
	int type() const;
private:
	bool m_bResizing;
	QString name;        //传感器名称
	QString model;       //传感器规格
	QString produce;     //生产厂商
	QDate date;          //生产日期
};