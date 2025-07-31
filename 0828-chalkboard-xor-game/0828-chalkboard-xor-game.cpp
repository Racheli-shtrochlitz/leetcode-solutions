class Solution {
public:
    bool xorGame(vector<int>& nums) {
    int x=0;
    for(int n:nums) x^=n;
    unordered_set<int> s(nums.begin(), nums.end());
    return x==0 || nums.size() % 2 == (s.size()*2) % 2;
    }
};