#include <exception>
#include <functional>
#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <ostream>
#include <string>
#include <string>
#include <thread>

void captureFrames(cv::VideoCapture& cap, cv:: Mat& frame, bool& running);


int main(int argc, char** argv) {
    std::string videoPath = "v412src device=/dev/video1 ! video/x-raw, width=640, height=480 ! videoconvert ! appsink";

    std::cout << "About to capture video from " <<std::endl;

    try{
        cv::VideoCapture cap (0, cv::CAP_GSTREAMER);
        if (!cap.isOpened()) {
            throw std::runtime_error("Unable to open the camera");
            return -1;
        }
        std::cout << "Video capture initialized successfully" << std::endl;

        cv::Mat frame;
        bool running = true;

        std::cout << "I am running" << std::endl;

        std::thread caputureThread(captureFrames, std::ref(cap), std::ref(frame), std::ref(running));

        std::cout << "Started the thread" << std::endl;

        while(running){
            if(!frame.empty()){
                cv::imshow("Video Feed", frame);
                if(cv::waitKey(1) == 'q'){
                    running = false;
                }
        }
    }

    caputureThread.join();
    std::cout << "Thread joined" << std::endl;
    }catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return -1;

    }
    return 0;

}

void captureFrames(cv::VideoCapture& cap, cv::Mat& frame, bool& running){
    while(running){
        cap >> frame;
    }
}