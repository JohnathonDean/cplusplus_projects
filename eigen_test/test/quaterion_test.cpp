#include <iostream>
#include <string>
#include <cstring>
#include "Eigen/Core"
#include "Eigen/Geometry"

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char **argv)
{

    // Quaterniond类四元数初始化参数顺序为w,x,y,z
    Eigen::Quaterniond quaternion1(0.016054,0.999787,-0.001744,0.012879);
    Eigen::Vector3d eulerAngle_ = quaternion1.matrix().eulerAngles(2,1,0);
    double rx = eulerAngle_[2]*180.0/M_PI;
    double ry = eulerAngle_[1]*180.0/M_PI;
    double rz = eulerAngle_[0]*180.0/M_PI;

    std::cout << rx << " , "
            << ry << " , "
            << rz << std::endl;

    Eigen::Vector3d euler_angles(rx/180.0*M_PI, ry/180.0*M_PI, rz/180.0*M_PI);//RPY RZ RY RX
    Eigen::Quaterniond quaternion_in;
    quaternion_in = Eigen::AngleAxisd(euler_angles[0], Eigen::Vector3d::UnitZ()) *
                    Eigen::AngleAxisd(euler_angles[1], Eigen::Vector3d::UnitY()) *
                    Eigen::AngleAxisd(euler_angles[2], Eigen::Vector3d::UnitX());
    std::cout << quaternion_in.w() << " , "
                << quaternion_in.x() << " , "
                << quaternion_in.y() << " , "
                << quaternion_in.z() << std::endl;

    return 0;
}