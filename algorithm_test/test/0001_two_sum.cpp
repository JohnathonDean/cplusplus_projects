#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    int num = nums.size();
    for(int i = 0; i < num - 1; i ++) {
        for(int j = i + 1; j < num; j ++) {
            if(nums[i] + nums[j] == target) {
                res = {i, j};
                return res;
            }
        }
    }

    res = {0, 0};
    return res;
}

int main(int argc, char **argv)
{
    vector<int> inptu = {2,7,11,15};


    return 0;
}
