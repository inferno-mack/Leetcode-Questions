class Solution {
public:
    
    int ans = 0;
    int dp[10001][13];
    
    int res(vector<int>& a, int sum, int n){
        if(sum == 0) return 0;
        if(n<0) return 1000000000;
        
        if(dp[sum][n] != -1) return ans = dp[sum][n];
        
        if(a[n] <= sum){
            dp[sum][n] = min(res(a, sum, n-1), 1+ res(a, sum-a[n], n));
            return ans = dp[sum][n];
        }
        dp[sum][n] = res(a, sum, n-1);
        return ans = dp[sum][n];
    }
    
    int coinChange(vector<int>& a, int sum) {
        sort(a.begin(), a.end());
        // dp.resize(sum+1, vector<int>(a.size()+1));
        
        memset(dp , -1 , sizeof(dp));
        
        res(a, sum , a.size()-1);
        if(ans >= 1000000000) return -1;
        return ans;
    }
};