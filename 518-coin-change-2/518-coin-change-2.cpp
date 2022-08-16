class Solution {
public:
    int solve(int ind, vector<int> arr, int target,vector<vector<int>> &dp){
        if(ind==0)
            return (target%arr[0]==0);
        
        if(dp[ind][target]!=-1) return dp[ind][target];
        int nottake=solve(ind-1, arr, target,dp);
        int take=0;
        if(arr[ind]<=target) take=solve(ind, arr, target-arr[ind],dp);
        
        return dp[ind][target]=nottake+take;
    }
    
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return solve(n-1, coins, amount,dp);
    }
};