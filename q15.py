# Next Permutation
# Implement next permutation, which rearranges numbers into the lexicographically 
# next greater permutation of numbers. If such an arrangement is not possible, 
# it must rearrange it as the lowest possible order (i.e., sorted in ascending order).
# The replacement must be in place and use only constant extra memory.
# Input: nums = [1,2,3]
# Output: [1,3,2]

# Example 2:

# Input: nums = [3,2,1]
# Output: [1,2,3]

# Example 3:

# Input: nums = [1,1,5]
# Output: [1,5,1]

# Example 4:

# Input: nums = [1]
# Output: [1]

# My code : 213 / 265 test cases passed.
# Not passed
# Input: [4,2,0,2,3,2,0]
# Output: [4,2,2,0,0,2,3]
# Expected: [4,2,0,3,0,2,2]

# def sort_part(nums,l,r):
#     n = r-1+1

#     for i in range(l,l+n-1):
#         for j in range(l,l+n-i):
#             if nums[j] > nums[j+1]:
#                 temp = nums[j]
#                 nums[j] = nums[j+1]
#                 nums[j+1] = temp

# class Solution(object):
#     def nextPermutation(self, nums):
#         """
#         :type nums: List[int]
#         :rtype: None Do not return anything, modify nums in-place instead.
#         """
#         flag = 0
#         for i in range(len(nums)-1,0,-1):
#             m = i-1
#             for j in range(i-1,-1,-1):
#                 if nums[j] < nums[i]:
#                     temp = nums[i]
#                     nums[i] = nums[j]
#                     nums[j] = temp
#                     #if not(j == i-1 or j+1 == i-1):
#                     sort_part(nums,j+1,len(nums)-1)
#                     flag = 1
#                     break
#                 elif nums[j] == nums[i]:
                    
#                     temp = nums[j]
#                     nums[j] = nums[m]
#                     nums[m] = temp
#                     print('h ',nums)
#                     sort_part(nums,j+1,len(nums)-1)
#                     flag = 1
#                     break
#                 else:
#                     if nums[j]<nums[m]:
#                         m = j
                        
#             if flag == 1:
#                 break
#         if flag==0:
#             nums.sort()


# ******************************************************************************



# Explaination
# First, we observe that for any given sequence that is in descending order, 
# no next larger permutation is possible. For example, no next permutation is possible 
# for the following array:

# [9, 5, 4, 3, 1]

# We need to find the first pair of two successive numbers a[i] and a[i−1], from the right, 
# which satisfy a[i]>a[i−1]. Now, no rearrangements to the right of a[i−1] 
# can create a larger permutation since that subarray consists of numbers in descending order. 
# Thus, we need to rearrange the numbers to the right of a[i−1] including itself.

# Now, what kind of rearrangement will produce the next larger number? 
# We want to create the permutation just larger than the current one. 
# Therefore, we need to replace the number a[i−1] with the number which is just larger than itself 
# among the numbers lying to its right section, say a[j].

# We swap the numbers a[i−1] and a[j]. We now have the correct number at index i−1. 
# But still the current permutation isn't the permutation that we are looking for. 
# We need the smallest permutation that can be formed by using the numbers only to the 
# right of a[i−1]. Therefore, we need to place those numbers in ascending order to get their 
# smallest permutation.

# But, recall that while scanning the numbers from the right, we simply kept decrementing the index 
# until we found the pair a[i] and a[i−1] where, a[i]>a[i−1]. Thus, all numbers 
# to the right of a[i−1] were already sorted in descending order. Furthermore, 
# swapping a[i−1] and a[j] didn't change that order. Therefore, we simply need to reverse the numbers 
# following a[i−1] to get the next smallest lexicographic permutation.

def sort_part(nums,l,r):
    n = r-1+1
    for i in range(l,l+n-1):
        for j in range(l,l+n-i):
            if nums[j] > nums[j+1]:
                temp = nums[j]
                nums[j] = nums[j+1]
                nums[j+1] = temp

class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        flag = 0
        for i in range(len(nums)-1,0,-1):
            if(nums[i-1]<nums[i]):
                m = i
                for j in range(i+1,len(nums)):
                    if(nums[j]>nums[i-1] and nums[j]<nums[m]):
                        m = j
                #print(nums)
                temp = nums[i-1]
                nums[i-1] = nums[m]
                nums[m] = temp
                #print(nums)
                sort_part(nums,i,len(nums)-1)
                flag = 1
                break
        if flag==0:
            nums.sort()

s = Solution()
nums = [4,2,0,2,3,2,0]
s.nextPermutation(nums)
print(nums)               