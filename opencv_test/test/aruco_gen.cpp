#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/aruco/charuco.hpp"
#include "opencv2/imgproc.hpp"


using std::cin;
using std::cout;
using std::endl;

using namespace cv;

void gengerate_aruco_code(int mark_id)
{
	// to gengerate a new maker
	cv::Mat markerImage;//创建存储marker的Mat对象
	cv::Ptr<cv::aruco::Dictionary> mdictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_ARUCO_ORIGINAL);
	cv::aruco::drawMarker(mdictionary, mark_id, 500, markerImage, 1);//生成marker ID:11  大小500x500像素  存放至Mat对象

	imshow("test", markerImage);//显示marker
	waitKey();
	imwrite("aruco_marker.jpg", markerImage);
}

void writer_aruco_marker(int start_id, int num)
{
    for(int i = 0; i < num; i++) {
        cv::Mat markerImage;//创建存储marker的Mat对象
        cv::Ptr<cv::aruco::Dictionary> mdictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_ARUCO_ORIGINAL);
        cv::aruco::drawMarker(mdictionary, start_id + i, 500, markerImage, 1);//生成marker ID:11  大小500x500像素  存放至Mat对象
        std::string marker_id_ = std::to_string(start_id + i);
        std::string file_name_ = "aruco_marker" + marker_id_ + ".jpg";
        imwrite(file_name_, markerImage);
        sleep(0.2);
    }
}

int main(int argc, char **argv)
{
    writer_aruco_marker(0,500);

    return 0;
}
