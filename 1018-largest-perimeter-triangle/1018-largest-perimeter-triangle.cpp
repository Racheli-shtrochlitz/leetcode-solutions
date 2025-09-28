class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int sum=0;
        sort(nums.begin(), nums.end(), greater<int>());
        for(int i=0; i<nums.size()-2; i++){
            if(nums[i+1]==0) return 0;
            if(nums[i]<nums[i+1]+nums[i+2]){
                return nums[i]+nums[i+1]+nums[i+2];
            }
        }
        return 0;
    }
};