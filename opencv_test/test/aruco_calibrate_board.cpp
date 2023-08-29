#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <memory>
#include <unistd.h>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/aruco/charuco.hpp"
#include "opencv2/imgproc.hpp"


void generate_marker_board(int id)
{
    cv::Ptr<cv::aruco::Dictionary> mdictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_7X7_1000);
    int start_id = id * 100;
    int mark_num = 100;

    std::vector<std::shared_ptr<cv::Mat>> mark_que;

    for(int i = 0; i < mark_num; i++) {
        cv::Mat markerImage;//创建存储marker的Mat对象
        cv::aruco::drawMarker(mdictionary, start_id + i, 700, markerImage, 1);//生成marker ID:11  大小700x700像素  存放至Mat对象
        mark_que.push_back(std::make_shared<cv::Mat>(markerImage));
    }

    int width = (150 + 700 + 150) * 10;
    int height = 150 + 700 + 150;
    std::vector<std::shared_ptr<cv::Mat>> row_img_que;
    for(int i = 0; i < 5; i++) {
        cv::Mat up_img(height, width, CV_8UC1, cv::Scalar(255));
        cv::Mat down_img(height, width, CV_8UC1, cv::Scalar(255));
        for(int j = 0; j < 10; j++) {
            cv::Mat ROI_0 = up_img(cv::Rect((150 + 700 + 150) * j + 150, 150, 700, 700));
            mark_que[i*20+j]->copyTo(ROI_0);
        }
        for(int j = 0; j < 10; j++) {
            cv::Mat ROI_0 = down_img(cv::Rect((150 + 700 + 150) * j + 150, 150, 700, 700));
            mark_que[i*20+j+10]->copyTo(ROI_0);
        }
        cv::Mat raw_img(height * 2, width, CV_8UC1, cv::Scalar(255));
        cv::Mat ROI_1 = raw_img(cv::Rect(0, 0, width, height));
        cv::Mat ROI_2 = raw_img(cv::Rect(0, height, width, height));
        up_img.copyTo(ROI_1);
        down_img.copyTo(ROI_2);
        row_img_que.push_back(std::make_shared<cv::Mat>(raw_img));
    }

    int que_size = row_img_que.size();
    int w1 = row_img_que[0]->cols;
    int h1 = row_img_que[0]->rows;
    cv::Mat res_img((h1+height)*que_size, w1, CV_8UC1, cv::Scalar(255));
    for(int i = 0; i < que_size; i++) {
        cv::Mat ROI_0 = res_img(cv::Rect(0, (h1+height)*i, w1, h1));
        row_img_que[i]->copyTo(ROI_0);
    }
    std::string file_name_ = "markers_" + std::to_string(id) + ".jpg";
	cv::imwrite(file_name_, res_img);

}


int main(int argc, char **argv)
{

    for(int i = 0; i < 1;i++)
    {
        generate_marker_board(i);
    }



    return 0;
}
