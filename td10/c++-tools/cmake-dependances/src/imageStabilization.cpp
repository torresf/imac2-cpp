#include <iostream>
#include <vector>
#include <cstdlib>
#include <utility>   // std::pair
#include <ctime>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/video/video.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <Eigen/Dense>


// sudo apt-get install libeigen3-dev 
// sudo apt-get install libopencv-dev 
//g++ -Wall -Wno-unused-local-typedefs imageStabilization.cpp -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_video -I ~/eigen  -o stabilisation


//////////////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv)
{
  // check arguments
  if(argc > 2){
    std::cerr << "usage: " << argv[0] << " videoFileName" << std::endl;
    exit(0); 
  }
  
  // input video stream
  cv::VideoCapture capture;

  // load a video
  if(argc == 2){
    capture = cv::VideoCapture(argv[1]);
    if(!capture.isOpened()){
      std::cerr << "failed to open video file : " << argv[1] << std::endl;
      return -1;
    }
  }
  
  // or open a web cam stream
  if(argc == 1){
    std::cout << "   open video stream ..." << std::endl;
    capture = cv::VideoCapture(0);
    capture.set(CV_CAP_PROP_FRAME_WIDTH,800);
    capture.set(CV_CAP_PROP_FRAME_HEIGHT,600);
    std::cout << "video width  : " << capture.get(CV_CAP_PROP_FRAME_WIDTH) << std::endl;
    std::cout << "video height : " << capture.get(CV_CAP_PROP_FRAME_HEIGHT) << std::endl;
  }

  // grab a frame to get the video resolution
  cv::Mat frame;
  capture >> frame;
 
  // display window
  cv::namedWindow("input video");
  cvMoveWindow("input video",0, 50);
  cv::namedWindow("stabilization");
  cvMoveWindow("stabilization",900, 50);

  // gray scale images required for the tracking
  cv::Mat grayPrevious;
  cv::Mat gray;
  cv::cvtColor(frame, gray, CV_BGR2GRAY);
  gray.copyTo(grayPrevious);

  // find features to track
  std::vector<cv::Point2f> pointsToTrack[2];
  cv::goodFeaturesToTrack(gray,               // the image
                          pointsToTrack[0],   // the output detected features
                          1000,               // the maximum number of features
                          0.01,               // quality level
                          10.0);              // min distance between two features


  // the homography to apply to the data
  Eigen::Matrix3d H = Eigen::Matrix3d::Identity();

  // read video stream
  std::cout << "   read video stream ..." << std::endl;
  bool loop = true;
  while(loop){
 
    // get the next frame
    capture >> frame;

    // convert to gray scale
    cv::cvtColor(frame, gray, CV_BGR2GRAY);

    // if not enough points, add new points to track
    if(pointsToTrack[0].size()<500){
      pointsToTrack[1].clear();
      cv::goodFeaturesToTrack(gray,               // the image
                              pointsToTrack[1],   // the output detected features
                              1000,               // the maximum number of features
                              0.01,               // quality level
                              10.0);              // min distance between two features
      pointsToTrack[0].insert(pointsToTrack[0].end(),pointsToTrack[1].begin(),pointsToTrack[1].end());
      pointsToTrack[1].clear();
    }


    // tracking process
    std::vector<uchar> status; // status of tracked features
    std::vector<float> err;    // error in tracking
    cv::calcOpticalFlowPyrLK(
      grayPrevious, gray, // 2 consecutive images
      pointsToTrack[0], // input point positions in first image
      pointsToTrack[1], // output point positions in the 2nd image
      status, // tracking success
      err); // tracking error

    // keep the good points
    std::vector<cv::Point2f> initialPoints;
    std::vector<cv::Point2f> trackedPoints; 

    for(uint i= 0; i < pointsToTrack[1].size(); i++ ) {
      double motion = sqrt(pow(pointsToTrack[0][i].x-pointsToTrack[1][i].x,2)+pow(pointsToTrack[0][i].y-pointsToTrack[1][i].y,2));

      // do we keep this point?
      if (status[i] && motion < 20) {
        // keep this point in vector
        initialPoints.push_back(pointsToTrack[0][i]);
        trackedPoints.push_back(pointsToTrack[1][i]);
      }
    }
    pointsToTrack[0] = trackedPoints;

    // draw the tracking effect
    cv::Mat finalImage;
    frame.copyTo(finalImage);

    // for all tracked points
    for(uint i= 0; i < initialPoints.size(); i++ ) {
      // draw line and circle
      cv::line(finalImage,
        initialPoints[i], // initial position
        trackedPoints[i], // new position
        cv::Scalar(255,255,255));
      cv::circle(finalImage, trackedPoints[i], 3, cv::Scalar(0,0,255),-1);
    }


    ////////////////////////////////////////////////////////////////////////////////////////////
    // image stabilization

    // convert opencv to eigen
    Eigen::MatrixXd initialPts(3,initialPoints.size());
    Eigen::MatrixXd currentPts(3,trackedPoints.size());
    for(uint i=0; i<initialPoints.size(); ++i){
      initialPts.col(i) << initialPoints[i].x, initialPoints[i].y, 1.0;
      currentPts.col(i) << trackedPoints[i].x, trackedPoints[i].y, 1.0;
    }








    // if not enough points to track
    if(currentPts.cols() < 2)
      H = Eigen::Matrix3d::Identity();

    // convert the homography from Eigen to opencv
    cv::Mat Hocv(3,3,CV_64F);
    for(uint i=0; i<3; ++i)
      for(uint j=0; j<3; ++j)
        Hocv.at<double>(i,j) = H(i,j);

    // apply the homography to finalImage
    cv::Mat outputImage;
    cv::warpPerspective(finalImage, outputImage, Hocv, finalImage.size(), cv::INTER_LINEAR, cv::BORDER_CONSTANT);


    // image stabilization end
    ///////////////////////////////////////////////////////////////////////////////////////////


    // copy the last grab gray scale image to previous
    gray.copyTo(grayPrevious);
 
    // display the image
    cv::imshow("input video",frame);
    cv::imshow("stabilization",outputImage);

    // events (quit)
    switch(char(cv::waitKey(10))){
      case 27  : loop=false; break;
      case 'Q' :
      case 'q' : loop=false; break;
      case 's' : cv::imwrite("monImage.jpg",outputImage); break;
    }
     

  } // main loop end


  // close the video streaming
  std::cout << "   close video stream ..." << std::endl;
  capture.release();

  return 0;
}
