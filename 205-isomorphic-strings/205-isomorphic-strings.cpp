class Solution {
public:
    bool solve(string s, string t){
        map<int,int> mp;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])!=mp.end()){
                if(mp[s[i]]!=t[i]) return false;
            }        
            else mp[s[i]]=t[i];
        }
        return true;
    }
    
    bool isIsomorphic(string s, string t) {
        return solve(s,t) && solve(t,s);
    }
};