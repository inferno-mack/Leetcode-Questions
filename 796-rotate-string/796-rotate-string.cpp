class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size())
            return false;
        if(s==goal) 
            return true;
        
        char ch=goal[0];
        int n=s.size();
        int ind=-1;
        for(int i=0;i<s.size();i++){
            if(ch==s[i]){
                string temp1=s.substr(i,n-i);
                string temp2=goal.substr(0,n-i);
                if(temp1==temp2){
                    ind=i;
                    break;
                }
            }
        }
        
        if(ind==-1)
            return false;
        string s1=s.substr(ind,n-ind);
        string s2=s.substr(0,ind);
        if(goal==(s1+s2))
            return true;
        return false;
    }
};