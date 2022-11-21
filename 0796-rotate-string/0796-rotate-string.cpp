class Solution {
public:
    bool rotateString(string s, string goal) {
        for(int i=0;i<s.size();i++){
            if(s[i]==goal[0]){
                string temp = s.substr(i, s.size()-i) + s.substr(0, i);
                if(temp == goal)
                    return true;
            }
        }
        return false;
    }
};