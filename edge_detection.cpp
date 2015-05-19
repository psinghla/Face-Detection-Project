#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
  VideoCapture camera;
  int cameraNumber=0;
  camera.open(0);
  Mat bgr,hsv;
  Mat edges;
  Mat srcColor;
  Mat gray;
  while(true)
  {
    camera >> srcColor;
  imshow("image",srcColor);
  //////////function to convert RGB to GRAY SCALE using cvtColor()///////
  cvtColor(srcColor, gray, COLOR_BGR2GRAY) ;
  ////////MEDIAN_BLUR_FILTER_SIZE is the size to cancel the noise///
  const int MEDIAN_BLUR_FILTER_SIZE = 7;
  ////////medianBlur() cancel the noise //////////
   medianBlur(gray, gray, MEDIAN_BLUR_FILTER_SIZE) ;
   //////////we converted the image to gray bcoz laplacian works in gray image only//////
   /////////laplacian operator is used to detect edges/////
  const int LAPLACIAN_FILTER_SIZE = 5;
  /////////CV_8U is unsigned 8bit/pixel - ie a pixel can have values 0-255, this is the normal range for most image and video formats.///////////////
  Laplacian(gray, edges, CV_8U, LAPLACIAN_FILTER_SIZE) ;
  imshow("laplacian",edges);
  if (char(waitKey(10))=='x')
  {
    exit(0);
  }
  }
  return 0;
}
