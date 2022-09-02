class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int row[8]={1,-1,0,0,-1,-1,1,1};
        int col[8]={0,0,1,-1,-1,1,-1,1};
        if(grid[0][0]==1) return -1;
        if(grid[m-1][n-1]==1) return -1;
        if(m==1 and n==1 and grid[0][0]==0) return 1;
        
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({1,{0,0}});
        grid[0][0]=1;
        while(!pq.empty()){
            int dist=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
            
            for(int k=0;k<8;k++){
                int r = i + row[k];
                int c = j + col[k];
                if(r==(m-1) and (c==(n-1))) return dist+1;
                if(r>=0 and r<m and c>=0 and c<n and grid[r][c]==0){
                    grid[r][c]=1;
                    pq.push({dist+1,{r,c}});
                }
            }
        }
        return -1;
    }
};