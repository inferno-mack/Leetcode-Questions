class Solution {
public:
    int maxPower(string s) {
        int ans=INT_MIN;
        int count=1;
        if(s.size()==1) return 1;
        
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]){
                count++;
            }else{
                ans=max(ans, count);
                count=1;
            }
        }
        ans=max(ans, count);
        return ans;
    }
};