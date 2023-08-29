#include <iostream>
#include <fstream>
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
    cv::Ptr<cv::aruco::Dictionary> mdictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_ARUCO_ORIGINAL);
    int start_id = 45*id;
    int mark_num = 45;

    std::vector<std::shared_ptr<cv::Mat>> mark_que;
    for(int i = 0; i < mark_num; i++) {
        cv::Mat markerImage;//创建存储marker的Mat对象
        cv::aruco::drawMarker(mdictionary, start_id + i, 800, markerImage, 1);//生成marker ID:11  大小700x700像素  存放至Mat对象
        mark_que.push_back(std::make_shared<cv::Mat>(markerImage));
    }

    int width = 100 + 800 + 100;
    int height = width;
    std::vector<std::shared_ptr<cv::Mat>> row_img_que;
    int row_num = mark_num / 5;
    for(int i = 0; i < row_num; i++) {
        cv::Mat up_img(height, width*5, CV_8UC1, cv::Scalar(255));
        for(int j = 0; j < 5; j++) {
            cv::Mat ROI_0 = up_img(cv::Rect( width* j+100, 100, 800, 800));
            mark_que[i*5+j]->copyTo(ROI_0);
        }
        row_img_que.push_back(std::make_shared<cv::Mat>(up_img));
    }

    int que_size = row_img_que.size();
    int w1 = row_img_que[0]->cols;
    int h1 = row_img_que[0]->rows;
    cv::Mat res_img(h1*que_size, w1, CV_8UC1, cv::Scalar(255));
    for(int i = 0; i < que_size; i++) {
        cv::Mat ROI_0 = res_img(cv::Rect(0, h1*i, w1, h1));
        row_img_que[i]->copyTo(ROI_0);
    }
    std::string file_name_ = "markers_" + std::to_string(id) + ".jpg";
	cv::imwrite(file_name_, res_img);

}

void generate_marker_upside()
{
    cv::Ptr<cv::aruco::Dictionary> mdictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_ARUCO_ORIGINAL);
    std::vector<std::shared_ptr<cv::Mat>> mark_que;
    for(int i = 0; i < 100; i++) {
        cv::Mat markerImage;//创建存储marker的Mat对象
        cv::aruco::drawMarker(mdictionary, i, 800, markerImage, 1);
        mark_que.push_back(std::make_shared<cv::Mat>(markerImage));
    }

    int width = 100 + 800 + 100;
    int height = width;
    std::vector<std::shared_ptr<cv::Mat>> row_img_que;
    for(int i = 0; i < 9; i++) {
        cv::Mat up_img(height, width*9, CV_8UC1, cv::Scalar(255));
        for(int j = 0; j < 9; j++) {
            cv::Mat ROI_0 = up_img(cv::Rect( width* j+100, 100, 800, 800));
            mark_que[i*9+j]->copyTo(ROI_0);
        }
        row_img_que.push_back(std::make_shared<cv::Mat>(up_img));
    }

    int que_size = row_img_que.size();
    int w1 = row_img_que[0]->cols;
    int h1 = row_img_que[0]->rows;
    cv::Mat res_img(h1*que_size, w1, CV_8UC1, cv::Scalar(255));
    for(int i = 0; i < que_size; i++) {
        cv::Mat ROI_0 = res_img(cv::Rect(0, h1*i, w1, h1));
        row_img_que[i]->copyTo(ROI_0);
    }
    std::string file_name_ = "up_markers.jpg";
	cv::imwrite(file_name_, res_img);


}



void write_id(int id)
{
    std::ofstream info_file_output;
    info_file_output.open("id_config.txt");

    for(int i = 0; i < id; i++) {
        info_file_output << "  - {" << std::endl;
        info_file_output << "      id: " << std::to_string(i) << ", corners: [[0.012, 0.012, 0], [0.012, -0.012, 0], [-0.012, 0.012, 0], [-0.012, -0.012, 0]]" << std::endl;
        info_file_output << "    }" << std::endl;
    }

    info_file_output.close();
}


