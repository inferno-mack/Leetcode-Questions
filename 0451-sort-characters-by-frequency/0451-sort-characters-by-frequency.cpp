class Solution {
public:
    string frequencySort(string s) {
        string ans;
        unordered_map<char,int> hash;
        for(int i=0;i<s.size();i++)
            hash[s[i]]++;
        
        priority_queue<pair<int,char>> maxHeap;
        for(auto x : hash){
            maxHeap.push({x.second, x.first});
        }
        
        while(!maxHeap.empty()){
            pair<int, char> top = maxHeap.top();
            maxHeap.pop();
            
            for(int i=1;i<=top.first;i++)
                ans+=top.second;
        }
        return ans;
    }
};