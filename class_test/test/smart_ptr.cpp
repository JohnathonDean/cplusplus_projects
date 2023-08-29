#include <iostream>

#include<boost/smart_ptr.hpp>

#include <pcl/point_types.h>
#include <pcl/point_cloud.h>

typedef pcl::PointXYZI PointT;

using namespace std;

class mainClassA {
public:
    mainClassA();
    ~mainClassA();

    bool sum();

private:
    boost::shared_ptr<int> ptr1;

    pcl::PointCloud<PointT>::Ptr cloud_map;


};

mainClassA::mainClassA() {
    cout << "make A" << endl;

    ptr1 = boost::make_shared<int>();

    cloud_map = boost::make_shared<pcl::PointCloud<PointT>>();


}

mainClassA::~mainClassA() {
    cout << "destroy A" << endl;
}

bool mainClassA::sum() {

    ptr1.reset(new int());

    cloud_map.reset(new pcl::PointCloud<PointT>());


    return true;
}


class B
{
public:
    B()
    {}
    ~B()
    {}

    void sum()
    {
        a_main.sum();
    }

private:
    mainClassA a_main;

};



int main(int argc, char const *argv[])
{

    B test_b;

    test_b.sum();


    return 0;
}
