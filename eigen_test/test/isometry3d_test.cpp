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
    // cout << " " << quaternion2.w() << " "
    //             << quaternion2.x() << " "
    //             << quaternion2.y() << " "
    //             << quaternion2.z() << endl;


    Eigen::Isometry3d T1=Eigen::Isometry3d::Identity();
    T1.rotate(rotation_matrix2);
    T1.pretranslate(t1);
    cout << "T1: " << T1.translation().x() << " "
                    << T1.translation().y() << " "
                    << T1.translation().z() << endl;
    Eigen::Quaterniond qu_temp(T1.rotation());
    cout << qu_temp.w() << " "
            << qu_temp.x() << " "
            << qu_temp.y() << " "
            << qu_temp.z() << endl;
    cout << T1.rotation().eulerAngles(2,1,0)[0] / M_PI * 180 << endl;


    // t1 <<  1.1, 1.1, 1.1;
    // T1.pretranslate(t1);
    // cout << "T1: " << T1.translation().x() << " "
    //                 << T1.translation().y() << " "
    //                 << T1.translation().z() << endl;



    // Eigen::Isometry3d T2=Eigen::Isometry3d::Identity();
    // T2.rotate(rotation_matrix2);
    // T2.pretranslate(t2);




    return 0;
}


// keyframe_id: 91
// pose:
//  0.031636 -0.999499         0    14.447
//  0.999499  0.031636         0   24.6925
//         0         0         1         0
//         0         0         0         1
// ob_type: 2 ob_pose:
// 0.0289936  -0.99958         0   14.4274
//   0.99958 0.0289936         0   24.6964
//         0         0         1         0
//         0         0         0         1
// keyframe_id: 92
// pose:
// 0.0327669 -0.999463         0   14.4416
//  0.999463 0.0327669         0   25.4706
//         0         0         1         0
//         0         0         0         1
// ob_type: 2 ob_pose:
// 0.0317152 -0.999497         0   14.4506
//  0.999497 0.0317152         0   25.4738
//         0         0         1         0
//         0         0         0         1
// keyframe_id: 93
// pose:
//  0.382173 -0.924091         0   14.5323
//  0.924091  0.382173         0   26.2539
//         0         0         1         0
//         0         0         0         1
// ob_type: 2 ob_pose:
//  0.378425 -0.925632         0   14.5337
//  0.925632  0.378425         0   26.2507
//         0         0         1         0
//         0         0         0         1
