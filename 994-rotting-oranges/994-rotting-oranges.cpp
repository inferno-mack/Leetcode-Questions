class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2)
                    q.push({i,j});
            }
        }
        
        int ans=0;
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),1));
        while(!q.empty()){
            int length=q.size();
            ans++;
            
            while(length--){
                pair<int,int> p=q.front();
                q.pop();
                if((p.first-1)>=0 and grid[p.first-1][p.second]==1){
                    q.push({p.first-1,p.second});
                    grid[p.first-1][p.second]=-1;
                }     

                if((p.first+1)<grid.size() and grid[p.first+1][p.second]==1){
                    q.push({p.first+1,p.second});
                    grid[p.first+1][p.second]=-1;
                }     

                if((p.second-1)>=0 and grid[p.first][p.second-1]==1){
                    q.push({p.first,p.second-1});
                    grid[p.first][p.second-1]=-1;
                }     

                if((p.second+1)<grid[0].size() and grid[p.first][p.second+1]==1){
                    q.push({p.first,p.second+1});
                    grid[p.first][p.second+1]=-1;
                } 
            }
        }
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1)
                    return -1;
            }
        }
        
        if(ans!=0) return ans-1;
        return 0;
    }
};