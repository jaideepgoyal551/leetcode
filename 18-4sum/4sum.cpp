class Solution {
public:
       vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()) ;
        vector<vector<int>> result ;
        int n = nums.size() - 1 ;
        for (int i = 0 ; i <= n - 3 ; i++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue ;
            }
            int first = nums[i] ;
            for (int j = i + 1 ; j <= n - 2 ; j++) {
                if (j > i + 1 && nums[j] == nums[j-1]) {
                    continue ;
                }

                int second = nums[j] ;
                int left = j + 1 ;
                int right = n ;
                
                while (left < right) {
                    if (left > j + 1 && nums[left] == nums[left - 1]) {
                        left++ ;
                        continue ;
                    }
                    if (right < n - 1 && nums[right] == nums[right + 1]) {
                        right-- ;
                        continue ;
                    }
                    long total = (long) first + second + nums[left] + nums[right] ;
                    // if (totalM > INT_MAX || totalM < INT_MIN) {
                    //     break ;
                    // }
                    
                    // int total = first + second + nums[left] + nums[right] ;
                    if (total == target) {
                        vector<int> item = {first, second, nums[left], nums[right]} ;
                        result.push_back(item) ;
                        right-- ;
                        left++ ;
                    } else if (total > target) {
                        right-- ;
                    } else if (total < target) {
                        left++ ; 
                    }
                }
            }
        }

        return result ; 
    }
};