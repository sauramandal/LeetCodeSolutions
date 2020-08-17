#define max(x,y) (x>=y ? x : y)
#define min(x,y) (x<=y ? x : y)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = -1000000;
        int i = 0, j = height.size()-1;
        while(i<j) {
            maxArea = max(maxArea, (j-i) * min(height[i], height[j]));
            if(height[i]<height[j]) i++;
            else j--;
        }
        return maxArea;
    }
};