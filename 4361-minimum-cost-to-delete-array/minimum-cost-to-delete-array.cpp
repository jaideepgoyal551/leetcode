class Solution {
public:
    long long minCost(vector<int>& nums) {
        int n = nums.size() ;
        long long ans = nums[0] + nums[n - 1] ;
        sort(nums.begin() + 1 , nums.end() - 1);
        for(int i = 1 ; i < n - 1 ; i+=2 ) {

            if(nums[i] + nums[i + 1] < 0 && i + 1 != n - 1) {
                ans += nums[i] + nums[i + 1] ;
            } 
        }

        return ans ;
        
    }
};