#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Bridge.h"
#include "Scene.h"

class Bridge : public QMainWindow
{
	Q_OBJECT
signals:

public:
	Bridge(QWidget *parent = Q_NULLPTR);
	Scene *scene;

public slots:
	//快捷栏 [添加传感器]
	void on_AddND_triggered();
	void on_AddWY_triggered();
	void on_AddYB_triggered();
	void delND();
	void delWY();
	void delYB();
	void ItemSelect(QString info);
	void on_actionQT_triggered();
	void on_actionAuthor_triggered();

private:
	Ui::BridgeClass ui;
};
