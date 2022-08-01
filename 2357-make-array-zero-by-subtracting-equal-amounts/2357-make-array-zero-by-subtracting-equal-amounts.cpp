class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                for(int j=i+1;j<nums.size();j++){
                    nums[j]-=nums[i];
                }
                ans++;
            }
        }
        
        return ans;
    }
};