void write_id_map(int id)
{
    std::ofstream info_file_output;
    info_file_output.open("id_map.txt");

    info_file_output << "%YAML:1.0" << std::endl;
    info_file_output << "map_dictionary: ARUCO" << std::endl;
    info_file_output << "map_markers_nums: 500" << std::endl;
    info_file_output << "map_id: ID_YOUIBOT" << std::endl;
    info_file_output << "# pixel:0; meters: 1" << std::endl;
    info_file_output << "map_info_type: 1" << std::endl;
    info_file_output << "map_markers:" << std::endl;

    double corr = 1.0;
    // double corr = 2692.0 / 2694.0;

    int row_num = id / 5;
    for(int i = 0; i < row_num; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            int curr_id = i * 5 + j;
            double x0 = 0.0 - 0.030 * i * corr;
            double y0 = 0.0 - 0.030 * j * corr;
            double x1 = (x0 + 0.012) * corr;
            double y1 = (y0 + 0.012) * corr;
            double x2 = (x0 + 0.012) * corr;
            double y2 = (y0 - 0.012) * corr;
            double x3 = (x0 - 0.012) * corr;
            double y3 = (y0 - 0.012) * corr;
            double x4 = (x0 - 0.012) * corr;
            double y4 = (y0 + 0.012) * corr;
            std::string pose = "[[" + std::to_string(x1) + ", " + std::to_string(y1) + ", 0], "
                                            + "[" + std::to_string(x2) + ", " + std::to_string(y2) + ", 0], "
                                            + "[" + std::to_string(x3) + ", " + std::to_string(y3) + ", 0], "
                                            + "[" + std::to_string(x4) + ", " + std::to_string(y4) + ", 0]]";
            info_file_output << "  - {" << std::endl;
            info_file_output << "      id: " << std::to_string(i*5+j) << ", corners: " << pose << std::endl;
            info_file_output << "    }" << std::endl;

        }
    }

    info_file_output.close();
}

void write_markmap3_id()
{
    std::ofstream info_file_output;
    info_file_output.open("markmap3_id.txt");

    info_file_output << "%YAML:1.0" << std::endl;
    info_file_output << "map_dictionary: ARUCO" << std::endl;
    info_file_output << "map_markers_nums: 81" << std::endl;
    info_file_output << "map_id: ID_YOUIBOT" << std::endl;
    info_file_output << "# pixel:0; meters: 1" << std::endl;
    info_file_output << "map_info_type: 1" << std::endl;
    info_file_output << "map_markers:" << std::endl;

    double x_offset = 0.12;
    double y_offset = 0.12;
    double corr = 1.0;
    // double corr = 2692.0 / 2694.0;

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            int curr_id = i * 9 + j;
            double x0 = 0.0 - 0.030 * i * corr + x_offset;
            double y0 = 0.0 - 0.030 * j * corr + y_offset;
            double x1 = (x0 + 0.012) * corr;
            double y1 = (y0 + 0.012) * corr;
            double x2 = (x0 + 0.012) * corr;
            double y2 = (y0 - 0.012) * corr;
            double x3 = (x0 - 0.012) * corr;
            double y3 = (y0 - 0.012) * corr;
            double x4 = (x0 - 0.012) * corr;
            double y4 = (y0 + 0.012) * corr;
            std::string pose = "[[" + std::to_string(x1) + ", " + std::to_string(y1) + ", 0], "
                                            + "[" + std::to_string(x2) + ", " + std::to_string(y2) + ", 0], "
                                            + "[" + std::to_string(x3) + ", " + std::to_string(y3) + ", 0], "
                                            + "[" + std::to_string(x4) + ", " + std::to_string(y4) + ", 0]]";
            info_file_output << "  - {" << std::endl;
            info_file_output << "      id: " << std::to_string(i*9+j) << ", corners: " << pose << std::endl;
            info_file_output << "    }" << std::endl;

        }
    }

    info_file_output.close();
}

