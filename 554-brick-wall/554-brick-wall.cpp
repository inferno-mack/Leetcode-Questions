class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        map<int,int> mp;
        int last;
        
        for(int i=0;i<wall.size();i++){
            vector<int> temp(wall[i].size());
            temp[0]=wall[i][0];
            mp[temp[0]]++;
            for(int j=1;j<wall[i].size();j++){
                temp[j]=temp[j-1]+wall[i][j];
                mp[temp[j]]++;
            }
            last=temp[temp.size()-1];
        }
        
        int mx=0;
        for(auto x:mp)
            if(x.second>mx and x.first!=last)
                mx=max(mx,x.second);
        
        return (wall.size()-mx);
    }  
};