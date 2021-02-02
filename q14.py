# Given an array of intervals where intervals[i] = [starti, endi], 
# merge all overlapping intervals, and return an array of the non-overlapping intervals 
# that cover all the intervals in the input.

# my code : works in 208 ms in leetcode
def overlapping(interval, next_interval):
    s1, e1 = interval[0], interval[1]
    s2 = next_interval[0]
    if s2>=s1 and s2<=e1:
        return True
    return False

def mergeSort(intervals,l,p,r):
    n1 = p-l+1
    n2 = r-p
    L,R = [],[]
    for i in range(n1):
        L.append(intervals[l+i])
    for j in range(n2):
        R.append(intervals[p+1+j])

    i,j,k = 0,0,l
    while(i<n1 and j<n2):
        if(L[i][0] <= R[j][0]):
            intervals[k] = L[i]
            i = i+1
        else:
            intervals[k] = R[j]
            j = j+1
        k = k+1

    while(i<n1):
        intervals[k] = L[i]
        i = i+1
        k = k+1

    while(j<n2):
        intervals[k] = R[j]
        j = j+1
        k = k+1
            
def sort(intervals,l,r):
    if(l<r):
        p = int((l+r)/2)
        sort(intervals,l,p)
        sort(intervals,p+1,r)
        mergeSort(intervals,l,p,r)


class Solution(object):

    def merge(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[List[int]]
        """
        sort(intervals,0,len(intervals)-1)
        int_index = 0
        while(int_index<len(intervals)-1):
            
            i = int_index+1
            while(i<len(intervals)):
                
                interval = intervals[int_index]
                start = interval[0]
                stop  = interval[1]
                next_interval = intervals[i]
                #print('interval, next : ',interval,next_interval)
                if overlapping(interval,next_interval):
                    stop = max(interval[1],next_interval[1])
                    intervals.remove(interval)
                    intervals.remove(next_interval)
                    intervals.insert(int_index,[start,stop])
                else:
                    i = i+1
            #print(intervals)
            int_index = int_index + 1


        return intervals

s = Solution()
intervals = [[1,4],[0,4]]
print(s.merge(intervals))

# Leetcode solution of 68 ms
# class Solution(object):
#     def merge(self, intervals):
#         """
#         :type intervals: List[List[int]]
#         :rtype: List[List[int]]
#         """
#         if len(intervals) <= 1:
#             return intervals
#         intervals = sorted(intervals) <<<<<<<<<<<<<<<<<<<<<<< highlight
#         current = intervals[0]
#         result = []
#         for i in range(1, len(intervals)):
#             next_interval = intervals[i]
#             if next_interval[0] > current[1]:
#                 result.append(current)
#                 current = next_interval
#             else:
#                 current = [current[0], max(current[1], next_interval[1])]
#         result.append(current)
#         return result