# Best Time to Buy and Sell Stock
# You are given an array prices where prices[i] is the price of a given stock on the ith day.
# You want to maximize your profit by choosing a single day to buy one stock and 
# choosing a different day in the future to sell that stock.

# Return the maximum profit you can achieve from this transaction. 
# If you cannot achieve any profit, return 0.

class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        ****************************************************
        My code runs in O(n^2) while code below runs in O(n)
        a = prices.copy()
        a.sort(reverse=True)
        if prices == a:
            return 0

        mi,profit = 0,0
        n = len(prices)
        for i in range(0,n-1):
            if prices[i] > prices[mi]:
                continue
            mx = i+1
            mi = i
            for j in range(i+1,n):
                if (prices[j] > prices[i]) and (prices[j] > prices[mx]):
                    # print('here ',prices[i],prices[j])
                    mx = j
            p = prices[mx] - prices[mi]
            # print('p',p)
            if p > profit:
                profit = p
        return profit"""

        buy = prices[0]
        mx_profit = 0
    
        for i in range(1,len(prices)):
            profit = prices[i]-buy
    
            if profit>mx_profit:
                mx_profit = profit
        
            if buy>prices[i]:
                buy = prices[i]
    
        return mx_profit        

prices = [7,1,5,3,6,4]
s = Solution()
print(s.maxProfit(prices))