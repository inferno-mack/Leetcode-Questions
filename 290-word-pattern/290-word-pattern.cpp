class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> vec;
        string temp="";
        for(int i=0;i<s.size();i++){
            while(s[i]!=' ' and i<s.size()){
                temp+=s[i];
                i++;
            }
            vec.push_back(temp);
            temp="";
        }
        
        if(vec.size()!=pattern.size())
            return false;
        
        unordered_map<char, string> mp;
        unordered_map<string, char> mp1;
        for(int i=0;i<pattern.size();i++){
            if(mp.count(pattern[i]) && mp1.count(vec[i])){
                if(mp[pattern[i]]!=vec[i] || mp1[vec[i]]!=pattern[i])
                    return false;
            }
            else if(mp.count(pattern[i])==false && mp1.count(vec[i])==false){
                mp[pattern[i]]=vec[i];
                mp1[vec[i]]=pattern[i];
            }
            else
                return false;
        }
        return true;
    }
};