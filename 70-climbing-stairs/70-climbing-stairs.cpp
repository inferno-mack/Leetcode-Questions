class Solution {
public:
    int solve(int ind,vector<int> &dp){
        if(ind==1) return 1;
        if(ind==2) return 2;
        
        if(dp[ind]!=-1) return dp[ind];
        int fs=solve(ind-1, dp);
        int ss=solve(ind-2, dp);
        return dp[ind]=fs+ss;
    }
    
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return solve(n, dp);
    }
};