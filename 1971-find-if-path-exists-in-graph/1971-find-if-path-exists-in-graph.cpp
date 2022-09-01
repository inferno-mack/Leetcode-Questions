class Solution {
public:
    bool dfs(int i, int j, vector<int> &vis, vector<int> adj[]){
        vis[i] = 1;
        bool f = false;
        for(auto it : adj[i]){
            if(!vis[it]){
                if(it == j) return true;
                f |= dfs(it, j, vis, adj);
            }
        }
        return f;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination) return true;
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int> vis(n,0);
        return dfs(source, destination, vis, adj);
    }
};