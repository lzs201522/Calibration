// CalibrationAlone.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <opencv\cv.h>
#include <opencv\highgui.h>
#include <time.h>
#include <complex>
#include <math.h>

//#define POINTHEIGHT 9
//#define POINTWIDTH 11
//#define PICTURE_NUM 4
////bool ReadFilePoint(char* path,int Number,CvMat* &PicPoint)
////{
//////	std::ifstream stream("try.txt");
////	FILE * fp;
////	uchar flag=0;
////	float Buffer[198];
////	if (Number==0||path==NULL)
////	{
////		return false;
////	}
////	short i=0, j=0,k=0;
////	PicPoint = cvCreateMat(Number*POINTHEIGHT*POINTWIDTH, 2, CV_32F);
////	char TempChar[64];
////	char TempNumber[10];
////	for ( i = 0; i < Number; i++)
////	{
////		memset(TempChar, 0, 20);
////		memset(TempNumber, 0, 10);
////		memset(Buffer, 0, 4 * 198);
////		strcat(TempChar, path);
////		_ltoa(i+1, TempNumber, 10);
////		strcat(TempChar, TempNumber);
////		strcat(TempChar, ".txt");
////		
////		fp = fopen(TempChar, "r+");
////		
////		
////		if (fp!=0)
////		{
////			
////				for (j = 0; j < POINTHEIGHT; j++)
////				{
////					for (k = 0; k < POINTWIDTH; k++)
////					{
//////						stream >> CV_MAT_ELEM(*PicPoint, float, i*POINTHEIGHT*POINTWIDTH + j*POINTWIDTH + k, 0);
//////						stream >> CV_MAT_ELEM(*PicPoint, float, i*POINTHEIGHT*POINTWIDTH + j*POINTWIDTH + k, 1);
////						fscanf(fp, "%f", &CV_MAT_ELEM(*PicPoint, float, i*POINTHEIGHT*POINTWIDTH + j*POINTWIDTH + k, 0));
////						fscanf(fp, "%f", &CV_MAT_ELEM(*PicPoint, float, i*POINTHEIGHT*POINTWIDTH + j*POINTWIDTH + k, 1));
////						std::cout << CV_MAT_ELEM(*PicPoint, float, i*POINTHEIGHT*POINTWIDTH + j*POINTWIDTH + k, 0) << '\t';
////						std::cout << CV_MAT_ELEM(*PicPoint, float, i*POINTHEIGHT*POINTWIDTH + j*POINTWIDTH + k, 1) << '\n';
////					}
////				}
////			fclose(fp);
////		}
////		
//////		stream.close();
////	}
////	return true;
////}
////bool GetPlatePoint(int num, CvMat* &Camera)
////{
////	Camera = cvCreateMat(num*POINTHEIGHT*POINTWIDTH, 3, CV_32F);
////	for (int i = 0; i < num; i++)
////	{
////		for (int j = 0; j < POINTHEIGHT; j++)
////		{
////			for (int k = 0; k < POINTWIDTH; k++)
////			{
////				CV_MAT_ELEM(*Camera, float, i*POINTHEIGHT*POINTWIDTH + j*POINTWIDTH + k, 0) = k;
////				CV_MAT_ELEM(*Camera, float, i*POINTHEIGHT*POINTWIDTH + j*POINTWIDTH + k, 1) = j;
////				CV_MAT_ELEM(*Camera, float, i*POINTHEIGHT*POINTWIDTH + j*POINTWIDTH + k, 2) = 0;
////			}
////		}
////	}
////	return true;
////}
////int _tmain(int argc, _TCHAR* argv[])
////{
////	//IplImage* image = cvLoadImage("test.jpg");
////	//cvShowImage("test", image);
////	//cvWaitKey(0);
////	//cvReleaseImage(&image);
////	short i=0, j=0;
////	CvMat* imgPoint = NULL;
////	CvMat* imgWorld = NULL;
////	CvSize imgSize;
////	CvMat* PointNum = cvCreateMat(PICTURE_NUM, 1, CV_32S);
////
////	for (i = 0; i < PICTURE_NUM; i++)
////	{
////		CV_MAT_ELEM(*PointNum, int, i, 0) = POINTHEIGHT*POINTWIDTH;
////	}
////	imgSize.height = 600;
////	imgSize.width = 800;
////	GetPlatePoint(PICTURE_NUM, imgWorld);
////	ReadFilePoint("D:\\CalibrationAlone\\CalibrationAlone\\ccd", PICTURE_NUM, imgPoint);
////	CvMat* camera = cvCreateMat(3, 3, CV_32FC1);
////	CvMat* distortion = cvCreateMat(5, 1, CV_32FC1);
////	CvMat* rotation = cvCreateMat(PICTURE_NUM, 3, CV_32FC1);;
////	CvMat* translation = cvCreateMat(PICTURE_NUM, 3, CV_32FC1);
////	memset(camera->data.fl, 0, 9 * 4);
////	CvMat* RolateMatrix = cvCreateMat(3, 3, CV_32F);
////	CvMat* Vector = cvCreateMat(3, 1, CV_32F);
////	CV_MAT_ELEM(*camera, float, 0, 0) = 1.0f;
////	CV_MAT_ELEM(*camera, float, 1, 1) = 1.0f;
////	
////
////	float error = 0;
////	error = cvCalibrateCamera2(imgWorld, imgPoint, PointNum, imgSize, camera, distortion, rotation, translation, 0);
////	std::ofstream file("Inner.txt");
////	for ( i = 0; i < 3; i++)
////	{
////		file << camera->data.fl[i * 3] << '\t';
////		file << camera->data.fl[i * 3+1] << '\t';
////		file << camera->data.fl[i * 3+2] << '\t';
////		file << '\n';
////	}
////	file.close();
////	file.open("Distortion.txt");
////	for ( i = 0; i < 5; i++)
////	{
////		file << distortion->data.fl[i] << '\t';
////	}
////	file.close();
////	file.open("Translation.txt");
////	for ( i = 0; i < 4; i++)
////	{
////		file << translation->data.fl[i*3] << '\t';
////		file << translation->data.fl[i*3+1] << '\t';
////		file << translation->data.fl[i*3+2] << '\t';
////		file << '\n';
////	}
////	file.close();
////	file.open("RolateMatrix.txt");
////	for (size_t i = 0; i < 4; i++)
////	{
////		for ( j = 0; j < 3; j++)
////		{
////			Vector->data.fl[j] = rotation->data.fl[3 * i + j];
////		}
////		cvRodrigues2(Vector, RolateMatrix);
////		for ( j = 0; j < 3; j++)
////		{
////			file << RolateMatrix->data.fl[3 * j]<<'\t';
////			file << RolateMatrix->data.fl[3 * j+1]<<'\t';
////			file << RolateMatrix->data.fl[3 * j+2]<<'\t';
////			file << '\n';
////		}
////		
////	}
////	file.close();
////	return 0;
////}
////
////bool ImageClean(IplImage *input,IplImage* output)
////{
////	CvSize inputsize = cvGetSize(input);
////	CvSize outputsize = cvGetSize(output);
////	short i=0, j = 0;
////	if (inputsize.height!=outputsize.height||inputsize.width!=outputsize.width)
////	{
////		return false;
////	}
////	cvCopy(input, output);
////	for ( i = 0; i < inputsize.height; i++)
////	{
////		for ( j = 0; j < inputsize.width; j++)
////		{
////			if ((uchar)input->imageData[i*inputsize.width + j]>240 || (uchar)input->imageData[i*inputsize.width + j]<10)
////			{
////				output->imageData[i*inputsize.width + j]=0;
////			}
////		}
////	}
////	return true;
////}
////bool DrawBox(CvBox2D box, IplImage* img)
////{
////	if (img==NULL)
////	{
////		return 0;
////	}
////	CvPoint2D32f point[4];
////	int i;
////	for (i = 0; i<4; i++)
////	{
////		point[i].x = 0;
////		point[i].y = 0;
////	}
////	cvBoxPoints(box, point); //计算二维盒子顶点
////	CvPoint pt[4];
////	for (i = 0; i<4; i++)
////	{
////		pt[i].x = (int)point[i].x;
////		pt[i].y = (int)point[i].y;
////	}
////	cvLine(img, pt[0], pt[1], CV_RGB(255, 0, 0), 2, 8, 0);
////	cvLine(img, pt[1], pt[2], CV_RGB(255, 0, 0), 2, 8, 0);
////	cvLine(img, pt[2], pt[3], CV_RGB(255, 0, 0), 2, 8, 0);
////	cvLine(img, pt[3], pt[0], CV_RGB(255, 0, 0), 2, 8, 0);
////	return true;
////}
////
////int _tmain(int argc, _TCHAR* argv[])
////{
////	/*time_t MyTime;
////	time(&MyTime);
////	std::cout << MyTime;*/
////	CvMemStorage* storage = cvCreateMemStorage(0);
////	CvSeq *contour;
////	
////	IplImage* test= cvLoadImage("testError.jpg",CV_LOAD_IMAGE_ANYDEPTH); 
////	IplImage* result = cvCreateImage(cvGetSize(test), 8, 1);
////	ImageClean(test,  result);
////	cvErode(result, result);
////	cvErode(result, result);
////	cvErode(result, result);
////	IplImage* temp = cvCreateImage(cvGetSize(test), 8, 1);
////	cvCopy(result, temp);
////	cvThreshold(temp,temp,10,255,CV_THRESH_BINARY);
////	cvFindContours(temp, storage, &contour, sizeof(CvContour), CV_RETR_CCOMP, CV_CHAIN_APPROX_NONE);
////	while (contour)
////	{
////		double area = fabs(cvContourArea(contour, CV_WHOLE_SEQ));
////		if (area>3000)
////		{
////			CvBox2D get= cvMinAreaRect2(contour);
////			if (get.size.width / get.size.height>0.28&&get.size.width / get.size.height<0.38)
////			{
////				DrawBox(get, test);
////				std::cout << get.size.height << std::endl;
////			}
////			if (get.size.height / get.size.width>0.28&&get.size.height / get.size.width<0.38)
////			{
////				DrawBox(get, test);
////				std::cout << get.size.width << std::endl;
////			}
////		}
////		contour = contour->h_next;
////	}
////	cvShowImage("test",test);
////	cvWaitKey(0);
////	cvReleaseImage(&test);
////	cvReleaseImage(&result);
////	cvReleaseImage(&temp);
////
////
////	system("pause");
////	return 0;
////}
//template<class T> bool ReadData(char* path, T* input, int length)
//{
//	int i = 0;
//	if (path==0||input==0||length<1)
//	{
//		return 0;
//	}
//	std::ifstream Fread(path);
//	
//	for ( i = 0; i < length; i++)
//	{
//		Fread >> input[i];
//	}
//	Fread.close();
//	return 1;
//}
//template<class T> bool SaveData(char* path, T* input, int length)
//{
//	int i = 0;
//	if (path == 0 || input == 0 || length<1)
//	{
//		return 0;
//	}
//	std::ofstream Fread(path);
//
//	for (i = 0; i < length; i++)
//	{
//		Fread << input[i]<<'\n';
//	}
//	Fread.close();
//	return 1;
//}
//int _tmain(int argc, _TCHAR* argv[])
//{
//	unsigned int i = 0;
//	unsigned int j = 0;
////	float test[198];
////	memset(test, 0, 198 * 4);
////	ReadData("ccd1.txt", test, 198);
//	//读入相位点
//	//读入方式：
//	//x1,x2,x3,x4
//	//y1,y2,y3,y4
//	//u1,u2,u3,u4
//	//v1,v2,v3,v4
//	//矫正点，,x,y
//	//输入为已经矫正点
//	//start！
//	CvMat* CCDPoint = cvCreateMat(99*4,2,CV_32F);
//	CvMat* DLPPoint = cvCreateMat(99 * 4, 2, CV_32F);
//	CvMat* CCD = cvCreateMat(99, 2, CV_32F);
//	CvMat* Correct = cvCreateMat(99, 2, CV_32F);
//	CvMat* Matrix = cvCreateMat(3, 3, CV_32F);
//
//	memset(CCDPoint->data.fl, 0, 99 * 8 * 4);
//	memset(DLPPoint->data.fl, 0, 99 * 8 * 4);
//	memset(CCD->data.fl, 0, 99*2  * 4);
//	memset(Correct->data.fl, 0, 99 * 2 * 4);
//	cvZero(Matrix);
//
//	ReadData("CCD4.txt", CCDPoint->data.fl, 99 * 4 * 2);
//	ReadData("DLP4.txt", DLPPoint->data.fl, 99 * 4 * 2);
//	ReadData("4ccd.txt", CCD->data.fl, 99 * 2);
//	
//	for ( i = 0; i < 99; i++)
//	{
//		CvPoint2D32f* Camera = new CvPoint2D32f[4];
//		CvPoint2D32f* Projector = new CvPoint2D32f[4];
//		for ( j = 0; j < 4; j++)
//		{
//			Camera[j].x = CV_MAT_ELEM(*CCDPoint,float, 4 * i + j, 0);
//			Camera[j].y = CV_MAT_ELEM(*CCDPoint, float, 4 * i + j, 1);
//			Projector[j].x = CV_MAT_ELEM(*DLPPoint, float, 4 * i + j, 0);
//			Projector[j].y = CV_MAT_ELEM(*DLPPoint, float, 4 * i + j, 1);
//		}
//		cvGetPerspectiveTransform(Camera,Projector,Matrix);
//		CvMat* two = cvCreateMat(1, 1, CV_32FC2);
//		CvMat* temp = cvCreateMat(1, 1, CV_32FC2);
//		two->data.fl[0] = CV_MAT_ELEM(*CCD, float, i, 0);
//		two->data.fl[1] = CV_MAT_ELEM(*CCD, float, i, 1);
//		cvPerspectiveTransform(two,temp , Matrix);
//
//		CV_MAT_ELEM(*Correct, float, i, 0) = temp->data.fl[0]/3.1415926/76*912;
//		CV_MAT_ELEM(*Correct, float, i, 1) = temp->data.fl[1]/3.1415926/60*570;
//
//		cvReleaseMat(&temp);
//		cvReleaseMat(&two);
//		delete[] Projector;
//		delete []Camera;
//	}
//
//	SaveData("correct4.txt", Correct->data.fl, 99 * 2);
//	cvReleaseMat(&CCDPoint);
//	cvReleaseMat(&DLPPoint);
//	cvReleaseMat(&CCD);
//	return 0;
//}
//int _tmain(int argc, char** argv)
//{
//	IplImage* img = NULL;
//	char path=0;
//	if (argc>1)
//	{
//		//		std::cout << strlen(argv[0]) << std::endl;
//		//		printf("%s\n", argv[1]);
//		memcpy(&path, argv[1], 1);
//	}
//	else
//	{
//		return 0;
//	}
//	if (path=='0')
//	{
//		img = cvLoadImage("test0.png");
//	}
//	if (path == '1')
//	{
//		 img = cvLoadImage("test1.png");
//	}
//	
//	IplImage* copy = cvCreateImage(cvGetSize(img), 8, 1);
////	IplImage* copy1 = cvCreateImage(cvGetSize(img), 8, 1);
//	CvMemStorage *storage = cvCreateMemStorage();
//	CvSeq *contour;
//	cvZero(copy);
//	int num = 0; 
////	cvZero(copy1);
//	for (size_t i = 0; i < img->height; i++)
//	{
//		for (size_t j = 0; j < img->width; j++)
//		{
//			if ((uchar)img->imageData[img->widthStep*i + img->nChannels*j] - (uchar)img->imageData[img->widthStep*i + img->nChannels*j+1]<30 
//				&& (uchar)img->imageData[img->widthStep*i + img->nChannels*j]>150 && (uchar)img->imageData[img->widthStep*i + img->nChannels*j+2]<200)
//			{
//				copy->imageData[i*copy->widthStep + j*copy->nChannels] = 255;
//			}
//		}
//	}
//	cvDilate(copy, copy);
//	cvDilate(copy, copy);
//	cvErode(copy, copy);
//	cvDilate(copy, copy);
//	cvErode(copy, copy);
//	cvDilate(copy, copy);
//	cvErode(copy, copy);
//	
//	cvFindContours(copy, storage, &contour, sizeof(CvContour), CV_RETR_CCOMP, CV_CHAIN_APPROX_NONE);
//	cvZero(copy);
//	while (contour)
//	{
//		CvBox2D box = cvMinAreaRect2(contour);
//		if (box.size.height / box.size.width > 3|| box.size.height / box.size.width < 0.33)
//		{
//			cvDrawContours(copy, contour, CV_RGB(255, 255, 255), CV_RGB(255, 255, 255), 0, CV_FILLED, 8, cvPoint(0, 0));
//		}
//		contour = contour->h_next;
//	}
//	for (size_t i = 0; i < copy->height*copy->width; i++)
//	{
//		if ((uchar)copy->imageData[i])
//		{
//			num++;
//		}
//	}
//	std::cout << num << std::endl;
//	if (num>50)
//	{
//		std::cout << "产品不合格！" << std::endl;
//	}
//	else
//	{
//		std::cout << "产品合格！" << std::endl;
//	}
//	cvShowImage("Raw", img);
//	cvShowImage("Real", copy);
//	cvWaitKey(0);
//	cvReleaseMemStorage(&storage);
//	cvReleaseImage(&img);
//	cvReleaseImage(&copy);
//
//	return 0;
//}
bool PrintContour(char* path,CvSeq* countour);
bool AutoCanny(IplImage* src, IplImage* dst, float thresh);
bool SaveMat(char* path, CvMat* Mat,uchar flag);
bool DrawBox(CvBox2D box, IplImage* img);
CvBox2D CheckMate(CvSeq* contour, IplImage* src);
float PointFilter(int x, int y, IplImage* src, CvMat* mat);
CvPoint2D32f GetTrueBorder(CvPoint point, IplImage* src,CvMat* sobelx,CvMat* sobely);
bool GetIndex(CvMat* index, CvBox2D* Ellipse, int num);
float GetPointLength(CvPoint2D32f pt1, CvPoint2D32f pt2)
{
	return sqrt((pt1.x - pt2.x)*(pt1.x - pt2.x) + (pt1.y - pt2.y)*(pt1.y - pt2.y));
}
bool ShowPoint(IplImage* Draw, CvBox2D* Ellipse, CvMat* Index);
bool SaveEllipse(char* path, CvBox2D *ellipse, int num);
std::complex<double> sqrtn(const std::complex<double>&x, double n);
void Ferrari(std::complex<double> x[4]
	, std::complex<double> a
	, std::complex<double> b
	, std::complex<double> c
	, std::complex<double> d
	, std::complex<double> e);
