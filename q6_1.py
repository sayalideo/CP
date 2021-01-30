# Find the Union and Intersection of the two sorted arrays.
# this code contains intersection
# Learn map in cpp
#User function Template for python3

def NumberofElementsInIntersection(a, b, n, m):
    #return: expected length of the intersection array.
    sa = set(a)
    sb = set(b)
    return len(sa.intersection(sb))

        
if __name__=='__main__':
    t=int(input())
    for _ in range(t):
        
        n,m=[int(x) for x in input().strip().split()]
        
        a=[int(x) for x in input().strip().split()]
        b=[int(x) for x in input().strip().split()]
        
        
        print(NumberofElementsInIntersection(a,b,n,m))

#0.02