class Solution {
   public:
    int getMaxFreq(unordered_map<char, int>& f) {
        int maxi = 0;
        for (auto& it : f) {
            maxi = max(maxi, it.second);
        }
        return maxi;
    }

    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map<char, int> f;
        int res = INT_MIN;
        int low = 0;
        int high = 0;
        for (high = 0; high < n; high++) {
            f[s[high]]++;
            int len = high - low + 1;
            int maxcount = getMaxFreq(f);
            int diff = len - maxcount;
            while (diff > k) {
                f[s[low]]--;
                low++;

                len = high - low + 1;
                maxcount = getMaxFreq(f);
                 diff = len - maxcount; 
            }
            res = max(res, high - low + 1);
        }
        return res;
    }
};
