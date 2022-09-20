class Solution {
public:
     struct cmp {
            bool operator()(const pair<int,string> &a, const pair<int,string> &b) {
                return (a.first == b.first) ? 
                    (a.second < b.second) : 
                    (a.first > b.first);
            };
        };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> mp;
        for(int i=0;i<words.size();i++)
            mp[words[i]]++;
        
        priority_queue<pair<int,string>, vector<pair<int,string>>,cmp> pq; 
        for(auto x:mp){
            if(pq.size()<k) pq.push({x.second, x.first});
            else if(x.second>pq.top().first){
                pq.pop();
                pq.push({x.second, x.first});
            }
        }
        
        vector<string> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};