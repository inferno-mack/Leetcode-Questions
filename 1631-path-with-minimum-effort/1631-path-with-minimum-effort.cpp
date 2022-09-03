class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<int> maxdiff;
        int m=heights.size();
        int n=heights[0].size();
        int row[4]={-1,1,0,0};
        int col[4]={0,0,-1,1};
        if(m == 1 and n==1) return 0;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> eff(m,vector<int>(n,INT_MAX));
        eff[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int effort=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
            for(int k=0;k<4;k++){
                int r = i + row[k];
                int c = j + col[k];
                if(r>=0 and r<m and c>=0 and c<n){
                    if(eff[r][c]>max(effort,abs(heights[i][j]-heights[r][c]))){
                        eff[r][c]=max(effort,abs(heights[i][j]-heights[r][c]));
                        pq.push({eff[r][c],{r,c}});
                    }
                }
            }
        }
        return eff[m-1][n-1];
    }
};