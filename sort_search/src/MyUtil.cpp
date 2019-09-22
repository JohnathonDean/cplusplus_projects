#include "sort_search/MyUtil.h"

using namespace std;

namespace MyUtil {

    int *generateRandomArray(int n, int rangeL, int rangeR){
        assert(n > 0 && rangeL <= rangeR);

        int *arr = new int[n];
        srand(time(NULL));
        for(int i = 0; i < n; i++)
            arr[i] = rand() % (rangeL - rangeR + 1) + rangeL;
        
        return arr;
    }


    int *generateNearlyOrderedArray(int n, int swapTimes){
        assert(n > 0 && swapTimes > 0);

        int *arr = new int[n];
        for(int i = 0; i < n; i++)
            arr[i] = i;
        
        srand(time(NULL));
        for(int i = 0; i < swapTimes; i++){
            int posx = rand()%n;
            int posy = rand()%n;
            swap(arr[posx], arr[posy]);
        }

        return arr;
    }


    int *generateOrderedArray(int n){
        assert(n > 0);
        int *arr = new int[n];
        for(int i = 0; i < n; i++)
            arr[i] = i;
        return arr;
    }


}