#include <iostream>
 #include <iomanip>
#include <string>
#include <cstring>
#include "Eigen/Core"
#include "Eigen/Geometry"

int main(int argc, char **argv)
{

    // Eigen::MatrixXd inf = Eigen::MatrixXd::Identity(6, 6);
    // cout << "inf: " << inf << endl;

    // inf.topLeftCorner(3, 3).array() /= 0.2;
    // inf.bottomRightCorner(3, 3).array() /= 0.1;
    // cout << "inf: " << inf << endl;

    Eigen::Matrix3d rotation_matrix1 = Eigen::Matrix3d::Identity();
    Eigen::Matrix3d rotation_matrix2 = Eigen::Matrix3d::Identity();
    Eigen::Matrix3d rotation_matrix3 = Eigen::Matrix3d::Identity();
    Eigen::Matrix3d rotation_matrix4 = Eigen::Matrix3d::Identity();
    Eigen::Matrix3d rotation_matrix5 = Eigen::Matrix3d::Identity();
    Eigen::Matrix3d rotation_matrix6 = Eigen::Matrix3d::Identity();

    rotation_matrix1 << 0.031636, -0.999499, 0, 0.999499, 0.031636, 0, 0, 0, 1;
    rotation_matrix2 << 0.0289936, -0.99958, 0, 0.99958, 0.0289936, 0, 0, 0, 1;
    rotation_matrix3 << 0.0327669, -0.999463, 0, 0.999463, 0.0327669, 0, 0, 0, 1;
    rotation_matrix4 << 0.0317152, -0.999497, 0, 0.999497, 0.0317152, 0, 0, 0, 1;
    rotation_matrix5 << 0.382173, -0.924091, 0, 0.924091, 0.382173, 0, 0, 0, 1;
    rotation_matrix6 << 0.378425, -0.925632, 0, 0.925632, 0.378425, 0, 0, 0, 1;

    // std::cout << rotation_matrix1 << std::endl << std::endl;
    // std::cout << rotation_matrix2 << std::endl << std::endl;
    // std::cout << rotation_matrix3 << std::endl << std::endl;
    // std::cout << rotation_matrix4 << std::endl << std::endl;
    // std::cout << rotation_matrix5 << std::endl << std::endl;
    // std::cout << rotation_matrix6 << std::endl << std::endl;

    Eigen::Vector3d t1(14.447, 24.6925,0);
    Eigen::Vector3d t2(14.4274, 24.6964,0);
    Eigen::Vector3d t3(14.4416, 25.4706,0);
    Eigen::Vector3d t4(14.4506, 25.4738,0);
    Eigen::Vector3d t5(14.5323, 26.2539,0);
    Eigen::Vector3d t6(14.5337, 26.2507,0);


    Eigen::Isometry3d T1=Eigen::Isometry3d::Identity();
    Eigen::Isometry3d T2=Eigen::Isometry3d::Identity();
    Eigen::Isometry3d T3=Eigen::Isometry3d::Identity();
    Eigen::Isometry3d T4=Eigen::Isometry3d::Identity();
    Eigen::Isometry3d T5=Eigen::Isometry3d::Identity();
    Eigen::Isometry3d T6=Eigen::Isometry3d::Identity();

    T1.rotate(rotation_matrix1);
    T1.pretranslate(t1);
    T2.rotate(rotation_matrix2);
    T2.pretranslate(t2);
    T3.rotate(rotation_matrix3);
    T3.pretranslate(t3);
    T4.rotate(rotation_matrix4);
    T4.pretranslate(t4);
    T5.rotate(rotation_matrix5);
    T5.pretranslate(t5);
    T6.rotate(rotation_matrix6);
    T6.pretranslate(t6);

    // std::cout << T1.matrix() << std::endl << std::endl;
    // std::cout << T2.matrix() << std::endl << std::endl;
    // std::cout << T3.matrix() << std::endl << std::endl;
    // std::cout << T4.matrix() << std::endl << std::endl;
    // std::cout << T5.matrix() << std::endl << std::endl;
    // std::cout << T6.matrix() << std::endl << std::endl;

    Eigen::Isometry3d error_offset1 =  T2.inverse() * T1;
    Eigen::Isometry3d error_offset2 =  T4.inverse() * T3;
    Eigen::Isometry3d error_offset3 =  T6.inverse() * T5;

    std::cout << error_offset1.matrix() << std::endl << std::endl;
    std::cout << error_offset2.matrix() << std::endl << std::endl;
    std::cout << error_offset3.matrix() << std::endl << std::endl;

    std::cout << "error_norm:" << error_offset1.translation().norm() << std::endl;
    std::cout << "error_norm:" << error_offset2.translation().norm() << std::endl;
    std::cout << "error_norm:" << error_offset3.translation().norm() << std::endl;

    // Eigen::VectorXd t6(5);


    return 0;
}