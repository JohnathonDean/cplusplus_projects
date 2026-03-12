#ifndef SORT_H
#define SORT_H

#include <vector>

namespace sort_algo {

void bubbleSort(std::vector<int>& nums);
void selectionSort(std::vector<int>& nums);
void insertionSort(std::vector<int>& nums);
void mergeSort(std::vector<int>& nums);
void quickSort(std::vector<int>& nums);
void heapSort(std::vector<int>& nums);

}  // namespace sort_algo

#endif
