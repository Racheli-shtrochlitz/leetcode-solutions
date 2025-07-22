class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        int left=0,
        right=0,
        sum=0,
        maxVal=0;
        set<int> set;

        while(right<n){
            if(!set.count(nums[right])){
                sum+=nums[right];
                maxVal=max(maxVal,sum);
                set.insert(nums[right]);
                right++;
            }
            else{
                sum-=nums[left];
                set.erase(nums[left]);
                left++;
            }
        }
        return maxVal;
    }
};