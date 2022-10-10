class Solution {
    int f(int idx, int buy, int cap, vector<int>& v, int n,vector<vector<vector<int>>>& dp){
        //if(cap==0)return 0;//only 2 times
        if(idx==n or cap==0)return 0;//exhausted
        if(~dp[idx][buy][cap])return dp[idx][buy][cap];
        int profit =0;//re-int to 0 after buying and selling
        if(buy){
            int buY = -v[idx] + f(idx+1,0,cap,v,n,dp); //buying so next step sell so 0 and profit will be -
            int notB = f(idx+1,1,cap,v,n,dp);//not buying, unchanged profit, still can buy so 1
            return dp[idx][buy][cap]=profit+=max(buY,notB);
        }
        else{//sell (capacity will only be -1 while we are actually selling the stock)
            int sell = v[idx] + f(idx+1,1,cap-1,v,n,dp); //selling so next step buy so 1 and profit will be +
            int notS = f(idx+1,0,cap,v,n,dp);//not selling, unchanged profit, still can sell so 0
            return dp[idx][buy][cap]=profit+=max(sell,notS);
        }
    }
public:
    int maxProfit(vector<int>& v) {
        //buy is denoted 1, sell is denoted 0
        //capacity is 2 init -> like knapsack
        int n = v.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,1,2,v,n,dp);
    }
};