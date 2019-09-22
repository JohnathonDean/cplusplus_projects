/*

*/

#include <iostream>

using namespace std;

void swap0(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swap1(int a, int b)
{
    swap(a,b);
}

void swap2(int *a, int *b)
{
    swap(*a,*b);
}

void swap3(int &a, int &b)
{
    swap(a,b);
}

int main(int argc, char const *argv[])
{
    int x=2,y=3;
    cout << " x " << x << " y " << y << endl;
    swap1(x,y);
    cout << " x " << x << " y " << y << endl;
    swap2(&x,&y);
    cout << " x " << x << " y " << y << endl;
    swap3(x,y);
    cout << " x " << x << " y " << y << endl;
    swap0(x,y);
    cout << " x " << x << " y " << y << endl;

    return 0;
}