std::vector<double> BoxEllipseConvert(CvBox2D Elli);
bool EllipseSharedTang(std::vector<double> Elli1,std::vector<double> Elli2,CvMat* line);

//the difficulty is the fear itself
int _tmain(int argc, char** argv)
{
	IplImage* raw = cvLoadImage("n14.jpg", CV_LOAD_IMAGE_ANYDEPTH);
	IplImage* Bin = cvCreateImage(cvGetSize(raw), 8, 1);
	IplImage* dst = cvCreateImage(cvGetSize(raw), 8, 1);
	char path[32];
	int i = 0, j = 0;
	uint32_t cnt=0;
	cvSmooth(raw, raw);
	cvThreshold(raw, Bin, 38, 255, CV_THRESH_BINARY);
	AutoCanny(raw, dst, 0.98);
	cvShowImage("show", Bin);
	cvWaitKey(0);
	// get the contour of thresh
	CvSeq* BinThresh = NULL;
	CvSeq* CannyThresh = NULL;
	CvMemStorage *storage = cvCreateMemStorage(0);
	cvFindContours(Bin, storage, &BinThresh, 88, CV_RETR_CCOMP, CV_CHAIN_APPROX_NONE);
	cvFindContours(dst, storage, &CannyThresh, 88, CV_RETR_CCOMP, CV_CHAIN_APPROX_NONE);
	cvCopy(raw, Bin);

	CvSeq* loop = NULL;
	loop = BinThresh;
	CvBox2D Box;
	CvBox2D Ellipse[99];
	memset(Ellipse, 0, sizeof(CvBox2D));
	while (loop)
	{
		Box = cvMinAreaRect2(loop, storage);
		if (Box.size.height*Box.size.width>36 && Box.size.height*Box.size.width<1500)
		{
			float rate = Box.size.height / Box.size.width;
			if (rate<1.8&&rate>0.6)
			{
				//sprintf(path, "Bin%d%d.txt", (int)Box.center.x, (int)Box.center.y);
				//PrintContour(path, loop);

				cnt++;
			}
		}
		loop = loop->h_next;
	}
	cnt = 0;
	loop = BinThresh;
	while (loop)
	{
		Box = cvMinAreaRect2(loop, storage);
		if (Box.size.height*Box.size.width>36 && Box.size.height*Box.size.width<1500)
		{
			float rate = Box.size.height / Box.size.width;
			if (rate<1.8&&rate>0.6)
			{
				//sprintf(path, "Bin%d%d.txt", (int)Box.center.x, (int)Box.center.y);
				//PrintContour(path, loop);
				Ellipse[cnt] = CheckMate(loop, raw);
				DrawBox(Ellipse[cnt], Bin);
				cnt++;
			}
		}
		loop = loop->h_next;
	}
	
	CvMat* Mat = cvCreateMat(9,11,CV_8SC2);
	GetIndex(Mat, Ellipse, 99);
	SaveEllipse("ellipse.txt", Ellipse, 99);
	CvBox2D test,test2;
	test.center.x = test.center.y = 3;
	test.size.height = 2;
	test.size.width = 4;
	test.angle = 45;

	test2.center.x = test2.center.y = -3;
	test2.size.height = 2;
	test2.size.width = 4;
	test2.angle = 45;
	std::vector<double> E1, E2;
	E1 = BoxEllipseConvert(test);
	E2 = BoxEllipseConvert(test2);
	EllipseSharedTang(E1, E2, NULL);

	IplImage *color = cvCreateImage(cvGetSize(Bin), 8, 3);
	cvConvertImage(Bin, color, CV_GRAY2BGR);
	ShowPoint(color, Ellipse, Mat);
	std::cout << "point sum is " << cnt << '\n';
	cvShowImage("show", color);
	cvWaitKey(0);

	cnt = 0;
	loop = CannyThresh;
	while (loop)
	{
		Box = cvMinAreaRect2(loop, storage);
		if (Box.size.height*Box.size.width>36 && Box.size.height*Box.size.width<1500)
		{
			float rate = Box.size.height / Box.size.width;
			if (rate<1.7&&rate>0.6)
			{
				//sprintf(path, "Can%d%d.txt", (int)Box.center.x, (int)Box.center.y);
				//PrintContour(path, loop);
				DrawBox(Box, dst);
				cnt++;
			}
		}
		loop = loop->h_next;
	}
	std::cout << "point sum is " << cnt << '\n';
	cvShowImage("show", dst);

	cvWaitKey(0);
	cvReleaseMemStorage(&storage);
	cvReleaseImage(&raw);
	cvReleaseImage(&dst);
	cvReleaseImage(&Bin);
	cvReleaseImage(&color);
	//测试费拉里法
	//std::complex<double> x[4];
	//std::complex<double> x1(1.0, 0.0); //随便填
	//std::complex<double> x2(2.0, 0.0); //随便填
	//std::complex<double> x3(3.0, 0.0); //随便填
	//std::complex<double> x4(4.0, 0.0); //随便填
	//std::complex<double> a(1.0, 0.0); //随便填(不为零即可)
	//std::complex<double> b = a * (-x1 - x2 - x3 - x4);
	//std::complex<double> c = a * (x1 * x2 + x1 * x3 + x1 * x4 + x2 * x3 + x2 * x4 + x3 * x4);
	//std::complex<double> d = a * (-x2 * x3 * x4 - x1 * x3 * x4 - x1 * x2 * x4 - x1 * x2 * x3);
	//std::complex<double> e = a * (x1 * x2 * x3 * x4);
	//Ferrari(x, a, b, c, d, e); //验证费拉里法
	return 0;
}
bool AutoCanny(IplImage* src,IplImage* dst,float thresh)
{
	if (src==NULL||dst==NULL)
	{
		return false;
	}
	int i=0, j=0;
	CvMat* dx = cvCreateMat(dst->height, dst->width, CV_32F);
	CvMat* dy = cvCreateMat(dst->height, dst->width, CV_32F);
	CvMat* grad = cvCreateMat(dst->height, dst->width, CV_32F);
	uint32_t check[64];
	float max=0;
	uint32_t cnt = 0;
	memset(check, 0, 64 * 4);
	cvSobel(src, dx, 1, 0);
	cvSobel(src, dy, 0, 1);
	for (i = 0; i <grad->height; i++)
	{
		for (j = 0; j <grad->width; j++)
		{
			grad->data.fl[i*grad->width + j] =
				sqrt(dx->data.fl[i*grad->width + j] * dx->data.fl[i*grad->width + j]
				+ dy->data.fl[i*grad->width + j] * dy->data.fl[i*grad->width + j]);
		}
	}
	for (i = 0; i < grad->height*grad->width; i++)
	{
		max=MAX(max,grad->data.fl[i]);
	}
	for (i = 0; i <grad->height*grad->width; i++)
	{
		check[(uint32_t)(grad->data.fl[i] / (max + 1) * 64)]++;
	}
	for ( i = 0; i < 64; i++)
	{
		cnt = cnt + check[i];
		if (cnt>grad->height*grad->width*thresh)
		{
			break;
		}
	}
	cvCanny(src, dst, i  * max / 64, i  * max / 128);
	cvReleaseMat(&dx);
	cvReleaseMat(&dy);
	cvReleaseMat(&grad);
	return true;

}
bool DrawBox(CvBox2D box, IplImage* img)
{
	if (img==NULL)
	{
		return false;
	}
	CvPoint2D32f point[4];
	int i;
	for (i = 0; i<4; i++)
	{
		point[i].x = 0;
		point[i].y = 0;
	}
	cvBoxPoints(box, point); //计算二维盒子顶点
	CvPoint pt[4];
	for (i = 0; i<4; i++)
	{
		pt[i].x = (int)point[i].x;
		pt[i].y = (int)point[i].y;
	}
	cvLine(img, pt[0], pt[1], CV_RGB(255, 255, 255), 1, 8, 0);
	cvLine(img, pt[1], pt[2], CV_RGB(255, 255, 255), 1, 8, 0);
	cvLine(img, pt[2], pt[3], CV_RGB(255, 255, 255), 1, 8, 0);
	cvLine(img, pt[3], pt[0], CV_RGB(255, 255, 255), 1, 8, 0);
	return true;
}
bool PrintContour(char* path, CvSeq* contour)
{
	if (path==NULL||contour==NULL)
	{
		return false;
	}
	std::ofstream output(path);
	int i = 0, j = 0;
	CvPoint* point = NULL;
	for (size_t i = 0; i < contour->total; i++)
	{
		point = (CvPoint*)cvGetSeqElem(contour,i);
		output << point->x << '\t' << point->y << '\n';
	}
	output.close();
	return true;
}
CvBox2D CheckMate(CvSeq* contour, IplImage* src)
{
	if (contour==NULL&&src==NULL)
	{
		CvBox2D Nbox;
		memset(&Nbox, 0, sizeof(CvBox2D));
		return Nbox;
	}
	//get the Real Contour

	int i = 0, j = 0;
	CvBox2D Box;
	Box = cvFitEllipse2(contour);
//	DrawBox(Box, src);
//	cvShowImage("show", src);
//	cvWaitKey(0);
	CvPoint2D32f point[4];
	cvBoxPoints(Box, point);
	
	//get the max 
	unsigned int HMax, HMin, WMax, WMin;
	HMax = HMin = point[0].y;
	WMax = WMin = point[0].x;
	for ( i = 0; i < 4; i++)
	{
		HMax = MAX(point[i].y, HMax);
		HMin = MIN(point[i].y, HMin);
		WMax = MAX(point[i].x, WMax);
		WMin = MIN(point[i].x, WMin);
	}
	CvSize TempSize;
	TempSize.height = HMax - HMin + 8;
	TempSize.width = WMax - WMin + 8;
	
	IplImage* CutOff = cvCreateImage(TempSize, 8, 1);
	IplImage* Canny = cvCreateImage(TempSize, 8, 1);
	cvZero(CutOff);
	CvPoint Differ;
	Differ.x = WMin - 4;
	Differ.y = HMin - 4;

	//put in the cutoff picture
	for (i = 0; i < TempSize.height; i++)
	{
		for ( j = 0; j < TempSize.width; j++)
		{

			CutOff->imageData[i*CutOff->widthStep + j] =
				src->imageData[(Differ.y + i)*src->widthStep + j + Differ.x];
		}
	}


	AutoCanny(CutOff, Canny, 0.9);
	
	CvBox2D RealBox;
	CvSeq* head=NULL;
	CvMemStorage* storage = cvCreateMemStorage(0);
	cvFindContours(Canny, storage, &head, 88, CV_RETR_CCOMP, CV_CHAIN_APPROX_NONE);
	CvSeq* loop = NULL;
	loop = head;
	CvMat* sobelx = cvCreateMat(CutOff->height, CutOff->width, CV_16S);
	CvMat* sobely = cvCreateMat(CutOff->height, CutOff->width, CV_16S);
	CvPoint2D32f* AccuratePoint;
	cvSobel(CutOff, sobelx, 1, 0);
	cvSobel(CutOff, sobely, 0, 1);
	int size = 0;
	CvSeq* SaveContour = NULL;
	while (loop)
	{
		RealBox = cvMinAreaRect2(loop, storage);
		if (RealBox.size.height*RealBox.size.width>(Box.size.height)*(Box.size.width)*0.7)
		{
			AccuratePoint = new CvPoint2D32f [loop->total];
			size = loop->total;
			for ( i = 0; i < loop->total; i++)
			{				
				CvPoint* TempPoint = (CvPoint*)cvGetSeqElem(loop, i);
				SaveContour = loop;
				AccuratePoint[i]= GetTrueBorder(*TempPoint, CutOff,sobelx,sobely);
			}
		}
		loop = loop->h_next;

	}
	
	/*std::ofstream temp("Real.txt");
	for ( i = 0; i < size; i++)
	{
		temp << AccuratePoint[i].x << '\t' << AccuratePoint[i].y << '\n';
	}
	temp.close();
	temp.open("Canny.txt");
	for (i = 0; i < size; i++)
	{
		CvPoint* out = (CvPoint*)cvGetSeqElem(SaveContour, i);
		temp << out->x << '\t' << out->y << '\n';
	}
	temp.close();
	cvShowImage("differ", Canny);
	cvWaitKey(0);*/
	if (SaveContour==NULL)
	{
		cvShowImage("show",Canny);
		cvWaitKey(0);
	}
	CvMat* Ellipse = cvCreateMat(SaveContour->total, 2, CV_32F);

	for (i = 0; i < SaveContour->total; i++)
	{
		Ellipse->data.fl[i * 2] = AccuratePoint[i].x;
		Ellipse->data.fl[i * 2+1] = AccuratePoint[i].y;

	}
	
	CvBox2D output;

	output=cvFitEllipse2(Ellipse);
	output.center.x = output.center.x + Differ.x;
	output.center.y = output.center.y + Differ.y;

	//debuging for ellipse fitting
	char path[32];
	memset(path, 0, 32);
	for (i = 0; i < SaveContour->total; i++)
	{
		Ellipse->data.fl[i * 2] = Ellipse->data.fl[i * 2] + Differ.x;
		Ellipse->data.fl[i * 2 + 1] = Ellipse->data.fl[i * 2+1] + Differ.y;

	}
	sprintf(path, "D:\\Ellipse\\%d%d.txt", (int)output.center.x, (int)output.center.y);
	SaveMat(path, Ellipse,CV_32F);




	//


	delete []AccuratePoint;
	cvReleaseMat(&Ellipse);
	cvReleaseMat(&sobelx);
	cvReleaseMat(&sobely);
	cvReleaseImage(&CutOff);
	cvReleaseImage(&Canny);
	return output;
}
CvPoint2D32f GetTrueBorder(CvPoint point, IplImage* src,CvMat* sobelx,CvMat* sobely)
{
//	cvSaveImage("src.jpg", src);

	CvPoint2D32f output;
	output.x = 0;
	output.y = 0;
	int i = 0, j = 0;
	
	//new method : try the length
	float keep[7];
	memset(keep, 0, 7 * 4);
	float differ[5];
	memset(differ, 0, 4 * 5);
	//now get the filter 
	CvPoint index;
	float theta = atan2f((float)sobely->data.s[point.y*sobely->width + point.x] ,(float) sobelx->data.s[point.y*sobelx->width + point.x]);
	for ( i = 0; i < 7; i++)
	{
		
		
		index.x = floor((i - 3)*cos(theta) + point.x);
		index.y = floor((i - 3)*sin(theta) + point.y);
		keep[i] = (uchar)src->imageData[index.y*src->widthStep+index.x];
		/*float diffx = ((i - 3)*cos(theta) - (int)((i - 3)*cos(theta)))*
			(cvGet2D(src, index.y, index.x + 1).val[0] - cvGet2D(src, index.y, index.x).val[0]);
		float diffy = ((i - 3)*sin(theta) - (int)((i - 3)*sin(theta)))*
			(cvGet2D(src, index.y+1, index.x ).val[0] - cvGet2D(src, index.y, index.x).val[0]);*/
		float diffx = ((i - 3)*cos(theta) - floor((i - 3)*cos(theta)))*
				((uchar)src->imageData[index.y*src->widthStep + index.x + 1] - (uchar)src->imageData[index.y*src->widthStep + index.x]);
		float diffy = ((i - 3)*sin(theta) - floor((i - 3)*sin(theta)))*
			((uchar)src->imageData[(index.y+1)*src->widthStep + index.x] - (uchar)src->imageData[index.y*src->widthStep + index.x]);
		keep[i] = diffx + diffy + keep[i];
	}

	
	//	cvShowImage("temp", src);
//	cvWaitKey(0);
	//say fuck you to the grad
	
	for ( i = 0; i <5 ; i++)
	{
		differ[i] = (keep[i +2] - keep[i])/2;
	}
	for ( i = 0; i <5; i++)
	{
		if (differ[i]<0)
		{
			differ[i] = 0.5;
		}
	}
	float fxx = (float)((0.1 * log(differ[0]) + 0.05 * log(differ[1]) - 0.05 * log(differ[3]) - 0.1 * log(differ[4]))
		/ (0.1429 * log(differ[0]) - 0.0714 * log(differ[1]) - 0.1429 * log(differ[2]) - 0.0714 * log(differ[3]) + 0.1429 * log(differ[4])));
	output.x = point.x + cos(theta)*fxx;
	output.y = point.y + sin(theta)*fxx;
 	return output;
}

