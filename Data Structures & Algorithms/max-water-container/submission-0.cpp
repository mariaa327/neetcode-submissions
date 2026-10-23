class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = (int)heights.size() - 1;

        int maxArea = 0;

        while(left < right){
            int width = right - left;
            int height;

            if(heights[left] >= heights[right]) height = heights[right];
            else height = heights[left];

            int area = height * width;

            if(area > maxArea) maxArea = area;

            if(heights[left] < heights[right]) left++;
            else right--;
        }

        return maxArea;

    }
};
