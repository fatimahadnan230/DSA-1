class Solution(object):
    def maxCoins(self, nums):
        # step 1: pad the array with 1s at both ends
        balloons = [1] + [x for x in nums if x >= 0] + [1]
        # create a dictionary to store our calculated results (memoization)
        memo = {}
        
        def dp(left, right):
            # check if we have already calculated this range
            if (left, right) in memo:
                return memo[(left, right)]
            
            # base case: no balloons to burst in between
            if left + 1 >= right:
                return 0
            
            best = 0
            # pick balloon 'i' to be the last one burst in range (left, right)
            for i in range(left + 1, right):
                # calculate coins based on the last balloon logic
                coins = balloons[left] * balloons[i] * balloons[right]
                # add results from left and right sub-problems
                total = coins + dp(left, i) + dp(i, right)
                if total > best:
                    best = total
            
            # save the result in memo before returning
            memo[(left, right)] = best
            return best
        
        # start solving for the full range
        return dp(0, len(balloons) - 1)