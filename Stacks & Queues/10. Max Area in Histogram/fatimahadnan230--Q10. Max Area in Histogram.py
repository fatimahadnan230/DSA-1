class Solution:
    def largestRectangleArea(self, heights: list[int]) -> int:
        stack = [] 
        max_area = 0
        # we add a 0 to the end to make sure the stack clears at the finish
        heights.append(0) 
        
        for i, h in enumerate(heights):
            # while current height is less than the height at the stack top
            while stack and heights[stack[-1]] >= h:
                height = heights[stack.pop()]
                # if stack is empty, it means this was the shortest bar so far
                width = i if not stack else i - stack[-1] - 1
                max_area = max(max_area, height * width)
            stack.append(i)
            
        # putting the list back to its original state
        heights.pop() 
        return max_area