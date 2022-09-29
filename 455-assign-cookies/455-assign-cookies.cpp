class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans=0;
        map<int,int> mp;
        for(auto &it:s)
            mp[it]++;
        
        for(auto &it:g){
            auto itr=mp.lower_bound(it);
            if(itr!=mp.end()){
            (itr->second--);
            ans++;    
            if((*itr).second==0)
                mp.erase((*itr).first);
            }
        }
        return ans;
    }
};