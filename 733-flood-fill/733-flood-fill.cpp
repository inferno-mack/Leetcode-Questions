class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vector<vector<int>> vis(m,vector<int>(n,-1));
        while(!q.empty()){
            pair<int,int> p=q.front();
            int i=p.first, j=p.second;
            q.pop();
            
            vis[i][j]=1;
            if((i-1)>=0 and image[i-1][j]==image[i][j] and vis[i-1][j]==-1){
                // image[i-1][j]=color;
                q.push({i-1,j});
                vis[i-1][j]=1;
            }
            if((i+1)<m and image[i+1][j]==image[i][j] and vis[i+1][j]==-1){
                // image[i+1][j]=color;
                q.push({i+1,j});
                vis[i+1][j]=1;
            }
            if((j-1)>=0 and image[i][j-1]==image[i][j] and vis[i][j-1]==-1){
                // image[i][j-1]=color;
                q.push({i,j-1});
                vis[i][j-1]=1;
            }
            if((j+1)<n and image[i][j+1]==image[i][j] and vis[i][j+1]==-1){
                // image[i][j+1]=color;
                q.push({i,j+1});
                vis[i][j+1]=1;
            }
            image[i][j]=color;
        }
        return image;
    }
};