#include "test.h"
#include <QtWidgets/QApplication>
#include <QPushButton>
#include <iostream>
#include "atlstr.h"
#include <qfiledialog.h>
#include <qmessagebox.h>
#include <qspinbox.h>
#include <io.h>
#include <string>
#include <stdio.h>
#include <QThread>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/imgproc.hpp>
#include <qlistwidget.h>
#include <qtextstream.h>

#pragma warning(disable:4996)

using namespace std;
using namespace cv;

QString inputdirname = "C:";	// input directory path
QString outputdirname = "C:";	// output directory path
int spin_num;					// number of delay
QString GT = "C:";				// GT directory
string GT_Look_up_Table[100][3] = {};

double TP;
int FN;
int FP;
int num;

double ticks = cvGetTickFrequency()*10e6;
//int64 t0;

test::test(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

// Convert OpenCV::Mat -> Qt:QImage
QImage test::convertOpenCVMatToQtQImage(cv::Mat mat) {
	if (mat.channels() == 1) {                  // if grayscale image
		return QImage((uchar*)mat.data, (int)mat.cols, (int)mat.rows, (int)mat.step, QImage::Format_Indexed8);     // declare and return a QImage
	}
	else if (mat.channels() == 3) {             // if 3 channel color image
		cv::cvtColor(mat, mat, CV_BGR2RGB);     // invert BGR to RGB
		return QImage((uchar*)mat.data, (int)mat.cols, (int)mat.rows, (int)mat.step, QImage::Format_RGB888);       // declare and return a QImage
	}

	return QImage();  // return a blank QImage if the above did not work
}

// Processing & Display 
void test::slotDisplay() {
	// Initialization
	TP = 0.0;
	FN = 0;
	FP = 0;
	num = 0;

	FILE *out;
	Mat img;

	// update number of delay  
	spin_num = ui.spinBox->value();

	// Input Path
	string path = inputdirname.toLocal8Bit().constData(); // orignal input directory path

														  // input directory path processing to search image files
	string path_add = path;
	for (int i = path.length() - 1; i >= 0; i--) {
		if (path[i] == '/') {
			path_add.replace(i, 1, "//");
		}
	}

	// all bmp file to search
	string input_path = path_add;
	input_path.append("//*.bmp");

	struct _finddata_t fd;	// folder
	intptr_t handle;		// iterator

							// Directory Cheak
	if ((handle = _findfirst(input_path.c_str(), &fd)) == -1L)
		cout << "No file in directory!" << endl;

	vector<Rect> faces;	// Container of faces
	vector<Rect> human; // Container of human
	vector<Rect> car;	// Container of cars


	int GT_x, GT_y = 0;// GT x,y

	int i = 1;
	do {
		int cheak = 0;

		// Creat Image Path in Input Directory
		string img_path = path_add;
		img_path.append("//");
		img_path.append(fd.name);

		// Add image file name to listbox
		ui.listWidget->addItem(QString::number(i) + ". " + fd.name);
		i++;

		// GT Look up table Seting for one image
		if (ui.checkBox_5->isChecked()) {
			int i;
			for (i = 0; i<100; i++) {
				const char* name = GT_Look_up_Table[i][0].c_str();

				if (strcmp(fd.name, name) == 0) {
					num = i;
					break;
				}
			}
			// set gt x, gt y
			GT_x = std::stoi(GT_Look_up_Table[num][1]);
			GT_y = std::stoi(GT_Look_up_Table[num][2]);
		}

		// Image read
		img = imread(img_path, 1);

		// Just resize input image if you want
		cv::resize(img, img, Size(640, 480));

		// Image to draw
		Mat img_cp = img.clone();

		// Face Detection
		if (ui.checkBox->isChecked()) {
			cheak++;

			CascadeClassifier face_cascade;
			face_cascade.load("myhaar.xml");

			// Detect faces
			face_cascade.detectMultiScale(img, faces, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(140, 140));

			int flag = 1;
			// To draw Red rectangles around detected faces
			for (unsigned i = 0; i < faces.size(); i++) {
				rectangle(img_cp, faces[i], Scalar(0, 0, 255), 2, 1);

				// Evaluation & Calculate TP, FP, FN
				if (ui.checkBox_5->isChecked()) {
					if (faces[i].x < GT_x && GT_x < (faces[i].x + faces[i].width) && faces[i].y < GT_y && GT_y < (faces[i].y + faces[i].height)) {
						TP++;
						flag--;
					}
					else
						FP++;
				}
			}
			if (ui.checkBox_5->isChecked()) {
				if (flag > 0) {
					FN++;
				}
			}
		}

		// Human Detection
		if (ui.checkBox_2->isChecked()) {
			cheak++;

			CascadeClassifier human_cascade;
			human_cascade.load("myhaar2.xml");

			// Detect human
			human_cascade.detectMultiScale(img, human, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(140, 140));

			int flag = 1;
			// To draw Green rectangles around detected human
			for (unsigned i = 0; i < human.size(); i++) {
				rectangle(img_cp, human[i], Scalar(0, 255, 0), 2, 1);

				// Evaluation & Calculate TP, FP, FN
				if (ui.checkBox_5->isChecked()) {
					if (human[i].x < GT_x && GT_x < (human[i].x + human[i].width) && human[i].y < GT_y && GT_y < (human[i].y + human[i].height)) {
						TP++;
						flag--;
					}
					else
						FP++;
				}
			}
			if (ui.checkBox_5->isChecked()) {
				if (flag > 0) {
					FN++;
				}
			}
		}

		// Car Detection
		if (ui.checkBox_3->isChecked()) {
			cheak++;

			CascadeClassifier car_cascade;
			car_cascade.load("myhaar3.xml");

			// Detect cars
			car_cascade.detectMultiScale(img, car, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(140, 140));

			int flag = 1;
			// To draw Blue rectangles around detected cars
			for (unsigned i = 0; i < car.size(); i++) {
				rectangle(img_cp, car[i], Scalar(255, 0, 0), 2, 1);

				// Evaluation & Calculate TP, FP, FN
				if (ui.checkBox_5->isChecked()) {
					if (car[i].x < GT_x && GT_x < (car[i].x + car[i].width) && car[i].y < GT_y && GT_y < (car[i].y + car[i].height)) {
						TP++;
						flag--;
					}
					else
						FP++;
				}
			}
			if (ui.checkBox_5->isChecked()) {
				if (flag > 0) {
					FN++;
				}
			}
		}

		// Convert Image
		QImage qimgOutput = convertOpenCVMatToQtQImage(img_cp);

		// Display output
		ui.label->setPixmap(QPixmap::fromImage(qimgOutput));

		// ROI image Display & Save to file
		if (cheak > 0) {	// If at least one is checked

							// ROI image Display
			if (ui.checkBox_4->isChecked()) {
				if (ui.checkBox->isChecked()) {
					for (int i = 0; i < faces.size(); i++) {
						Mat roi_img1 = img_cp(faces[i]);

						// roi resize
						cv::resize(roi_img1, roi_img1, Size(300, 300));
						cv::cvtColor(roi_img1, roi_img1, CV_RGB2BGR);

						// Convert roi image
						QImage qimgroi1 = convertOpenCVMatToQtQImage(roi_img1);

						// Display output
						ui.label_4->setPixmap(QPixmap::fromImage(qimgroi1));

						QThread::msleep(500);
						qApp->processEvents();
					}
				}
				if (ui.checkBox_2->isChecked()) {
					for (int i = 0; i < human.size(); i++) {
						Mat roi_img2 = img_cp(human[i]);

						// roi resize
						cv::resize(roi_img2, roi_img2, Size(150, 300));
						cv::cvtColor(roi_img2, roi_img2, CV_RGB2BGR);

						// Convert roi image
						QImage qimgroi2 = convertOpenCVMatToQtQImage(roi_img2);

						// Display output
						ui.label_4->setPixmap(QPixmap::fromImage(qimgroi2));

						QThread::msleep(500);
						qApp->processEvents();
					}
				}
				if (ui.checkBox_3->isChecked()) {
					for (int i = 0; i < car.size(); i++) {
						Mat roi_img3 = img_cp(car[i]);

						// roi resize
						cv::resize(roi_img3, roi_img3, Size(300, 150));
						cv::cvtColor(roi_img3, roi_img3, CV_RGB2BGR);

						// Convert roi image
						QImage qimgroi3 = convertOpenCVMatToQtQImage(roi_img3);

						// Display output
						ui.label_4->setPixmap(QPixmap::fromImage(qimgroi3));

						QThread::msleep(500);
						qApp->processEvents();
					}
				}
			}

			// Save to file

			// Output Path
			string out_path = outputdirname.toLocal8Bit().constData();

			// output directory path processing to save image files
			string out_path_add = out_path;
			for (int i = out_path.length() - 1; i >= 0; i--) {
				if (out_path[i] == '/') {
					out_path_add.replace(i, 1, "//");
				}
			}
			string out_img_path = out_path_add;
			out_img_path.append("//output_");
			out_img_path.append(fd.name);

			Mat img_rgb = img_cp.clone();
			cv::cvtColor(img_rgb, img_rgb, CV_RGB2BGR);		// Convert RBG -> BGR
			imwrite(out_img_path, img_rgb);					// Save file
		}

		// Apply Delay
		if (spin_num != 0) {
			QThread::msleep(spin_num * 1000);
		}
		qApp->processEvents();


	} while (_findnext(handle, &fd) == 0);	// Until all the files in the folder have passed

	_findclose(handle);

	// Precision & Recall
	if (ui.checkBox_5->isChecked()) {
		double Precision = TP / (TP + FP);
		double Recall = TP / (TP + FN);
		QString P = QString::number(Precision);

		QString R = QString::number(Recall);

		ui.label_8->setText(P);
		ui.label_9->setText(R);
	}
}

// Select Input Directory to Qfiledialog
void test::selectInputDir() {
	inputdirname = QFileDialog::getExistingDirectory(
		this,
		tr("Select Directory"),
		"C://"
	);
	if (inputdirname > 0) {
		QMessageBox::information(this, tr("Input Directory Name"), inputdirname);
	}
	else {
		QMessageBox::information(this, tr("Input Directory Name"), "Cancled");
	}

	// Display Input Directory
	ui.label_2->setText(inputdirname);
}


// Select Output Directory to Qfiledialog
void test::selectOutputDir() {
	outputdirname = QFileDialog::getExistingDirectory(
		this,
		tr("Select Directory"),
		"C://"
	);
	if (outputdirname > 0) {
		QMessageBox::information(this, tr("Output Directory Name"), outputdirname);
	}
	else {
		QMessageBox::information(this, tr("Output Directory Name"), "Cancled");
	}

	// Display Onput Directory
	ui.label_3->setText(outputdirname);
}

//Evaluation File Select
void test::Evaluation() {
	GT = QFileDialog::getOpenFileName(
		this,
		tr("Select GT"),
		"C://",
		"Text file (*.txt);;All file (*.*)"
	);

	if (GT > 0) {
		QMessageBox::information(this, tr("GT"), GT);
	}
	else {
		QMessageBox::information(this, tr("GT"), "Cancled");
	}

	// File Read & Creat Look-up Table
	// All GT of files must exist in txt File.

	if (GT > 0) {
		QFile *file = new QFile;
		file->setFileName(GT);
		file->open(QIODevice::ReadOnly);

		QTextStream read(file);
		int i = 0;
		while (!read.atEnd()) {
			QString tmp = read.readLine();
			QStringList tmpList = tmp.split("/");
			GT_Look_up_Table[i][0] = tmpList[0].toStdString();	// file name
			GT_Look_up_Table[i][1] = tmpList[1].toStdString();  // x
			GT_Look_up_Table[i][2] = tmpList[2].toStdString();	// y
			i++;
		}

		file->close();
	}
}