class Solution {
public:
    bool f(int ind, int target, vector<int> &nums, vector<vector<int>> &dp){
        if(target == 0) return true;
        if(ind == 0) return (nums[0]==target);
        
        if(dp[ind][target]!=-1) return dp[ind][target];
        bool nottake=f(ind-1, target, nums,dp);
        bool take=false;
        if(nums[ind]<=target) take=f(ind-1, target-nums[ind], nums,dp);
        return dp[ind][target]=take | nottake;
    }
    
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto it:nums)
            sum+=it;
        
        int k=sum/2;
        vector<vector<bool>> dp(n+1, vector<bool>(k+1, false));
        if(sum & 1) return false;
        for(int i=0;i<n;i++)
            dp[i][0]=true;
        
        if(nums[0]<=k) dp[0][nums[0]]=true;
        for(int ind=1;ind<n;ind++){
            for(int target=1;target<=k;target++){
                bool nottake=dp[ind-1][target];
                bool take=false;
                if(nums[ind]<=target) take=dp[ind-1][target-nums[ind]];
                dp[ind][target]=take | nottake;
            }
        }
        return dp[n-1][k];
    }
};