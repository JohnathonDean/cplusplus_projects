#include "sort.h"

#include <algorithm>

namespace sort_algo {

// 冒泡排序：每一轮将当前区间中的最大值交换到末尾。
void bubbleSort(std::vector<int>& nums) {
    const int n = static_cast<int>(nums.size());
    // 外层循环控制总共需要进行多少轮“冒泡”。
    for (int i = 0; i < n - 1; ++i) {
        // 记录本轮是否发生交换，用于提前结束。
        bool swapped = false;
        // 内层循环只遍历尚未归位的部分，尾部 i 个元素已经有序。
        for (int j = 0; j < n - 1 - i; ++j) {
            // 相邻元素逆序时交换，让较大的元素向右移动。
            if (nums[j] > nums[j + 1]) {
                std::swap(nums[j], nums[j + 1]);
                swapped = true;
            }
        }
        // 如果本轮没有交换，说明整个数组已经有序。
        if (!swapped) {
            break;
        }
    }
}

// 选择排序：每一轮从未排序区间中选择最小值放到前面。
void selectionSort(std::vector<int>& nums) {
    const int n = static_cast<int>(nums.size());
    // i 表示当前要放置最小值的位置。
    for (int i = 0; i < n - 1; ++i) {
        // 假设当前位置就是未排序区间中的最小值。
        int minIndex = i;
        // 在 [i + 1, n - 1] 中继续寻找更小的元素。
        for (int j = i + 1; j < n; ++j) {
            if (nums[j] < nums[minIndex]) {
                minIndex = j;
            }
        }
        // 将找到的最小值交换到当前位置。
        if (minIndex != i) {
            std::swap(nums[i], nums[minIndex]);
        }
    }
}

// 插入排序：将当前元素插入到前面已经有序的区间中。
void insertionSort(std::vector<int>& nums) {
    const int n = static_cast<int>(nums.size());
    // 从第二个元素开始，默认前面的区间已经有序。
    for (int i = 1; i < n; ++i) {
        // key 是当前要插入到有序区间中的元素。
        int key = nums[i];
        int j = i - 1;
        // 从右向左查找插入位置，并把较大的元素整体后移。
        while (j >= 0 && nums[j] > key) {
            nums[j + 1] = nums[j];
            --j;
        }
        // 循环结束后，j + 1 就是 key 的正确位置。
        nums[j + 1] = key;
    }
}

// 合并两个有序子区间 [left, mid] 和 [mid + 1, right]。
void merge(std::vector<int>& nums, int left, int mid, int right) {
    // 临时数组用于保存合并结果，避免直接覆盖原数据。
    std::vector<int> temp;
    temp.reserve(right - left + 1);

    // i 指向左半部分起点，j 指向右半部分起点。
    int i = left;
    int j = mid + 1;

    // 比较左右两个有序区间的当前元素，较小者先放入 temp。
    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            temp.push_back(nums[i++]);
        } else {
            temp.push_back(nums[j++]);
        }
    }

    // 左半部分如果还有剩余，直接追加到 temp。
    while (i <= mid) {
        temp.push_back(nums[i++]);
    }

    // 右半部分如果还有剩余，直接追加到 temp。
    while (j <= right) {
        temp.push_back(nums[j++]);
    }

    // 将合并后的结果回写到原数组对应区间。
    for (int k = 0; k < static_cast<int>(temp.size()); ++k) {
        nums[left + k] = temp[k];
    }
}

// 归并排序：先递归拆分，再回溯时合并。
void mergeSortImpl(std::vector<int>& nums, int left, int right) {
    // 区间长度为 1 时天然有序，递归结束。
    if (left >= right) {
        return;
    }

    // 取中点，将当前区间拆成左右两个子区间。
    const int mid = left + (right - left) / 2;
    // 先分别把左半区间排好序。
    mergeSortImpl(nums, left, mid);
    // 再把右半区间排好序。
    mergeSortImpl(nums, mid + 1, right);
    // 最后合并两个有序子区间。
    merge(nums, left, mid, right);
}

void mergeSort(std::vector<int>& nums) {
    // 空数组无需排序，避免出现右边界为 -1 的情况。
    if (nums.empty()) {
        return;
    }
    mergeSortImpl(nums, 0, static_cast<int>(nums.size()) - 1);
}

// 快速排序分区：将小于等于基准值的元素移动到左侧。
int partition(std::vector<int>& nums, int left, int right) {
    // 这里选取区间最右侧元素作为基准值。
    const int pivot = nums[right];
    // smaller 指向“小于等于 pivot”区间的最后一个位置。
    int smaller = left - 1;

    // 扫描 [left, right - 1]，把小于等于 pivot 的元素交换到前面。
    for (int i = left; i < right; ++i) {
        if (nums[i] <= pivot) {
            ++smaller;
            std::swap(nums[smaller], nums[i]);
        }
    }

    // 扫描结束后，把基准值放到两个区间的分界位置。
    std::swap(nums[smaller + 1], nums[right]);
    return smaller + 1;
}

// 快速排序：围绕基准值分区后递归处理左右两边。
void quickSortImpl(std::vector<int>& nums, int left, int right) {
    // 区间为空或只有一个元素时已经有序。
    if (left >= right) {
        return;
    }

    // partition 返回基准值最终落定的位置。
    const int pivotIndex = partition(nums, left, right);
    // 递归处理基准值左边的子区间。
    quickSortImpl(nums, left, pivotIndex - 1);
    // 递归处理基准值右边的子区间。
    quickSortImpl(nums, pivotIndex + 1, right);
}

void quickSort(std::vector<int>& nums) {
    // 空数组直接返回，避免无意义递归。
    if (nums.empty()) {
        return;
    }
    quickSortImpl(nums, 0, static_cast<int>(nums.size()) - 1);
}

// 堆调整：以 root 为根节点维护大顶堆性质。
void heapify(std::vector<int>& nums, int heapSize, int root) {
    // 默认根节点最大，随后与左右孩子比较。
    int largest = root;
    const int left = 2 * root + 1;
    const int right = 2 * root + 2;

    // 如果左孩子存在且更大，则更新最大值下标。
    if (left < heapSize && nums[left] > nums[largest]) {
        largest = left;
    }

    // 如果右孩子存在且更大，则继续更新最大值下标。
    if (right < heapSize && nums[right] > nums[largest]) {
        largest = right;
    }

    // 如果最大值不是根节点，交换后继续向下调整。
    if (largest != root) {
        std::swap(nums[root], nums[largest]);
        heapify(nums, heapSize, largest);
    }
}

// 堆排序：先建堆，再不断把堆顶最大值放到数组末尾。
void heapSort(std::vector<int>& nums) {
    const int n = static_cast<int>(nums.size());

    // 从最后一个非叶子节点开始，逐步构建大顶堆。
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(nums, n, i);
    }

    // 堆顶始终是当前最大值，将其与末尾交换后即可“归位”。
    for (int i = n - 1; i > 0; --i) {
        std::swap(nums[0], nums[i]);
        // 交换后前面的堆可能失去性质，需要在缩小后的区间内重新调整。
        heapify(nums, i, 0);
    }
}

}  // namespace sort_algo
