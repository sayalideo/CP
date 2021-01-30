# Find the Union and Intersection of the two sorted arrays.

def doUnion(a,n,b,m):
    d = {}
    for i in a:
        d[i] = 1
    for j in b:
        d[j] = 1
    return len(d)
    #code here



#{ 
#  Driver Code Starts
#Initial Template for Python 3

#contributed by RavinderSinghPB
if __name__=='__main__':
    t=int(input())
    for _ in range(t):
        
        n,m=[int(x) for x in input().strip().split()]
        
        a=[int(x) for x in input().strip().split()]
        b=[int(x) for x in input().strip().split()]
        
        
        print(doUnion(a,n,b,m))
        
# 0.02
