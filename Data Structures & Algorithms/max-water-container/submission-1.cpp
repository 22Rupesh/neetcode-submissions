class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int maxi = INT_MIN;

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {

                int amount = (j - i) * min(heights[i], heights[j]);

                maxi = max(maxi, amount);
            }
        }

        return maxi;
    }
};