void write_mark_map(int id)
{
    std::ofstream info_file_output;
    info_file_output.open("mark_map.txt");

    info_file_output << "%YAML:1.0" << std::endl;
    info_file_output << "map_dictionary: ARUCO" << std::endl;
    info_file_output << "map_markers_nums: 500" << std::endl;
    info_file_output << "map_id: ID_YOUIBOT" << std::endl;
    info_file_output << "# pixel:0; meters: 1" << std::endl;
    info_file_output << "map_info_type: 1" << std::endl;
    info_file_output << "map_markers:" << std::endl;


    for(int i = 0; i < id; i++)
    {
        double x0 = 0.0-0.060*i;
        double y0 = 0.0;

        double x1 = x0 + 0.015;
        double y1 = y0 + 0.015;
        double x2 = x0 + 0.015;
        double y2 = y0 - 0.015;
        double x3 = x0 - 0.015;
        double y3 = y0 + 0.015;
        double x4 = x0 - 0.015;
        double y4 = y0 - 0.015;

        double x11 = x1 + 0.012;
        double y11 = y1 + 0.012;
        double x12 = x1 + 0.012;
        double y12 = y1 - 0.012;
        double x13 = x1 - 0.012;
        double y13 = y1 - 0.012;
        double x14 = x1 - 0.012;
        double y14 = y1 + 0.012;
        std::string pose = "[[" + std::to_string(x11) + ", " + std::to_string(y11) + ", 0], "
                    + "[" + std::to_string(x12) + ", " + std::to_string(y12) + ", 0], "
                    + "[" + std::to_string(x13) + ", " + std::to_string(y13) + ", 0], "
                    + "[" + std::to_string(x14) + ", " + std::to_string(y14) + ", 0]]";
        info_file_output << "  - {" << std::endl;
        info_file_output << "      id: " << std::to_string(0+i*10) << ", corners: " << pose << std::endl;
        info_file_output << "    }" << std::endl;

        double x21 = x2 + 0.012;
        double y21 = y2 + 0.012;
        double x22 = x2 + 0.012;
        double y22 = y2 - 0.012;
        double x23 = x2 - 0.012;
        double y23 = y2 - 0.012;
        double x24 = x2 - 0.012;
        double y24 = y2 + 0.012;
        pose = "[[" + std::to_string(x21) + ", " + std::to_string(y21) + ", 0], "
                    + "[" + std::to_string(x22) + ", " + std::to_string(y22) + ", 0], "
                    + "[" + std::to_string(x23) + ", " + std::to_string(y23) + ", 0], "
                    + "[" + std::to_string(x24) + ", " + std::to_string(y24) + ", 0]]";
        info_file_output << "  - {" << std::endl;
        info_file_output << "      id: " << std::to_string(1+i*10) << ", corners: " << pose << std::endl;
        info_file_output << "    }" << std::endl;

        double x31 = x3 + 0.012;
        double y31 = y3 + 0.012;
        double x32 = x3 + 0.012;
        double y32 = y3 - 0.012;
        double x33 = x3 - 0.012;
        double y33 = y3 - 0.012;
        double x34 = x3 - 0.012;
        double y34 = y3 + 0.012;
        pose = "[[" + std::to_string(x31) + ", " + std::to_string(y31) + ", 0], "
                    + "[" + std::to_string(x32) + ", " + std::to_string(y32) + ", 0], "
                    + "[" + std::to_string(x33) + ", " + std::to_string(y33) + ", 0], "
                    + "[" + std::to_string(x34) + ", " + std::to_string(y34) + ", 0]]";
        info_file_output << "  - {" << std::endl;
        info_file_output << "      id: " << std::to_string(5+i*10) << ", corners: " << pose << std::endl;
        info_file_output << "    }" << std::endl;

        double x41 = x4 + 0.012;
        double y41 = y4 + 0.012;
        double x42 = x4 + 0.012;
        double y42 = y4 - 0.012;
        double x43 = x4 - 0.012;
        double y43 = y4 - 0.012;
        double x44 = x4 - 0.012;
        double y44 = y4 + 0.012;
        pose = "[[" + std::to_string(x41) + ", " + std::to_string(y41) + ", 0], "
                    + "[" + std::to_string(x42) + ", " + std::to_string(y42) + ", 0], "
                    + "[" + std::to_string(x43) + ", " + std::to_string(y43) + ", 0], "
                    + "[" + std::to_string(x44) + ", " + std::to_string(y44) + ", 0]]";
        info_file_output << "  - {" << std::endl;
        info_file_output << "      id: " << std::to_string(6+i*10) << ", corners: " << pose << std::endl;
        info_file_output << "    }" << std::endl;

    }

    info_file_output.close();
}



int main(int argc, char **argv)
{

    // for(int i = 0; i < 11;i++)
    // {
    //     generate_marker_board(i);
    // }

    // write_id_map(500);
    // write_mark_map(20);

    // generate_marker_upside();

    write_markmap3_id();

    return 0;
}
