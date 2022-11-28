class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans;
        set<int> st;
        
        for(int i=0;i<matches.size();i++){
            st.insert(matches[i][0]);
            st.insert(matches[i][1]);
        }
        
        map<int,int> mp;
        for(auto x:st){
            mp[x]=0;
        }
        
        for(int i=0;i<matches.size();i++){
            int val=matches[i][1];
            mp[val]++;
        }
        
        vector<int> temp1, temp2;
        for(auto it:mp){
            if(it.second==0){
                temp1.push_back(it.first);
            }
            if(it.second==1){
                temp2.push_back(it.first);
            }
        }
        ans.push_back(temp1);
        ans.push_back(temp2);
        return ans;
    }
};