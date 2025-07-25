class Solution {
public:
    int maxSum(vector<int>& nums) {
        bool f=false;
        unordered_set<int> seen;
    int sum = 0;
    for (int num : nums) {
    if (num > 0 && seen.insert(num).second) {
        sum += num;
        f=true;
    }

}
    if(!f)
        return *max_element(nums.begin(), nums.end());

        return sum;
    }
};