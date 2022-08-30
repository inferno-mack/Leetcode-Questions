class Solution {
public:
    int findCircleNum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> adj(n+1);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(matrix[i-1][j-1]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        int ans=0;
        vector<int> vis(n+1,0);
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                ans++;
                queue<int> q;
                q.push(i);
                vis[i]=1;
                
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    for(auto it:adj[node]){
                        if(!vis[it]){
                            q.push(it);
                            vis[it]=1;
                        }
                    }
                }
            }
        }
        return ans;
    }
};