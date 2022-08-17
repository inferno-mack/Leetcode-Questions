class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> v1  = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."} ;
        
        int i , j ;
        
        map<string,int> m ;
        
        for(i=0;i<words.size();i++)
        {
            string s ;
            
            for(j=0;j<words[i].size();j++)
            {
                s = s + v1[words[i][j]-'a'] ;
            }
            
            m[s]++ ;
        }
        
        return m.size() ;
    }
};