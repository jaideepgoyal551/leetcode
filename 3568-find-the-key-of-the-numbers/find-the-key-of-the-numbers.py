class Solution:
    def generateKey(self, num1: int, num2: int, num3: int) -> int:
        a = str(num1).zfill(4)
        b = str(num2).zfill(4)
        c = str(num3).zfill(4)
        ans = ""
        for i in range(4):
            ans += str(min(int(a[i]),int(b[i]),int(c[i])))

        return int(ans)
        