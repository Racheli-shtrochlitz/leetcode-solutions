#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxElement = *max_element(nums.begin(), nums.end());
        int res = 0, count = 0;

        for (int num : nums) {
            if (num == maxElement) {
                count++;
                res = max(res, count);
            } else {
                count = 0;
            }
        }

        return res;
    }
};
