#include "test.h"
#include <QtWidgets/QApplication>
#include <QPushButton>
#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>


using namespace std;
using namespace cv;

#define Output_Path "C:\\Users\\dotd\\Documents\\Visual Studio 2015\\Projects\\0603_VDSR_Serial\\Output"

int main(int argc, char *argv[])
{
	//char* file_name;
	//file_name = strtok("a\\n\\c", "\\");
	//while(file_name != NULL){
	//
	//	printf("%s", file_name);
	//	//printf("ok");
	//	file_name = strtok(NULL, "\\");
	//}

	//char* result;

	//char str[20] = "I have a dream";

	//result = strtok(str, " ");
	//while (result != NULL) {
	//	printf("%s\n", result);
	//	result = strtok(NULL, " ");
	//	
	//}

	//printf("ok");






	// Run Qt
	QApplication a(argc, argv);
	test w;
	w.show();

	return a.exec();
}
