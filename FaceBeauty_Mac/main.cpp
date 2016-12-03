//
//  main.cpp
//  FaceBeauty_Mac
//
//  Created by zhoushiwei on 2016/11/29.
//  Copyright © 2016年 zhoushiwei. All rights reserved.
//

#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include "MyBeauty.h"
#include <iostream>
#include <ctype.h>

using namespace cv;
using namespace std;

int main( int argc, const char** argv )
{
    VideoCapture cap;
    MyBeauty MB;
    cap.open(0);
    cap.set(CV_CAP_PROP_FRAME_WIDTH,640);
    cap.set(CV_CAP_PROP_FRAME_HEIGHT,480);
    if( !cap.isOpened() )
    {
        return -1;
    }

    Mat frame;
    for(;;)
    {
        
            cap >> frame;
            if( frame.empty() )
                break;
        
        
        Mat BGR=frame.clone();
        Mat Dest=MB.ApplyZSWBeauty(BGR);
        imshow("Origin", frame);
        imshow("Beauty", Dest);
        waitKey(1);
   
      
        
    }
    
    return 0;
}
