class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l1 = s1.size();
        int l2 = s2.size();

        if (l1 > l2) return false;

        int low = 0;
        int high = l1 - 1;

        while (high < l2) {
            string temp = s2.substr(low, l1);

            string a = s1;
            sort(a.begin(), a.end());
            sort(temp.begin(), temp.end());

            if (a == temp) {
                return true;
            }

            low++;
            high++;
        }

        return false;
    }
};