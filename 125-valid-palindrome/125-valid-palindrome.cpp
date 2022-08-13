class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        
        for(int i=0;i<s.size();i++){
            
            if(s[i]>='a' and s[i]<='z'){
                str.push_back(s[i]);
            }
            if(s[i]>='A' and s[i]<='Z'){
                s[i]+=32;
                str.push_back(s[i]);
            }
            if(s[i]>='0' and s[i]<='9'){
                str.push_back(s[i]);
            }
        }
        
        for(int i=0;i<str.size()/2;i++){
            if(str[i]!=str[str.size()-1-i])
                return false;
        }
        cout<<str;
        return true;
    }
};