class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int chars=1, len=1;
        int ans=0;
        
        for(int i=1;i<word.size();i++){
            if(word[i]==word[i-1]){
                len++;
            }
            else if(word[i-1]<word[i]){
                len++;
                chars++;
            }
            else{
                len=1;
                chars=1;
            }
            
            if(chars==5){
                ans=max(ans,len);
            }
        }
        return ans;
    }
};