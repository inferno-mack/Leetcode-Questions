class Solution {
public:
    
    bool checkbipartitedfs(int node, vector<int> &color, vector<int> adj[]){
        if(color[node]==-1) color[node]=1;
        
        for(auto it:adj[node]){
            if(color[it]==-1){
                color[it]=1-color[node];
                if(!checkbipartitedfs(it, color, adj)) return false;
            }
            else if(color[it] == color[node]) return false;
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> adj[n];
	    for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
        }
        
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i] == -1){
                if(!checkbipartitedfs(i, color, adj)) return false;
            }
        }  
        return true;
    }
};