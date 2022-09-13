class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans=0;
        
        int ct1=0, ct0=0;
        int low=0;
        for(int i=0;i<nums.size();i++){
            ct1++;
            if(nums[i]==0) ct0++;
            if(ct0 > k){
                while(low <= i and ct0 > k){
                    if(nums[low]==0) ct0--;
                    ct1--;
                    low++;
                }
            }
            ans=max(ans, ct1);
        }
        return ans;
    }
};