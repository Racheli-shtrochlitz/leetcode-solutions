class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        int or_val = 0;
        vector<int> last_seen(32, -1); // לכל ביט 0-31

        for (int i = n - 1; i >= 0; i--) {
            for (int bit = 0; bit < 32; bit++) {
                if (nums[i] & (1 << bit)) {
                    last_seen[bit] = i;
                }
            }

            int max_pos = i;
            for (int bit = 0; bit < 32; bit++) {
                if (last_seen[bit] != -1) {
                    max_pos = max(max_pos, last_seen[bit]);
                }
            }

            res[i] = max_pos - i + 1;
        }

        return res;
    }
};
