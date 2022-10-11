class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int left=0, right=0;
        long long sum=0, n=nums.size();
        int ans=1;
        while(right<n){
            sum+=nums[right];
            
            while((1LL)*(right-left+1)*nums[right]-sum > k){
                sum-=nums[left];
                left++;
            }
            
            ans=max(ans,(right-left+1));
            right++;
        }
        return ans;
    }
};