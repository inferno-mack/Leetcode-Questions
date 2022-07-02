class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> ans;
        int n=s.size();
        int i=0,j=n;
        
        for(int k=0;k<s.size();k++)
        {
            if(s[k]=='I')
            {
                ans.push_back(i);
                i++;
            }
            else
            {
                ans.push_back(j);
                j--;
            }
        }
        ans.push_back(i);
        
        return ans;
    }
};