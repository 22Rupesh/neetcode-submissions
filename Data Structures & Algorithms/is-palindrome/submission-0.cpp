class Solution {
public:
    bool isPalindrome(string s) {
        string cleaned = "";

        for(int i = 0; i < s.size(); i++) {
            if(isalnum(s[i])) {
                cleaned += tolower(s[i]);
            }
        }

        string rev = cleaned;
        reverse(rev.begin(), rev.end());

        if(cleaned == rev) {
            return true;
        }
        else {
            return false;
        }
    }
};