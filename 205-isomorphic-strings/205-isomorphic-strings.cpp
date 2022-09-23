class Solution {
public:
    bool isIsomorphic(string pattern, string s) {
        unordered_map<char, char> mp;
        unordered_map<char, char> mp1;
        for(int i=0;i<pattern.size();i++){
            if(mp.count(pattern[i]) && mp1.count(s[i])){
                if(mp[pattern[i]]!=s[i] || mp1[s[i]]!=pattern[i])
                    return false;
            }
            else if(mp.count(pattern[i])==false && mp1.count(s[i])==false){
                mp[pattern[i]]=s[i];
                mp1[s[i]]=pattern[i];
            }
            else
                return false;
        }
        return true;
    }
};