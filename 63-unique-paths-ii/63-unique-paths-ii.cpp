class Solution {
public:
    int f(int i, int j, vector<vector<int>> grid,vector<vector<int>> &dp){
        if(i>=0 and j>=0 and grid[i][j]==1) return 0;
        if(i<0 or j<0) return 0;
        if(i==0 and j==0) return 1;
        
        if(dp[i][j]!=-1) return dp[i][j];
        int up=f(i-1,j,grid,dp);
        int left=f(i,j-1,grid,dp);
        return dp[i][j]=up+left;
    }
    
    int uniquePathsWithObstacles(vector<vector<int> > &grid) {
        int m = grid.size() , n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
       return  f(m-1,n-1,grid,dp);
    }
};