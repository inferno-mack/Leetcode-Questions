class Solution {
public:
    bool isRobotBounded(string str) {
        int x=0,y=0;
        int l=0;
        
        for(int i=0;i<str.size();i++){
            if(str[i]=='L')
                l=(l-1+4)%4;
            else if(str[i]=='R') 
                l=(l+1+4)%4;
            else{
                int temp=l;
                if(temp==0) y++;
                else if(temp==1) x--;
                else if(temp==2) y--;
                else if(temp==3) x++;
            }
        }
        
        if((x!=0 || y!=0) and l==0) return false;
        return true;
    }
};