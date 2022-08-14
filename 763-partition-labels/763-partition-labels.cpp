class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]=i;
        }
        vector<int> ans;
        int size=0,end=0;
        for(int i=0;i<s.size();i++){
            if(mp[s[i]]>end){
                end=mp[s[i]];
            }
            size++;
            if(i==end){
                ans.push_back(size);
                size=0;
            }
        }
        
        return ans;
    }
};