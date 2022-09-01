class Solution {
public:
    bool dfs(int node, vector<int> &vis, vector<vector<int>> &graph, vector<bool> &check){
        
        vis[node]=1;
        bool flag=true;
        
        for(auto it:graph[node]){
            if(!vis[it]){
                if(dfs(it, vis, graph, check) == false)
                    flag = false;
            }
            else flag = flag and check[it];
        }
        return check[node] = flag;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,0);
        vector<bool> check(n,false);
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(!vis[i])
                dfs(i, vis, graph, check);
        }
        for(int i = 0; i < n; i++){
            if(check[i] == true) ans.push_back(i);
        }
        return ans;
    }
};