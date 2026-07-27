class Solution:
    def maxProfit(self, prices):
        min_price = prices[0]
        ans = 0

        for i in range(1, len(prices)):
            ans = max(ans, prices[i] - min_price)
            min_price = min(min_price, prices[i])

        return ans
