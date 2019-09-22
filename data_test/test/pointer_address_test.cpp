#include <iostream>
#include <iomanip>
#include <string>

int main()
{
    using namespace std;

    int donuts = 6;
    double cups = 4.5;
    cout << "donuts value = " << donuts;
    cout << " and donuts address = " << &donuts << endl;
    cout << "cups value = " << cups;
    cout << " and cups address = " << &cups << endl;

    int *p_donuts;      // int* p;  int * p;    declare pointer to an int
    p_donuts = &donuts;   // assign address of int to pointer
    int* pt = &donuts;      //init a ptr
    cout << "*p_donuts = " << *p_donuts << endl;

    // use pointer to change value
    *p_donuts = *p_donuts + 1;
    cout << "Now donuts = " << p_donuts << endl;

    int * pt1 = new int;         // allocate space for an int
    *pt1 = 1001;                 // store a value there
    double * pd = new double;   // allocate space for a double
    *pd = 10000001.0;           // store a double there

    cout << "double ";
    cout << "value = " << *pd << ": location = " << pd << endl;
    cout << "location of pointer pd: " << &pd << endl;
    cout << "size of pt1 = " << sizeof(pt1);
    cout << ": size of *pt1 = " << sizeof(*pt1) << endl;
    cout << "size of pd = " << sizeof pd;
    cout << ": size of *pd = " << sizeof(*pd) << endl;
    delete pt1,pd;

    int * pe = new int;    // allocate memory
    int * pq = pe;      //set second pointer to same block
    delete pq;          //delete with second pointer

    double * p3 = new double [3]; // space for 3 doubles
    p3[0] = 0.2;                  // treat p3 like an array name
    p3[1] = 0.5;
    p3[2] = 0.8;
    cout << "p3[1] is " << p3[1] << ".\n";
    p3 = p3 + 1;                  // increment the pointer
    cout << "Now p3[0] is " << p3[0] << " and ";
    cout << "p3[1] is " << p3[1] << ".\n";
    p3 = p3 - 1;                  // point back to beginning
    delete [] p3;                 // free the memory

    int * p2 = new int [3]; // space for 3 int
    p2[0] = 2;                  // treat p3 like an array name
    p2[1] = 5;
    p2[2] = 8;
    cout << "p2[1] is " << p2[1] << ".\n";
    p2 = p2 + 1;                  // increment the pointer
    cout << "Now p2[0] is " << p2[0] << " and ";
    cout << "p2[1] is " << p2[1] << ".\n";
    p2 = p2 - 1;                  // point back to beginning
    delete [] p2;                 // free the memory


    double wages[3] = {10000.0, 20000.0, 30000.0};
    short stacks[3] = {3, 2, 1};
// Here are two ways to get the address of an array
    double * pw = wages;     // name of an array = address
    short * ps = &stacks[0]; // or use address operator
// with array element
    cout << "pw = " << pw << ", *pw = " << *pw << endl;
    pw = pw + 1;
    cout << "add 1 to the pw pointer:\n";
    cout << "pw = " << pw << ", *pw = " << *pw << "\n\n";

    cout << "ps = " << ps << ", *ps = " << *ps << endl;
    ps = ps + 1;
    cout << "add 1 to the ps pointer:\n";
    cout << "ps = " << ps << ", *ps = " << *ps << "\n\n";

    cout << "access two elements with array notation\n";
    cout << "stacks[0] = " << stacks[0] 
         << ", stacks[1] = " << stacks[1] << endl;
    cout << "access two elements with pointer notation\n";
    cout << "*stacks = " << *stacks
         << ", *(stacks + 1) =  " << *(stacks + 1) << endl;

    cout << sizeof(wages) << " = size of wages array\n";
    cout << sizeof(pw) << " = size of pw pointer\n";

//指针与二维数组
    int a[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};       //对于a[i][j]元素的地址的表达：&a[i][j];a[i]+j;*(a+i)+j;a[0]+i*m+j  (m为数组的列数)
    int *p11;
    for(p11=a[0]; p11<a[0]+12; p11++)
    {
        if((p11-a[0])%4==0)
            cout << endl;
        cout << setw(4) << *p11;        //setw(4)来控制输出间隔,默认用空格填充间隔，可以配合setfill()设置其他字符填充
    }
    cout << endl;
    int (*p4)[4];
    p4 = a;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout << setfill('-') << setw(4) << *(*(p4+i)+j);
        }
        cout << endl;
    }
//存储指针的数组
    int *p12[10];   //定义一个指针数组p12有10个元素，每个元素是一个指向int类型数据的指针
    int (*p13)[4];
    int a13 = 12;
    (*p4)[0] = a13;
    cout << (*p4)[0] << endl;
    p12[0] = &a13;      //或者*p12[0] = a13;
    cout << *p12[0] << endl;

    string str1("asdfqwer");
    string str2(10,'a');
    swap(str1,str2);
    cout << str1 << endl;
    cout << str2 << endl;



    return 0;
}