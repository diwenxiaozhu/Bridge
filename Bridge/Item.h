#pragma once

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QDate>
#include <QString>
#include <QDebug>

//QGraphicsScene����QGraphicsItem������/ѡ��/�ƶ�/����/ɾ����
// �Զ��� Item ������

class Item : public QObject, public QGraphicsRectItem
{
	Q_OBJECT
signals:
	void select(QString info);

public:
	Item(QGraphicsItem *parent = 0);
	//��ȡ����
	QString getName();
	QString getModel();
	QString getProduce();
	QDate getDate();
	//��������
	void setName(QString _name);
	void setModel(QString _Model);
	void setProduce(QString _produce);
	void setDate(QDate _date);
	//չʾ����
	void display();
	//�޸�����
	virtual void change();
	// ������Ϣ
	virtual QString getInfo();

protected:
	//Shift+���������ѡ��  Alt��׼������
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	//Alt+��ק���������� �ƶ�
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
	//��д���˫���¼�
	virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);

	// ʹitem��ʹ��qgraphicsitem_cast
	int type() const;
private:
	bool m_bResizing;
	QString name;        //����������
	QString model;       //���������
	QString produce;     //��������
	QDate date;          //��������
};