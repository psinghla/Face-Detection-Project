#include <highgui.h>
#include <opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
  int cameraNum=0;
  ///////to  get the input from camera//////////
  VideoCapture cam;
  cam.open(cameraNum);
  /////to set cam resolution////////
  cam.set(CV_CAP_PROP_FRAME_WIDTH, 640) ;
  cam.set(CV_CAP_PROP_FRAME_HEIGHT, 480) ;
  //////Mat is a keyword to capture the image from camera//////
  Mat bgr;
  while (true)
  {

    cam >> bgr;
    ///////imshow is a function which 1st takes the name of window to be made and then the image to be displayed///////////
    imshow("first screen",bgr);
    //////waitKey is used to update the image by the given ms and we have to exit that too/////
    if ((char)waitKey(10)=='x') // press 'x' to exit
          exit(0);
  }

  return 0;
}
