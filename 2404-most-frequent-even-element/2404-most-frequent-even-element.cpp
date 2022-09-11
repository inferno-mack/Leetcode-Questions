class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int, int> mp;
        for(auto it:nums){
            if(it%2==0)
                mp[it]++;
        }
        
        if(mp.size()==0)
            return -1;
        int ans=-1, freq=0;
        for(auto it:mp){
            if(it.second > freq){
                ans=it.first;
                freq=it.second;
            }
        }
        return ans;
    }
};