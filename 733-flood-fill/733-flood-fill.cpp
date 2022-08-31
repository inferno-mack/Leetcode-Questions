class Solution {
public:
    void dfs(vector<vector<int>> &grid, vector<vector<int>> &vis, int i, int j, int m, int n, int color){
        vis[i][j]=1;
        if((i-1)>=0 and grid[i-1][j]==grid[i][j] and vis[i-1][j]==-1)
            dfs(grid, vis, i-1, j, m, n, color);
        if((i+1)<m and grid[i+1][j]==grid[i][j] and vis[i+1][j]==-1)
            dfs(grid, vis, i+1, j, m, n, color);
        if((j-1)>=0 and grid[i][j-1]==grid[i][j] and vis[i][j-1]==-1)
            dfs(grid, vis, i, j-1, m, n, color);
        if((j+1)<n and grid[i][j+1]==grid[i][j] and vis[i][j+1]==-1)
            dfs(grid, vis, i, j+1, m, n, color);
        grid[i][j]=color;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        vector<vector<int>> vis(m,vector<int>(n,-1));
        dfs(image, vis, sr, sc, m, n, color);
        return image;
    }
};