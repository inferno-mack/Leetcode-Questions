class Solution {
public:
    
    bool isPalindrome(string str)
    {
        string rev=str;
        reverse(str.begin(),str.end());
        if(str==rev)
            return true;
        return false;
    }
    
    int countSubstrings(string s) {
        int ans=0;
        
        for(int i=0;i<s.size();i++)
        {
            for(int j=i;j<s.size();j++)
            {
                string temp=s.substr(i,j-i+1);
                if(isPalindrome(temp))
                {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};