class Solution(object):
    def canPlaceFlowers(self, flowerbed, n):
        count = 0
        length = len(flowerbed)
        
        for i in range(length):
            # check if the current plot is empty
            if flowerbed[i] == 0:
                # check if left and right neighbors are empty or out of bounds
                empty_left = (i == 0) or (flowerbed[i - 1] == 0)
                empty_right = (i == length - 1) or (flowerbed[i + 1] == 0)
                
                if empty_left and empty_right:
                    # plant a flower here
                    flowerbed[i] = 1
                    count += 1
                    # if we've already planted enough, we can stop early
                    if count >= n:
                        return True
                        
        return count >= n