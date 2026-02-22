#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();
        
        for (int i = 0; i <= n; i++) {
            // treat the "past the end" element as height 0
            int currentHeight = (i == n) ? 0 : heights[i];
            
            while (!st.empty() && heights[st.top()] >= currentHeight) {
                int h = heights[st.top()];
                st.pop();
                
                int w = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, h * w);
            }
            st.push(i);
        }
        
        return maxArea;
    }
};