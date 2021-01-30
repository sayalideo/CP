# Given an array arr of N integers. Find the contiguous sub-array with maximum sum.
# Kadane's Algorithm | 21 company tags | arrays, DP

#User function Template for python3

# Complete this function
def maxSubArraySum(a,size):
    ##Your code here
    curr_max, max_so_far = a[0],a[0]
    for i in range(1,size):
        curr_max = max(a[i],curr_max+a[i])
        max_so_far = max(max_so_far,curr_max)
    return curr_max 


import math
 
def main():
        T=int(input())
        while(T>0):
            
            n=int(input())
            
            arr=[int(x) for x in input().strip().split()]
            
            print(maxSubArraySum(arr,n))
            
            T-=1


if __name__ == "__main__":
    main()

# 0.71