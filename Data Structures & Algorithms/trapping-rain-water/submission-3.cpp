
// this is o(n^2)

// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n = height.size();
//         int water =0;
//         for(int i=0;i<n;i++){
//             int leftmax = 0;
//             int rightmax = 0;
//             for(int j=0;j<=i;j++){
//                 leftmax = max(leftmax,height[j]);
//             }
//             for(int j=i;j<n;j++){
//                 rightmax = max(rightmax, height[j]);
//             }
//             water += min(leftmax,rightmax)-height[i];
//         }

//         return water;
//     }
// };



// this is o(n)


class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> leftMax(n);
        vector<int> rightMax(n);

        // Fill leftMax
        leftMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }

        // Fill rightMax
        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }

        int water = 0;

        // Calculate trapped water
        for (int i = 0; i < n; i++) {
            water += min(leftMax[i], rightMax[i]) - height[i];
        }

        return water;
    }
};