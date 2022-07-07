class Solution {
public:
    
    bool bipartitebfs(int node, vector<int> &color, vector<int> adj[]){
        queue<int> q;
        q.push(node);
        color[node]=1;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            
            for(auto it: adj[curr]){
                if(color[it] == -1){
                    color[it] = 1 - color[curr];
                    q.push(it);
                }
                else if(color[it] == color[curr]) return false;
            }
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
                if(!bipartitebfs(i, color, adj)) return false;
            }
        }
        return true;
    }
};