#User function Template for python3
# Solution passes all test cases
class Solution:
    def getMinDiff(self, arr, n, k):
        arr.sort()
        mxs=[]
        mns=[]
        for i in arr:
            mxs.append(i+k)
            mns.append(i-k)
        ans=arr[-1]-arr[0]
        for i in range(1,n):
            if(mns[i]>=0):
                ans=min(ans,max(mns[n-1],mxs[i-1])-min(mns[i],mxs[0]))
        return ans


#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        k = int(input())
        n = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.getMinDiff(arr, n, k)
        print(ans)
        tc -= 1

# } Driver Code Ends