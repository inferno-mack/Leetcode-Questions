class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n==0) return 0;
        vector<int> nums(n+1);
        nums[0]=0,nums[1]=1;
        int ind=1;
        while((2*ind) <=n and (2*ind+1)<=n){
            nums[(2*ind)]=nums[ind];
            nums[(2*ind)+1]=nums[ind]+nums[ind+1];
            ind++;
        }
        
        int ans=INT_MIN;
        for(auto mx:nums)
            ans=max(ans,mx);
            
        return ans;
    }
};