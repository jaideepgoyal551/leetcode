class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int curmax = nums[0];

        for (int i = 1; i < n; i++) {
            ans = max(ans, (curmax - 1) * (nums[i] - 1));
            curmax = max(curmax, nums[i]);
        }

        return ans;
    }
};