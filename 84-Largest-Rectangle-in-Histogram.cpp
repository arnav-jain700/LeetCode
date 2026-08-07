class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        vector<int> stack;
        
        heights.push_back(0); 
        
        for (int i = 0; i < heights.size(); i++) {
            while (!stack.empty() && heights[stack.back()] > heights[i]) {
                int currentHeight = heights[stack.back()];
                stack.pop_back();

                int currentWidth = stack.empty() ? i : i - stack.back() - 1;
                
                maxArea = max(maxArea, currentHeight * currentWidth);
            }
            stack.push_back(i);
        }
        
        return maxArea;
    }
};