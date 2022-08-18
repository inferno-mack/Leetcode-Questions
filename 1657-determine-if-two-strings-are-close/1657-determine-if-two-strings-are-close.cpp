class Solution {
public:
    bool closeStrings(string s, string t) {
        if(s.size()!=t.size()) return false;
        
        map<char,int> mps, mpt;
        for(auto &it:s){
            mps[it]++;
        }
        
        for(auto &it:t){
            mpt[it]++;
        }
        
        for(auto it=mps.begin(); it!=mps.end(); it++){
            if(mpt.find(it->first)==mpt.end()) return false;
        }
        
        vector<int> vs,vt;
        for(auto it:mps)
            vs.push_back(it.second);
        sort(vs.begin(),vs.end());
        
        for(auto it:mpt)
            vt.push_back(it.second);
        sort(vt.begin(),vt.end());
        
        bool flag=false;
        for(int i=0;i<vs.size();i++){
            if(vs[i]!=vt[i]){
                flag=true;
                break;
            }
        }
        
        if(flag) return false;
        return true;
    }
};