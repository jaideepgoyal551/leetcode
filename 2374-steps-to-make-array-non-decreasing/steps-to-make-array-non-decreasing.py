class Solution:
    def totalSteps(self, nums):
        stack = []
        ans = 0

        for x in reversed(nums):
            steps = 0

            while stack and x > stack[-1][0]:
                steps = max(steps + 1, stack[-1][1])
                stack.pop()

            ans = max(ans, steps)
            stack.append((x, steps))

        return ans

        