class Solution {
public:
    int climbStairs(int n) {
        if(n==1 or n==2) return n;
        int prev=2;
        int prev2=1;
        int ans=0;
        
        for(int i=3;i<=n;i++){
            ans=prev+prev2;
            prev2=prev;
            prev=ans;
        }
        return prev;
    }
};