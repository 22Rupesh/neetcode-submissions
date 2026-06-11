class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int low = 0;
        int high = 0;
        int maxi = INT_MIN;
        int count = 0;
        if(s == ""){
            return 0;
        }
        while(high < n){
            bool duplicate = false;
            for(int i=low; i<high ; i++){
                if(s[i] == s[high]){
                    duplicate = true;
                    low = i+1;
                    break;
                }
            }
            maxi = max(maxi, high-low+1);
            high++;
        }
        return maxi;

    }
};
