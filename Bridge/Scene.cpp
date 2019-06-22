#pragma once
#include "Scene.h"
#include "QGraphicsSceneEvent"
#include "Item.h"
#include "qlogging.h"
#include "qevent.h"
#include <QDebug>
#include "YBItem.h"
#include "WYItem.h"
#include "NDItem.h"

// �Զ��� Scene
void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	qDebug() << "Custom scene clicked.";
	QGraphicsScene::mousePressEvent(event);
	if (!event->isAccepted()) {
		if (event->button() == Qt::RightButton) {
			// ��������Ƿ��� item
			QGraphicsItem *itemToRemove = NULL;
			foreach(QGraphicsItem *item, items(event->scenePos())) {
				if (item->type() == QGraphicsItem::UserType + 1) {
					itemToRemove = item;
					break;
				}
			}
			// ����ͼ��
			if (itemToRemove != NULL) {
				//((Item *)itemToRemove)->display();
				if (((Item *)itemToRemove)->inherits("YBItem"))
					((YBItem *)itemToRemove)->display();
				else if (((Item *)itemToRemove)->inherits("WYItem"))
					((WYItem *)itemToRemove)->display();
				else if (((Item *)itemToRemove)->inherits("NDItem"))
					((NDItem *)itemToRemove)->display();
			}
		}
	}
}


void Scene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) {
	qDebug() << "Item scene double clicked.";
	QGraphicsScene::mouseDoubleClickEvent(event);
}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	qDebug() << "Custom scene moved.";
	QGraphicsScene::mouseMoveEvent(event);
}

void Scene::keyPressEvent(QKeyEvent *event) {
	if (event->key() == Qt::Key_Backspace) {
		// �Ƴ�����ѡ�е� items
		qDebug() << "selected items " << selectedItems().size();
		while (!selectedItems().isEmpty()) {
			if (((Item *)selectedItems().front())->inherits("YBItem"))
				emit delYBsignal();
			else if (((Item *)selectedItems().front())->inherits("WYItem"))
				emit delWYsignal(), qDebug() << "WY";
			else if(((Item *)selectedItems().front())->inherits("NDItem"))
				emit delNDsignal(), qDebug() << "ND";
			removeItem(selectedItems().front());
		}
	}
	else {
		QGraphicsScene::keyPressEvent(event);
	}
}