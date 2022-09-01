class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& course) {
        vector<vector<int>> adj(n);
        queue<int> q;
        for(int i=0;i<course.size();i++){
            adj[course[i][1]].push_back(course[i][0]);
        }
        
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++){
            for(auto it:adj[i])
                indegree[it]++;
        }
        
        for(int i=0;i<indegree.size();i++)
            if(indegree[i]==0)
                q.push(i);
        
        int count=0;
        vector<int> ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        
        if(ans.size()==n) return ans;
        return {};
    }
};