#include <iostream>
#include <cmath>
#include <string>
#include <climits>
#include <cassert>
#include <ctime>
#include "sort_search/MyUtil.h"
#include "sort_search/Student.h"

using namespace std;

template<typename T>
T *insertSort(T arr_in[], int num)
{
    for(int i = 1; i < num; i++)
    {
        T key = arr_in[i];
        int j;
        for(j = i; j > 0 && arr_in[j-1] > key; j--)
            arr_in[j] = arr_in[j-1];
        arr_in[j] = key;
    }

    return arr_in;
}

template<typename T>
T *shellSort(T arr_in[], int num)
{
    int h = 1;
    while( h < num/3 )
        h = 3 * h + 1;      // 1,4,13,40,121...采用的knuth步长，步长序列的选择问题？
    // 计算 increment sequence: 1, 4, 13, 40, 121, 364, 1093...
    while( h >= 1 ){
        // h-sort the array
        for( int i = h ; i < num ; i ++ ){
            // 对 arr_in[i], arr_in[i-h], arr_in[i-2*h], arr_in[i-3*h]... 使用插入排序
            T e = arr_in[i];
            int j;
            for( j = i ; j >= h && e < arr_in[j-h] ; j -= h )
                arr_in[j] = arr_in[j-h];
            arr_in[j] = e;
        }
        h /= 3;
    }

    return arr_in;
}

template<typename T>
T *selectSort(T arr_in[], int num)
{
    for(int i = 0; i < num; i++)
    {
        int minindex = i;   //设置最小值的下标
        for(int j = i; j < num; j++)
        {
            if(arr_in[j] < arr_in[minindex])
                minindex = j;
        }
        swap(arr_in[i], arr_in[minindex]);
    }
    
    return arr_in;
}

template<typename T>
T *bubbleSort(T arr_in[], int num)
{
    bool swapped;
    do{
        swapped = false;
        for( int i = 1 ; i < num ; i ++ ){
            if( arr_in[i-1] > arr_in[i] ){
                swap( arr_in[i-1] , arr_in[i] );
                swapped = true;
            }
        }
        num --;
    }while(swapped);

    return arr_in;
}


int main(int argc, const char** argv) {
    
    int n = 50, dataL = 1,dataR = 100; 
    int* data = MyUtil::generateRandomArray(n, dataL, dataR);
    
    cout << "generateRandomArray: ";
    for(int i = 0; i < n; i++)
        cout << data[i] << "  ";
    cout << endl;

    clock_t startTime1 = clock();
    int* data_out = bubbleSort(data, n);
    clock_t endTime1 = clock();

    cout << "insertSort time cost: " << double(endTime1 - startTime1)/CLOCKS_PER_SEC << " s" << endl;
    cout << "sortArray result: " << endl; 
    for(int i = 0; i < n; i++)
        cout << data_out[i] << "  ";
    cout << endl;
    
    clock_t startTime2 = clock();
    int* data_out2 = shellSort(data, n);
    clock_t endTime2 = clock();

    cout << "shellSort time cost: " << double(endTime2 - startTime2)/CLOCKS_PER_SEC << " s" << endl;
    cout << "sortArray result: " << endl; 
    for(int i = 0; i < n; i++)
        cout << data_out2[i] << "  ";
    cout << endl;
    
    delete data, data_out, data_out2;

    Student d[4] = {{"D",90}, {"C",80}, {"A",70}, {"B",70}};
    Student* d1 = selectSort(d, 4);
    for(int i = 0;i < 4; i++)
        cout << d[i];
    cout << endl;

    return 0;
}
