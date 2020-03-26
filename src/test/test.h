#pragma once

#include <QtWidgets/QApplication>
#include <QPushButton>
#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <QtWidgets/QMainWindow>
#include "ui_test.h"
#include "atlstr.h"
#include <Windows.h>
#include <qlistwidget.h>

using namespace std;
using namespace cv;


class test : public QMainWindow
{
	Q_OBJECT

public:
	test(QWidget *parent = 0);
	QImage test::convertOpenCVMatToQtQImage(cv::Mat mat);

private:
	Ui::testClass ui;

	private slots:
	void slotDisplay();
	void selectInputDir();
	void selectOutputDir();
	void Evaluation();
};
