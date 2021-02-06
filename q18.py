#User function Template for python
import math
class Solution:
    def getPairsCount(self, arr, n, k):
        # code here
        h = dict()
        for i in arr:
            if h.get(i):
                h[i] += 1
            else:
                h[i] = 1

        count = 0 # contains number of elements
        for i in arr:
            if h.get(k-i):
                count += h[k-i]
                if k-i == i : #i.e. if k=2 and i==1 and h[1] = 1 then no pair shud be counted
                    count -= 1
# if arr = [1,1,1], then count=3+3+3 w/o line 18, now it is 2+2+2 = 6 elements i.e. 3 pairs

                
        return int(count/2) # returns number of pairs

            
ob = Solution()
ans = ob.getPairsCount([75, 99, 56, 24, 9, 51, 64, 79, 1, 36, 73, 27, 28, 8, 1], 15, 16)
print(ans)