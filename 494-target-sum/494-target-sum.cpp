class Solution {
public:
    int solve(vector<int> &nums,int tar){
        vector<int> prev(tar+1,0),curr(tar+1,0);
        
        if(nums[0]==0) prev[0]=2;
        else prev[0]=1;
        if(nums[0]!=0 and nums[0]<=tar) prev[nums[0]]=1;
        
        for(int i=1;i<nums.size();i++){
            for(int sum=0;sum<=tar;sum++){
                int nottake=prev[sum];
                int take=0;
                if(nums[i]<=sum) take=prev[sum-nums[i]];
                
                curr[sum]=nottake+take;
            }
            prev=curr;
        }
        return prev[tar];
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalsum=0;
        for(auto &it:nums){
            totalsum+=it;
        }
        
        if((totalsum-target)<0 || (totalsum-target)%2) return 0;
        return solve(nums, (totalsum-target)/2);
    }
};