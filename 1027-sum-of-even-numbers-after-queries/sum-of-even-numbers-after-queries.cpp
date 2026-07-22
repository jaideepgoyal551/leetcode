class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {

        int n = queries.size();
        vector<int>ans;

        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                sum += nums[i];
            }
        }
        for (int i = 0; i < n; i++) {
            int idx = queries[i][1];
            int old = nums[idx];
            nums[idx] += queries[i][0];
            if (old % 2 == 0) {
                sum -= old;
            }
            sum += (nums[idx] % 2 == 0 ) ? nums[idx] : 0;
            ans.push_back(sum);
        }
        return ans;

    }
};