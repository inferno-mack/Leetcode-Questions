class Solution {
public:
    string truncateSentence(string s, int k) {
        int ind=0;
        string ans="";
        while(ind<s.size() and k>0){
            if(s[ind]!=' ')
                ans+=s[ind];
            else{
                k--;
                if(k!=0)
                     ans+=' ';
            }
            ind++;
        }
        return ans;
    }
};