#define ll long long int
#define max(x,y) (x >= y ? x : y)
#define min(x,y) (x <= y ? x : y)

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n < 3) return 0;
        int left[n], right[n], water = 0;
        leftHeight[0] = height[0]; rightHeight[n-1] = height[n-1];
        for(int i=1;i<n;i++) leftHeight[i] = max(leftHeight[i-1], height[i]);
        for(int i=n-2;i>=0;i--) rightHeight[i] = max(rightHeight[i+1], height[i]);
        // Find the min of leftHeight & rightHeight & subtract with the current height to get the current water level
        for(int i=0;i<n;i++) 
            water += (min(leftHeight[i], rightHeight[i]) - height[i]);
        return water;
    }
};