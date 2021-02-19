#  Common elements | Easy | 3 companies
# Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.
# Note: can you take care of the duplicates without using any additional Data Structure?


class Solution:
    def commonElements (self,A, B, C, n1, n2, n3):
        # your code here
        sa = set(A)
        sb = set(B)
        sc = set(C)
        t = sa.intersection(sb)
        l = list(t.intersection(sc))
        l.sort()
        return l

t = int (input ())
for tc in range (t):
    n1, n2, n3 = list(map(int,input().split()))
    A = list(map(int,input().split()))
    B = list(map(int,input().split()))
    C = list(map(int,input().split()))
    
    ob = Solution()
    
    res = ob.commonElements (A, B, C, n1, n2, n3)
    
    if len (res) == 0:
        print (-1)
    else:
        for i in range (len (res)):
            print (res[i], end=" ")
        print ()

# } Driver Code Ends