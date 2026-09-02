class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mp = {}
        n = len(nums)
        for i in range(n) :
            comp = target - nums[i]
            if comp in mp :
                return [mp[comp] , i]
            mp[nums[i]] = i
        return []
        