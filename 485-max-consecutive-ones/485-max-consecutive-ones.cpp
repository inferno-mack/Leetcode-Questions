class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=INT_MIN;
        int ind=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                ans=max(ans,i-ind-1);
                ind = i;
            }
        }
        ans=max(ans,(int)nums.size()-ind-1);
        return ans;
    }
};