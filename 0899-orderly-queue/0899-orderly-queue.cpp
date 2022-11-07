class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k > 1){
            sort(s.begin(), s.end());
            return s;
        }
        
        string ans = s;
        for(int i = 0; i < s.size(); i++){
            char ch = s[0];
            s.erase(s.begin() + 0);
            
            s += ch;
            cout<<s<<endl;
            ans = min(ans, s);
        }
        
        return ans;
    }
};