float PointFilter(int x, int y, IplImage* src, CvMat* mat)
{
	float end=0;
	int i = 0, j = 0;
	for ( i = 0; i < mat->height; i++)
	{
		for (j = 0; j < mat->width; j++)
		{
			end = end + src->imageData[(i + y - mat->height / 2)* src->widthStep + (j + x - mat->width / 2)]
				* mat->data.fl[i*mat->width + j];
		}
	}
	return end;
}
bool GetIndex(CvMat* index, CvBox2D* Ellipse, int num)
{
	if (index==NULL&&Ellipse==NULL)
	{
		return false;
	}
	int i = 0, j = 0,k=0;
	//the mat is 9X11
	//get the four point
	//first get the BIG Five(Seven)
	
	CvPoint2D32f Big[5];
	float BigArea[5];
	memset(BigArea, 0, 4 * 5);
	memset(Big, 0, sizeof(CvPoint2D32f));
	Big[0] = Big[1] = Big[2] = Big[3] = Big[4]=Ellipse[0].center;
	BigArea[0] = BigArea[0] = BigArea[0] = BigArea[0] = BigArea[0]
		=Ellipse[i].size.height*Ellipse[i].size.width;
	for ( i = 0; i < 99; i++)
	{
		for ( j = 0; j < 5; j++)
		{
			float area= Ellipse[i].size.height*Ellipse[i].size.width;
			if (area>BigArea[j])
			{
				for (k = 4; k > j;k--)
				{
					BigArea[k] = BigArea[k - 1];
					Big[k] = Big[k - 1];
				}
				BigArea[j] = area;
				Big[j] = Ellipse[i].center;
				break;
			}
		}
	}
	
	//use this five big point to confirm the middle of the plate
	//get the shortest point pair
	CvPoint2D32f Pair[2];
	float MinLength = sqrt((Big[0].x - Big[1].x)*(Big[0].x - Big[1].x)
		+ (Big[0].y - Big[1].y)*(Big[0].y - Big[1].y));
	memset(Pair, 0, sizeof(CvPoint2D32f)*2);
	for ( i = 0; i < 5; i++)
	{
		for (j = i+1; j < 5; j++)
		{
			float TempLength = sqrt((Big[i].x - Big[j].x)*(Big[i].x - Big[j].x)
				+ (Big[i].y - Big[j].y)*(Big[i].y - Big[j].y));
			if (TempLength<MinLength)
			{
				MinLength = TempLength;
				Pair[0] = Big[i];
				Pair[1] = Big[j];
			}
		}
	}
	//find the plate center
	
	CvPoint2D32f lPair[2];
	memset(lPair,0,sizeof(CvPoint2D32f)*2);
	float MaxCosAngle = 0;
	for (i = 0; i < 5; i++)
	{
		for (j = i + 1; j < 5; j++)
		{
			float TempLength = sqrt((Big[i].x - Big[j].x)*(Big[i].x - Big[j].x)
				+ (Big[i].y - Big[j].y)*(Big[i].y - Big[j].y));
			if (TempLength==MinLength)
			{ 
				continue;
			}
			CvPoint2D32f Vector;
			Vector.x = Big[i].x - Big[j].x;
			Vector.y = Big[i].y - Big[j].y;
			CvPoint2D32f Vpair;
			Vpair.x = Pair[0].x - Pair[1].x;
			Vpair.y = Pair[0].y - Pair[1].y;
			float CosAngle = (Vector.x*Vpair.x + Vector.y*Vpair.y)/MinLength/TempLength;
			if (MaxCosAngle<abs(CosAngle))
			{
				MaxCosAngle = abs(CosAngle);
				lPair[0] = Big[i];
				lPair[1] = Big[j];
			}

		}
	}
	//plate rough= (lPair1+lPair)/2
	CvPoint2D32f PlateRoughMiddle;
	PlateRoughMiddle.x = (lPair[0].x + lPair[1].x) / 2;
	PlateRoughMiddle.y = (lPair[0].y + lPair[1].y) / 2;


	CvPoint2D32f LeftUp, Leftdown, RightUp, RightDown;
	LeftUp = Leftdown = RightUp = RightDown = Ellipse[0].center;
	float LeftDownMax = 0, RightDownMax = 0, LeftUpMax = 0, RightUpMax = 0;
	for ( i = 0; i < num; i++)
	{
		
		if (Ellipse[i].center.x<PlateRoughMiddle.x&&Ellipse[i].center.y<PlateRoughMiddle.y)
		{
			float TempLength = sqrt((Ellipse[i].center.x - PlateRoughMiddle.x)
				*(Ellipse[i].center.x - PlateRoughMiddle.x) +
				(Ellipse[i].center.y - PlateRoughMiddle.y)*
				(Ellipse[i].center.y - PlateRoughMiddle.y));
			if (TempLength>LeftUpMax)
			{
				LeftUpMax = TempLength;
				LeftUp.x = Ellipse[i].center.x;
				LeftUp.y = Ellipse[i].center.y;

			}
		}
		if (Ellipse[i].center.x>PlateRoughMiddle.x&&Ellipse[i].center.y<PlateRoughMiddle.x)
		{
			float TempLength = sqrt((Ellipse[i].center.x - PlateRoughMiddle.x)
				*(Ellipse[i].center.x - PlateRoughMiddle.x) +
				(Ellipse[i].center.y - PlateRoughMiddle.y)*
				(Ellipse[i].center.y - PlateRoughMiddle.y));
			if (TempLength>RightUpMax)
			{
				RightUpMax = TempLength;
				RightUp.x = Ellipse[i].center.x;
				RightUp.y = Ellipse[i].center.y;
			}
		}
		if (Ellipse[i].center.x<PlateRoughMiddle.x&&Ellipse[i].center.y>PlateRoughMiddle.x)
		{
			float TempLength = sqrt((Ellipse[i].center.x - PlateRoughMiddle.x)
				*(Ellipse[i].center.x - PlateRoughMiddle.x) +
				(Ellipse[i].center.y - PlateRoughMiddle.y)*
				(Ellipse[i].center.y - PlateRoughMiddle.y));
			if (TempLength>LeftDownMax)
			{
				LeftDownMax = TempLength;
				Leftdown.x = Ellipse[i].center.x;
				Leftdown.y = Ellipse[i].center.y;

			}
		}
		if (Ellipse[i].center.x>PlateRoughMiddle.x&&Ellipse[i].center.y>PlateRoughMiddle.x)
		{
			float TempLength = sqrt((Ellipse[i].center.x - PlateRoughMiddle.x)
				*(Ellipse[i].center.x - PlateRoughMiddle.x) +
				(Ellipse[i].center.y - PlateRoughMiddle.y)*
				(Ellipse[i].center.y - PlateRoughMiddle.y));
			if (TempLength>RightDownMax)
			{
				RightDownMax = TempLength;
				RightDown.x = Ellipse[i].center.x;
				RightDown.y = Ellipse[i].center.y;

			}
		}
		
	}

	CvPoint2D32f PlatePt[4];
	PlatePt[0].x = 0;
	PlatePt[0].y = 0;
	PlatePt[1].x = 10;
	PlatePt[1].y = 0;
	PlatePt[2].x = 0;
	PlatePt[2].y = 8;
	PlatePt[3].x = 10;
	PlatePt[3].y = 8;

	CvPoint2D32f PicPt[4];
	PicPt[0] = LeftUp;
	PicPt[1] = RightUp;
	PicPt[2] = Leftdown;
	PicPt[3] = RightDown;
	
	CvMat* PerpMat = cvCreateMat(3, 3, CV_32F);
	cvGetPerspectiveTransform(PlatePt, PicPt, PerpMat);
	CvMat* PerpPlatePoint = cvCreateMat(9, 11, CV_32FC2);
	CvMat* PerpRealPoint = cvCreateMat(9, 11, CV_32FC2);

	for ( i = 0; i < 9; i++)
	{
		for ( j = 0; j < 11; j++)
		{
			PerpPlatePoint->data.fl[2 * (i * 11 + j)] = j;
			PerpPlatePoint->data.fl[2 * (i * 11 + j) + 1] = i;
		}
	}
	cvPerspectiveTransform(PerpPlatePoint, PerpRealPoint, PerpMat);

	for ( i = 0; i < 99; i++)
	{
		float length = 400;
		CvPoint2D32f pt1;
		CvPoint2D32f pt2;
		for (j = 0; j < 99; j++)
		{
			
			pt1.x = PerpRealPoint->data.fl[2 * (j)];
			pt1.y = PerpRealPoint->data.fl[2 * (j)+1];
			pt2= Ellipse[i].center;
			if (length>GetPointLength(pt1, pt2))
			{
				length = GetPointLength(pt1, pt2);
				index->data.ptr[2 * i] = PerpPlatePoint->data.fl[2 * j];
				index->data.ptr[2 * i+1] = PerpPlatePoint->data.fl[2 * j+1];
			}
			
		}
		std::cout << length << '\n';
	}
	cvReleaseMat(&PerpRealPoint);
	cvReleaseMat(&PerpPlatePoint);
	cvReleaseMat(&PerpMat);
	return true;
}
bool ShowPoint(IplImage* Draw, CvBox2D* Ellipse, CvMat* Index)
{
	CvFont Font;
	int i = 0, j = 0;
	if (Draw->nChannels!=3)
	{
		return false;
	}
	cvInitFont(&Font, CV_FONT_HERSHEY_SIMPLEX, 0.5, 0.5);
	char Text[32];
	memset(Text, 0, 32);
	for ( i = 0; i < 99; i++)
	{
		memset(Text, 0, 32);
		sprintf(Text, "%d,%d", (int)Index->data.ptr[2 * i], (int)Index->data.ptr[2 * i + 1]);
		CvPoint cut = cvPoint((int)Ellipse[i].center.x, (int)Ellipse[i].center.y);
		cvPutText(Draw, Text, cut, &Font, CV_RGB(255, 0, 0));
		DrawBox(Ellipse[i], Draw);
	}
	return true;
}
bool SaveEllipse(char* path,CvBox2D* ellipse, int num)
{
	if (ellipse==NULL)
	{
		return false;
	}
	std::ofstream OutPut(path);
	int i = 0, j = 0;
	for ( i = 0; i < num; i++)
	{
		OutPut << ellipse[i].center.x << '\t';
		OutPut << ellipse[i].center.y << '\t';
		OutPut << ellipse[i].size.height << '\t';
		OutPut << ellipse[i].size.width << '\t';
		OutPut << ellipse[i].angle << '\t';
		OutPut << '\n';
	}
	OutPut.close();
	return true;
}
bool SaveMat(char* path, CvMat* Mat,uchar flag)
{
	std::ofstream Out(path);
	if (Out.fail())
	{
		return false;
	}
	int i = 0, j = 0;
	for ( i = 0; i < Mat->height; i++)
	{
		for ( j = 0; j < Mat->width; j++)
		{
			if (flag==CV_32F)
			{
				Out << Mat->data.fl[i*Mat->width + j]<<'\t';
			}
		}
		Out << '\n';
	}
	Out.close();
	return true;
}
std::complex<double> sqrtn(const std::complex<double>&x, double n)
{
	double r = _hypot(x.real(), x.imag()); //模
	if (r > 0.0)
	{
		double a = atan2(x.imag(), x.real()); //辐角
		n = 1.0 / n;
		r = pow(r, n);
		a *= n;
		return std::complex<double>(r * cos(a), r * sin(a));
	}
	return std::complex<double>();
}
/******************************************************************************\
使用费拉里法求解一元四次方程 a*x^4 + b*x^3 + c*x^2 + d*x + e = 0
\******************************************************************************/
void Ferrari(std::complex<double> x[4]
	, std::complex<double> a
	, std::complex<double> b
	, std::complex<double> c
	, std::complex<double> d
	, std::complex<double> e)
{
	a = 1.0 / a;
	b *= a;
	c *= a;
	d *= a;
	e *= a;
	std::complex<double> P = (c * c + 12.0 * e - 3.0 * b * d) / 9.0;
	std::complex<double> Q = (27.0 * d * d + 2.0 * c * c * c + 27.0 * b * b * e - 72.0 * c * e - 9.0 * b * c * d) / 54.0;
	std::complex<double> D = sqrtn(Q * Q - P * P * P, 2.0);
	std::complex<double> u = Q + D;
	std::complex<double> v = Q - D;
	if (v.real() * v.real() + v.imag() * v.imag() > u.real() * u.real() + u.imag() * u.imag())
	{
		u = sqrtn(v, 3.0);
	}
	else
	{
		u = sqrtn(u, 3.0);
	}
	std::complex<double> y;
	if (u.real() * u.real() + u.imag() * u.imag() > 0.0)
	{
		v = P / u;
		std::complex<double> o1(-0.5, +0.86602540378443864676372317075294);
		std::complex<double> o2(-0.5, -0.86602540378443864676372317075294);
		std::complex<double>&yMax = x[0];
		double m2 = 0.0;
		double m2Max = 0.0;
		int iMax = -1;
		for (int i = 0; i < 3; ++i)
		{
			y = u + v + c / 3.0;
			u *= o1;
			v *= o2;
			a = b * b + 4.0 * (y - c);
			m2 = a.real() * a.real() + a.imag() * a.imag();
			if (0 == i || m2Max < m2)
			{
				m2Max = m2;
				yMax = y;
				iMax = i;
			}
		}
		y = yMax;
	}
	else
	{//一元三次方程，三重根
		y = c / 3.0;
	}
	std::complex<double> m = sqrtn(b * b + 4.0 * (y - c), 2.0);
	if (m.real() * m.real() + m.imag() * m.imag() >= DBL_MIN)
	{
		std::complex<double> n = (b * y - 2.0 * d) / m;
		a = sqrtn((b + m) * (b + m) - 8.0 * (y + n), 2.0);
		x[0] = (-(b + m) + a) / 4.0;
		x[1] = (-(b + m) - a) / 4.0;
		a = sqrtn((b - m) * (b - m) - 8.0 * (y - n), 2.0);
		x[2] = (-(b - m) + a) / 4.0;
		x[3] = (-(b - m) - a) / 4.0;
	}
	else
	{
		a = sqrtn(b * b - 8.0 * y, 2.0);
		x[0] =
			x[1] = (-b + a) / 4.0;
		x[2] =
			x[3] = (-b - a) / 4.0;
	}
}
std::vector<double> BoxEllipseConvert(CvBox2D Elli)
{
	std::vector<double> dst(6);
	Elli.size.height = Elli.size.height / 2;
	Elli.size.width = Elli.size.width / 2;
	Elli.angle = Elli.angle / 180  * CV_PI;
	int i = 0;
	dst[5] = (Elli.center.x*cos(Elli.angle) + Elli.center.y*sin(Elli.angle))*
		(Elli.center.x*cos(Elli.angle) + Elli.center.y*sin(Elli.angle)) / Elli.size.width / Elli.size.width;
	dst[5] = dst[5] + (Elli.center.x*sin(Elli.angle) - Elli.center.y*cos(Elli.angle))
		*(Elli.center.x*sin(Elli.angle) - Elli.center.y*cos(Elli.angle)) / Elli.size.height / Elli.size.height - 1;
	dst[0] = cos(Elli.angle)*cos(Elli.angle) / Elli.size.width / Elli.size.width;
	dst[0] = dst[0] + sin(Elli.angle)*sin(Elli.angle) / Elli.size.height/Elli.size.height;
	dst[2] = sin(Elli.angle)*sin(Elli.angle) / Elli.size.width / Elli.size.width;
	dst[2] = dst[2] + cos(Elli.angle)*cos(Elli.angle) / Elli.size.height / Elli.size.height;
	dst[1] = cos(Elli.angle)*sin(Elli.angle) * 2 / Elli.size.width / Elli.size.width;
	dst[1] = dst[1] - cos(Elli.angle)*sin(Elli.angle) * 2 / Elli.size.height/Elli.size.height;
	dst[3] = -(Elli.center.x*cos(Elli.angle) + Elli.center.y*sin(Elli.angle))*cos(Elli.angle) * 2
		/ Elli.size.width / Elli.size.width;
	dst[3] = dst[3] + sin(Elli.angle) * 2 * (Elli.center.y*cos(Elli.angle) - Elli.center.x*sin(Elli.angle)) 
		/ Elli.size.height / Elli.size.height;
	dst[4] = -(Elli.center.x*cos(Elli.angle) + Elli.center.y*sin(Elli.angle))*sin(Elli.angle) * 2
		/ Elli.size.width / Elli.size.width;
	dst[4] = dst[4] - cos(Elli.angle) * 2 * (Elli.center.y*cos(Elli.angle) - Elli.center.x*sin(Elli.angle)) 
		/ Elli.size.height / Elli.size.height;
	for ( i = 0; i < 6; i++)
	{
		dst[i] = dst[i] / dst[5];
	}
	return dst;
	
}
bool EllipseSharedTang(std::vector<double> Elli1, std::vector<double> Elli2, CvMat* line)
{
	std::complex<double> A1, B1, C1, D1, E1,F1;
	std::complex<double> A2, B2, C2, D2, E2,F2;
	int i = 0, j = 0;

	A1 = Elli1[4] * Elli1[4] - 4 * Elli1[2];
	B1 = Elli1[2] * Elli1[3] * 4 - 2 * Elli1[1] * Elli1[4];
	C1 = Elli1[1] * Elli1[1] - 4 * Elli1[0] * Elli1[2];
	D1 = Elli1[3] * Elli1[4]*2 - 4 * Elli1[1];
	E1 = Elli1[1] * Elli1[3]*2 - 4 * Elli1[0] * Elli1[4];
	F1 = Elli1[3] * Elli1[3] - 4 * Elli1[0];

	A2 = Elli2[4] * Elli2[4] - 4 * Elli2[2];
	B2 = Elli2[2] * Elli2[3] * 4 - 2 * Elli2[1] * Elli2[4];
	C2 = Elli2[1] * Elli2[1] - 4 * Elli2[0] * Elli2[2];
	D2 = Elli2[3] * Elli2[4]*2 - 4 * Elli2[1];
	E2 = Elli2[1] * Elli2[3]*2 - 4 * Elli2[0] * Elli2[4];
	F2 = Elli2[3] * Elli2[3] - 4 * Elli2[0];

	A1 = A1 / C1;
	B1 = B1 / C1;
	D1 = D1 / C1;
	E1 = E1 / C1;
	F1 = F1 / C1;
	C1 = C1 / C1;

	A2 = A2 / C2;
	B2 = B2 / C2;
	D2 = D2 / C2;
	E2 = E2 / C2;
	F2 = F2 / C2;
	C2 = C2 / C2;
	
	std::complex<double> k[4];
	std::complex<double> a, b, c, d, e;
	a = (A1 - A2)*(A1 - A2) - (B1 - B2)*(B1*A2 - B2*A1);
	b = 2.0 * (A1 - A2)*(D1 - D2) - (E1 - E2)*(B1*A2 - B2*A1)
		- (B1 - B2)*(B1*D2 - B2*D1+E1*A2-E2*A1);
	c = 2.0*(A1 - A2)*(F1 - F2)+(D1-D2)*(D1-D2) - (E1 - E2)*(B1*D2 - B2 *D1+E1*A2-E2*A1)
		-(B1-B2)*(B1*F2-B2*F1+E1*D2-E2*D1);
	d = 2.0*(D1 - D2)*(F1 - F2) - (E1 - E2)*(B1*F2 - B2*F1 + E1*D2 - E2*D1)
		-(B1-B2)*(E1*F2-E2*F1);
	e = (F1 - F2)*(F1 - F2) - (E1 - E2)*(E1*F2 - E2*F1);
	Ferrari(k, a, b, c, d, e);
	//费拉里大法吼！

	double RealK[4];
	memset(RealK, 0, 16);
	
	for ( i = 0; i < 4; i++)
	{
		RealK[i] = k[i].real();
	}
	//下一步 知道K求两椭圆的切线
	//B<=1%时承认一样
	//谁特么会把你带进二元二次方程组里继续求啊！

	return true;
}