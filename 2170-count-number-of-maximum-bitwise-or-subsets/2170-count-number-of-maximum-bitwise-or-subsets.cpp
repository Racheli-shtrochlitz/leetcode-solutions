class Solution {
public:
     void dfs(vector<int>& nums, int index, int currOr, int maxOr, int& count) {
    if (index == nums.size()) {
        if (currOr == maxOr) count++;
        return;
    }
    
    // כוללים את המספר הנוכחי
    dfs(nums, index + 1, currOr | nums[index], maxOr, count);

    // לא כוללים את המספר הנוכחי
    dfs(nums, index + 1, currOr, maxOr, count);
}


    int countMaxOrSubsets(vector<int>& nums) {

    int maxOr=0;
    int count=0;
    for(int i=0; i<nums.size(); i++){
        maxOr|=nums[i];
    }
    dfs(nums,0,0,maxOr,count);

    return count;

    }
};