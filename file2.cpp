#include <highgui.hpp>
#include<opencv2/opencv.hpp>
//#include <load_image.h>
using namespace std;
using namespace cv;

int main()
{
  VideoCapture camera;
  int camerNumber=0;
  camera.open(cameraNumber);
  Mat bgr;
  Mat edges;
  Mat srcColor;
  Mat gray;
  while(true)
  {
    camera >> srcColor;
  //IplImage* img= cvLoadImage("lena.jpg",1);
  //Mat srcColor(img);
  imshow("image",srcColor);
  cvtColor(srcColor, gray, COLOR_BGR2GRAY) ;
  imshow("converted image",gray);
  const int MEDIAN_BLUR_FILTER_SIZE = 7;
  medianBlur(gray, gray, MEDIAN_BLUR_FILTER_SIZE) ;
  const int LAPLACIAN_FILTER_SIZE = 5;
  Laplacian(gray, edges, CV_8U, LAPLACIAN_FILTER_SIZE) ;
  imshow("laplacian",edges);
  if (char(waitKey(10))=='x')
  {
    exit(0);
  }
  }
  return 0;
}
