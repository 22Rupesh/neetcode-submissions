class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need;
        unordered_map<char, int> have;

        for (int i = 0; i < t.size(); i++) {
            need[t[i]]++;
        }

        int lengthNeed = need.size();
        int lengthHave = 0;

        int left = 0;
        int res = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            have[c]++;

            if (need.count(c) && have[c] == need[c]) {
                lengthHave++;
            }

            while (lengthHave == lengthNeed) {
                if (right - left + 1 < res) {
                    res = right - left + 1;
                    start = left;
                }

                have[s[left]]--;

                if (need.count(s[left]) &&
                    have[s[left]] < need[s[left]]) {
                    lengthHave--;
                }

                left++;
            }
        }

        return res == INT_MAX ? "" : s.substr(start, res);
    }
};