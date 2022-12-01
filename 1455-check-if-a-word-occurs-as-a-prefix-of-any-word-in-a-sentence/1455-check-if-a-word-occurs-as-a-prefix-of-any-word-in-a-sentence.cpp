class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string> words;
        
        for(int i=0;i<sentence.size();i++){
            string temp="";
            while(sentence[i]!=' ' and i<sentence.size()){
                temp+=sentence[i];
                i++;
            }
            words.push_back(temp);
        }
        
        int i, j;
        for(i=0;i<words.size();i++){
            if(words[i][0]==searchWord[0]){
                for(j=0;j<searchWord.size();j++){
                    if(searchWord[j]!=words[i][j]){
                        break;
                    }
                }
                if(j==searchWord.size()) return i+1;
            }
        }
        return -1;
    }
};