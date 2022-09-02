class Solution {
public:
    void dfs(int i, int j, vector<vector<char>> &grid, vector<vector<int>> &vis){
        vis[i][j]=2;
        if((i-1)>=0 and vis[i-1][j]==-1 and grid[i-1][j]=='1')
            dfs(i-1,j,grid,vis);
        if((i+1)<grid.size() and vis[i+1][j]==-1 and grid[i+1][j]=='1')
            dfs(i+1,j,grid,vis);
        if((j-1)>=0 and vis[i][j-1]==-1 and grid[i][j-1]=='1')
            dfs(i,j-1,grid,vis); 
        if((j+1)<grid[0].size() and vis[i][j+1]==-1 and grid[i][j+1]=='1')
            dfs(i,j+1,grid,vis); 
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,-1));
        int ans=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==-1 and grid[i][j]=='1'){
                    ans++;
                    dfs(i, j, grid, vis);
                }
            }
        }
        return ans;
    }
};