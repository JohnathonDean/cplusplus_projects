#include "sort.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

namespace {

// 使用标准库判定结果是否已经升序排列。
bool isSorted(const std::vector<int>& nums) {
    return std::is_sorted(nums.begin(), nums.end());
}

// 输出每个排序算法的测试结果。
void printResult(const std::string& name, bool passed) {
    std::cout << name << ": " << (passed ? "PASS" : "FAIL") << std::endl;
}

}  // namespace

int main() {
    // 使用同一组输入分别验证不同排序实现。
    const std::vector<int> input = {9, 4, 7, 1, 3, 8, 2, 6, 5};

    {
        std::vector<int> nums = input;
        sort_algo::bubbleSort(nums);
        printResult("bubbleSort", isSorted(nums));
    }

    {
        std::vector<int> nums = input;
        sort_algo::selectionSort(nums);
        printResult("selectionSort", isSorted(nums));
    }

    {
        std::vector<int> nums = input;
        sort_algo::insertionSort(nums);
        printResult("insertionSort", isSorted(nums));
    }

    {
        std::vector<int> nums = input;
        sort_algo::mergeSort(nums);
        printResult("mergeSort", isSorted(nums));
    }

    {
        std::vector<int> nums = input;
        sort_algo::quickSort(nums);
        printResult("quickSort", isSorted(nums));
    }

    {
        std::vector<int> nums = input;
        sort_algo::heapSort(nums);
        printResult("heapSort", isSorted(nums));
    }

    return 0;
}
