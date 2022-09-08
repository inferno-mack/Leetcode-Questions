class Solution {
public:
    bool check(vector<int>& nums) {
        int ind=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                ind=i;
                break;
            }
        }
        
        int k=nums.size()-ind;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
        
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1])
                return false;
        }
        return true;
    }
};