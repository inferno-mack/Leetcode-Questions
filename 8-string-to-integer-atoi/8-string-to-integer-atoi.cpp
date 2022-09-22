class Solution {
public:
    int myAtoi(string s) {
        const int len=s.size();
        if(len==0) return 0;
        
        int ind=0;
        while(ind<len && s[ind]==' ')
            ind++;
        
        bool isNegative=false;
        if(ind<len){
            if(s[ind]=='-'){
                isNegative=true;
                ind++;
            }
            else if(s[ind]=='+')
                ind++;
        }
        
        int result=0;
        while(ind<len && isDigit(s[ind])){
            int data=s[ind]-'0';
            
            //to avoid int overflow
            if(result > INT_MAX/10 || (result==(INT_MAX/10) and data>7))
                return isNegative ? INT_MIN:INT_MAX;
            
            result=result*10 + data;
            ind++;
        }
        if(isNegative) result=(-1)*result;
        return result;
    }

private:
    bool isDigit(char ch){
        return ch>='0' and ch<='9';
    }
};