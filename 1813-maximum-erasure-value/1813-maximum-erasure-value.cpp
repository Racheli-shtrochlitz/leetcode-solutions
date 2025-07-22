class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0;
        int sum = 0, maxVal = 0;
        vector<bool> seen(10001, false); // נניח המספרים עד 10^4

        while (right < n) {
            if (!seen[nums[right]]) {
                sum += nums[right];
                maxVal = max(maxVal, sum);
                seen[nums[right]] = true;
                right++;
            } else {
                sum -= nums[left];
                seen[nums[left]] = false;
                left++;
            }
        }

        return maxVal;
    }
};
