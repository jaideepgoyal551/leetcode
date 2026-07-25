class Solution:
    def canSeePersonsCount(self, heights):
        n = len(heights)

        # ans[i] = number of people visible from person i
        ans = [0] * n

        # Monotonic decreasing stack
        # Stores heights of people to the right
        stack = []

        # Traverse from right to left
        for i in range(n - 1, -1, -1):

            count = 0

            # Current person can see all shorter people
            while stack and heights[i] > stack[-1]:
                stack.pop()
                count += 1

            # If a taller or equal person exists,
            # current person can see exactly one more person
            if stack:
                count += 1

            # Store answer for current person
            ans[i] = count

            # Add current person's height to stack
            stack.append(heights[i])

        return ans
