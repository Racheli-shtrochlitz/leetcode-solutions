class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> n;
        int count=0;

        n.push_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
             if (nums[i] != nums[i - 1]) {
                 n.push_back(nums[i]);
            }
        }

        for(int i=1;i<n.size()-1;i++){
            if(n[i]>n[i-1]&&n[i]>n[i+1])
                count++;
            else
                if(n[i]<n[i-1]&&n[i]<n[i+1])
                count++;

        }

        return count;
    }
};