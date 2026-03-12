#ifndef SEARCH_H
#define SEARCH_H

#include <vector>

namespace search_algo {

int binarySearch(const std::vector<int>& nums, int target);
int leftBoundBinarySearch(const std::vector<int>& nums, int target);
int rightBoundBinarySearch(const std::vector<int>& nums, int target);

}  // namespace search_algo

#endif
