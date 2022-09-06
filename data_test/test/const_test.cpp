#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    int i = 10;
    int *p1, p2;
    p1 = &i;
    p2 = i;
    cout << p1 << "  " << *p1 << endl;
    p1 = nullptr;
    cout << p1 << endl;

    const int k = 20;
    const int &r1 = k;
    const int &r3 = r1 * 2;

    double dval = 3.1415;
    const int ri = dval;

    const int &r2 = i;
    cout << r2 << endl;
    i = 20;
    cout << r2 << endl;     //改变i之后，常量引用r2的值也会发生变化

    const double pi = 3.14;
    const double *p3 = &pi;     //指向常量的指针
    cout << p3 << "  " << *p3 << endl;
    p3 = &dval;     //可以修改指针的指向对象
    cout << p3 << "  " << *p3 << endl;
    double *const p4 = &dval;       //常量指针,不可修改指针的指向对象
    const double *const pip = &pi;  //指向常量的常量指针


    return 0;
}
