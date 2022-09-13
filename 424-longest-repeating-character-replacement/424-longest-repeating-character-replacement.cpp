class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans=0;
        
        for(char i='A';i<='Z';i++){
            int ct=0, temp=0;
            int low=0;
            for(int j=0;j<s.size();j++){
                ct++;
                if(s[j] != i) temp++;
                if(temp > k){
                    while(low <= j and temp > k){
                        if(s[low] != i) temp--;
                        ct--;
                        low++;
                    }
                }
                ans=max(ans, ct);
            }
        }
        return ans;
    }
};