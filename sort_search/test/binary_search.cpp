#include <iostream>
#include <cmath>
#include <cassert>
#include <ctime>
#include "sort_search/MyUtil.h"

using namespace std;

template<typename T>
int binarySearch(T arr[], int n, T target){

    int l = 0, r = n;    //在[l ... r]的范围内查找target
    while(l <= r){       //当l == r时，区间[l ... r]依然有效
        int mid = (l+r)/2;      //这种写法当l和r非常大时可能会产生整型溢出，应该改为l+(r-l)/2
        if(arr[mid] == target)
            return mid;
        if(target > arr[mid])
            l = mid +1;    //target在[mid+1 ... r]中
       else    // target < arr[mid]
           r = mid-1;     //target在[l ... mid-1]中
    }
    return -1;
}

int main(int argc, const char** argv) {
    
    int n = 50;
    int* data = MyUtil::generateOrderedArray(n);

    clock_t startTime = clock();
    for(int i = 0; i < n; i++){
        assert(i == binarySearch(data, n, i));
        // cout << binarySearch(data, n, i) << " ";     //输出每次的搜索结果
    }
    clock_t endTime = clock();

    cout << endl;
    cout << "binarySearch test complete." << endl;
    cout << "Time cost: " << double(endTime - startTime)/CLOCKS_PER_SEC << " s" << endl;

    return 0;
}