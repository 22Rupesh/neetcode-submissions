class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       
        // sort(nums.begin(),nums.end());
        unordered_set<int>s(nums.begin(),nums.end());
        int longest = 0;

        for(int i=0;i<nums.size();i++){
            int n = nums[i];
            // // Check if n is the start of a sequence
            if(s.find(n-1) == s.end()){
                int length = 0;
                while(s.find(n+length) != s.end()){
                    length++;
                }
                longest = max(longest,length);
            }
        }
        return longest;
    }
};
