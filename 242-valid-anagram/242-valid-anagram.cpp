class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        if(s==t)
            return true;
        
        unordered_map<char,int> mps, mpt;
        for(int i=0;i<s.size();i++)
            mps[s[i]]++;
        for(int i=0;i<t.size();i++)
            mpt[t[i]]++;
        
        for(auto x:mps)
            if(mpt[x.first]!=x.second)
                return false;
        return true;
    }
};