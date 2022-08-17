class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto &it:nums){
            mp[it]++;
        }
        
        int ans=-1;
        for(auto it:mp){
            if(it.second==1){
                ans=it.first;
                break;
            }
        }
        return ans;
    }
};