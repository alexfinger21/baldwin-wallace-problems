class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size());

        int max_jump = nums[0];
        int idx = 0;

        while (max_jump > 0 && idx < nums.size() - 1) {
            ++idx;
            max_jump = max(max_jump - 1, nums[idx]);
        }

        return idx == nums.size() - 1;
    }
};
