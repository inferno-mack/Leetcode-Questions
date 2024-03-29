class Solution {
public:
    int firstUniqChar(string s) {
        int freq[123]={0};
        for(int i=0;i<s.size();i++){
            freq[s[i]]++;
        }
        
        for(int i=0;i<s.size();i++){
            if(freq[s[i]]==1)
                return i;
        }
        
        return -1;
    }
};