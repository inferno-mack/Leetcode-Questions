class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>>graph(n+1,vector<int>(n+1,1e9));
        for(auto&edge:times)
            graph[edge[0]][edge[1]] = edge[2];
        for(int i=1;i<=n;i++)
            graph[i][i] = 0;
        for(int k=1;k<=n;k++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    graph[i][j] = min(graph[i][j],graph[i][k]+graph[k][j]);
        int result = 0;
        for(int i=1;i<=n;i++){
            if(graph[k][i]==1e9)
                return -1;
            result = max(result,graph[k][i]);
        }
        return result;
    }
};