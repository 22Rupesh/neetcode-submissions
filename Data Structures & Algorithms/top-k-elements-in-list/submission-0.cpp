class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n= nums.size();
        unordered_map<int,int>hash;
        for(auto i:nums){
            hash[i]++;
        }
        vector<int>ans;
        while(k--){
            int maxhash = 0;
            int ele = 0;

            for(auto it : hash){
                if(it.second > maxhash){
                    maxhash = it.second;
                    ele = it.first;
                }
            }

            ans.push_back(ele);

            hash.erase(ele);
        }
        return ans;
    }
};
