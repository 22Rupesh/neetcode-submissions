class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int low = 0;
        int high = k-1;
        vector<int>ans;
        
        while(high < nums.size()){
            int maxi = INT_MIN;
            for(int i=low; i<=high; i++){
                
                maxi = max(maxi,nums[i]);
            }
            ans.push_back(maxi);
            low++;
            high++;
        }
        return ans;
    }
};
