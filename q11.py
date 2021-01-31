# Given an array of integers nums containing n + 1 integers 
# where each integer is in the range [1, n] inclusive.
# There is only one repeated number in nums, return this repeated number.
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        a = nums.copy()
        a.sort()
        for i in range(len(a)-1):
            if a[i] == a[i+1]:
                return a[i]