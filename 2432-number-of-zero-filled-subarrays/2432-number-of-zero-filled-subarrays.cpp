class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count=0, sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                count++;
            }
            else{
                sum+=count*(count+1)/2;
                count=0;
            }
        }
        return sum+(count*(count+1)/2);
    }
};