class Solution {
public:
    bool xorGame(vector<int>& nums) {
    int x = 0;
    for (int n : nums) x ^= n;
    return x == 0 || nums.size() % 2 == 0;
    }
};