class Solution {
public:
    string removeOuterParentheses(string s) {
        vector<string> temp;
        int lo=0,hi=0;
        int ind=-1;
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
                lo++;
            else if(s[i]==')')
                hi+=1;
            
            if(lo==hi)
            {
                temp.push_back(s.substr(ind+1,i-ind));
                ind=i;
                lo=0;
                hi=0;
            }
        }
        
        
        for(int i=0;i<temp.size();i++)
        {
            cout<<temp[i]<<" ";
            string str=temp[i];
            ans+=str.substr(1,str.size()-2);
        }
        
        return ans;
    }
};