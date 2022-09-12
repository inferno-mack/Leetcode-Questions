class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int low=0, high=1;
        while(high<nums.size()){
            if(nums[low]!=nums[high]){
                low++;
                nums[low]=nums[high];
            }
            high++;
        }
        return low+1;
    }
};