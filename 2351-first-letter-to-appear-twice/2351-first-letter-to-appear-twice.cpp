class Solution {
public:
    char repeatedCharacter(string s) {
        int freq[123]={0};
        char ans;
        for(int i=0;i<s.size();i++){
            if(freq[s[i]]<1)
                freq[s[i]]++;
            else{
                ans=s[i];
                break;
            } 
        }
        
        return ans;
    }
};