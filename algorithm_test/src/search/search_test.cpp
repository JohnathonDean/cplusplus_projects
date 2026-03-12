#include "search.h"

#include <iostream>
#include <string>
#include <vector>

namespace {

// 输出每个测试点的执行结果。
void printResult(const std::string& name, bool passed) {
    std::cout << name << ": " << (passed ? "PASS" : "FAIL") << std::endl;
}

}  // namespace

int main() {
    // 用于验证标准二分查找。
    const std::vector<int> orderedNums = {1, 3, 5, 7, 9, 11, 13};
    printResult("binarySearch_hit",
                search_algo::binarySearch(orderedNums, 7) == 3);
    printResult("binarySearch_miss",
                search_algo::binarySearch(orderedNums, 8) == -1);

    // 用于验证重复元素场景下的左右边界查找。
    const std::vector<int> duplicateNums = {1, 2, 2, 2, 3, 4, 4, 5};
    printResult("leftBoundBinarySearch_hit",
                search_algo::leftBoundBinarySearch(duplicateNums, 2) == 1);
    printResult("rightBoundBinarySearch_hit",
                search_algo::rightBoundBinarySearch(duplicateNums, 2) == 3);
    printResult("leftBoundBinarySearch_miss",
                search_algo::leftBoundBinarySearch(duplicateNums, 6) == -1);
    printResult("rightBoundBinarySearch_miss",
                search_algo::rightBoundBinarySearch(duplicateNums, 6) == -1);

    return 0;
}
