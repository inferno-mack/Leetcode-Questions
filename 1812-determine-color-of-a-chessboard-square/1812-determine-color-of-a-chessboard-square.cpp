class Solution {
public:
    bool squareIsWhite(string str) {
        if(((str[0]-'a') + (str[1]-'0'))%2==1)
            return false;
        return true;
    }
};