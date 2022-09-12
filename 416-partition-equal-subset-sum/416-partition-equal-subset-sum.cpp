class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto it:nums)
            sum+=it;
        
        int k=sum/2;
        vector<bool> prev(k+1,false), curr(k+1, false);
        if(sum & 1) return false;
        for(int i=0;i<n;i++)
            prev[0]=true;
        
        if(nums[0]<=k) prev[nums[0]]=true;
        for(int ind=1;ind<n;ind++){
            for(int target=1;target<=k;target++){
                bool nottake=prev[target];
                bool take=false;
                if(nums[ind]<=target) take=prev[target-nums[ind]];
                curr[target]=take | nottake;
            }
            prev=curr;
        }
        return prev[k];
    }
};