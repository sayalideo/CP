#  Given an array which consists of only 0, 1 and 2. Sort the array without using any sorting algo
#User function Template for python3

def sort012(arr,n):
    # code here
    z,o,t = 0,0,0
    for i in arr:
        if i==0:
            z = z+1
        elif i==1:
            o = o+1
        else:
            t = t+1
    for i in range(n):
        if z:
            arr[i] = 0
            z = z-1
        elif o:
            arr[i] = 1
            o = o-1
        else:
            arr[i] = 2
            t = t-1

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t=int(input())
    for _ in range(t):
        n=int(input())
        arr=[int(x) for x in input().strip().split()]
        sort012(arr,n)
        for i in arr:
            print(i, end=' ')
        print()

# } Driver Code Ends