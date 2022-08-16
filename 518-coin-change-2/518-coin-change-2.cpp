class Solution {
public:
    int change(int val, vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(val+1,0));
        
        for(int tar=0;tar<=val;tar++)
            dp[0][tar]=(tar%arr[0]==0);
        
        for(int ind=1;ind<n;ind++){
            for(int tar=0;tar<=val;tar++){
                int nottake=dp[ind-1][tar];
                int take=0;
                if(arr[ind]<=tar) take=dp[ind][tar-arr[ind]];
                
                dp[ind][tar]=take+nottake;
            }
        }
        return dp[n-1][val];
    }
};