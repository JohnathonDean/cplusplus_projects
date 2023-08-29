#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "Eigen/Core"
#include "Eigen/Geometry"

int main(int argc, char **argv)
{
    Eigen::Matrix3d rotation_matrix1 = Eigen::Matrix3d::Identity();
    rotation_matrix1 << 1.000000e+00, 1.197624e-11, 1.704639e-10,
                        1.197625e-11, 1.000000e+00, 3.562503e-10,
                        1.704639e-10, 3.562503e-10, 1.000000e+00;
    Eigen::Matrix3d rotation_matrix2 = Eigen::Matrix3d::Identity();
    rotation_matrix2 = Eigen::AngleAxisd(10.0 * M_PI/180, Eigen::Vector3d::UnitZ()) *
                       Eigen::AngleAxisd(20.0 * M_PI/180, Eigen::Vector3d::UnitY()) *
                       Eigen::AngleAxisd(30.0 * M_PI/180, Eigen::Vector3d::UnitX());

    Eigen::Vector3d t1;
    t1 <<  3.214096e-14, -1.998401e-15, -4.041212e-14;
    Eigen::Vector3d t2(0.0, 0.0, 0.0);

    // Quaterniond类四元数初始化参数顺序为w,x,y,z
    Eigen::Quaterniond quaternion1(0.92388, 0, 0, 0.382683);
    Eigen::Quaterniond quaternion2(rotation_matrix2);

    Eigen::Isometry3d T1=Eigen::Isometry3d::Identity();
    T1.rotate(rotation_matrix2);
    T1.pretranslate(t1);

    std::cout << T1.matrix() << std::endl;
    std::ofstream outfile;
    outfile.open("/home/johnathon/mytest.txt", std::ios::app);
    outfile << T1.matrix() << std::endl;
    outfile.close();

    return 0;
}
