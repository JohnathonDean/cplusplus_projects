#include "search.h"

namespace search_algo {

// 标准二分查找：在有序数组中查找目标值，找到则返回下标，否则返回 -1。
int binarySearch(const std::vector<int>& nums, int target) {
    int left = 0;
    int right = static_cast<int>(nums.size()) - 1;

    // 当搜索区间仍然有效时持续收缩区间。
    while (left <= right) {
        // 使用这种写法避免 left + right 直接相加时的潜在溢出。
        const int mid = left + (right - left) / 2;

        // 命中目标值，直接返回当前位置。
        if (nums[mid] == target) {
            return mid;
        }

        // 中间值小于目标值，说明目标只可能出现在右半区间。
        if (nums[mid] < target) {
            left = mid + 1;
        } else {
            // 中间值大于目标值，说明目标只可能出现在左半区间。
            right = mid - 1;
        }
    }

    // 区间被缩小到空时仍未找到，返回 -1。
    return -1;
}

// 左边界二分查找：返回目标值第一次出现的位置，不存在则返回 -1。
int leftBoundBinarySearch(const std::vector<int>& nums, int target) {
    int left = 0;
    int right = static_cast<int>(nums.size());

    // 这里使用左闭右开区间 [left, right)。
    while (left < right) {
        const int mid = left + (right - left) / 2;

        if (nums[mid] < target) {
            // 目标只可能出现在更右侧的位置。
            left = mid + 1;
        } else {
            // nums[mid] >= target 时继续向左收缩，逼近最左位置。
            right = mid;
        }
    }

    // left 可能越界，或者虽然落在数组内但值并不是 target。
    if (left == static_cast<int>(nums.size()) || nums[left] != target) {
        return -1;
    }

    return left;
}

// 右边界二分查找：返回目标值最后一次出现的位置，不存在则返回 -1。
int rightBoundBinarySearch(const std::vector<int>& nums, int target) {
    int left = 0;
    int right = static_cast<int>(nums.size());

    // 同样使用左闭右开区间 [left, right)。
    while (left < right) {
        const int mid = left + (right - left) / 2;

        if (nums[mid] <= target) {
            // 命中目标时不立即返回，而是继续向右逼近最后一次出现的位置。
            left = mid + 1;
        } else {
            // 当前值已经大于目标，右边界一定在 mid 左侧。
            right = mid;
        }
    }

    // 循环结束后，left 指向第一个大于 target 的位置，因此右边界是 left - 1。
    const int index = left - 1;
    if (index < 0 || nums[index] != target) {
        return -1;
    }

    return index;
}

}  // namespace search_algo
