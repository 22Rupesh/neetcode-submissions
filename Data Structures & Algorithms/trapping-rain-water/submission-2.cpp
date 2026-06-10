class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int water =0;
        for(int i=0;i<n;i++){
            int leftmax = 0;
            int rightmax = 0;
            for(int j=0;j<=i;j++){
                leftmax = max(leftmax,height[j]);
            }
            for(int j=i;j<n;j++){
                rightmax = max(rightmax, height[j]);
            }
            water += min(leftmax,rightmax)-height[i];
        }

        return water;
    }
};