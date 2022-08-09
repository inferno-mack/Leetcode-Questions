class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        if(n==1) return nums[0];
        dp[0]=nums[0];
        
        for(int i=1;i<n;i++){
            int take=nums[i];
            if(i>1) take+=dp[i-2];
            int nottake=dp[i-1];
            dp[i]=max(take,nottake);
        }
        return dp[n-1];
    }
};