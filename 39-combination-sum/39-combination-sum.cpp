class Solution {
public:
    void f(int ind, vector<int> nums, vector<int> &res, vector<vector<int>> &ans, int target){
        if(target==0){
            ans.push_back(res);
            return;
        }
        if(ind==nums.size()) return;
        
        if(nums[ind]<=target){
            res.push_back(nums[ind]);
            f(ind, nums, res, ans, target-nums[ind]);
            res.pop_back();
        }
        f(ind+1, nums, res, ans, target);
    }
    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> res;
        f(0, nums, res, ans, target);
        return ans;
    }
};