class Solution {
public:
    int climb(int ind, vector<int> &dp){
        if(ind <= 1) return 1;
        if(dp[ind]!=-1) return dp[ind];
        return dp[ind]=climb(ind-1, dp)+climb(ind-2, dp);
    }
    
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return climb(n, dp);
    }
};