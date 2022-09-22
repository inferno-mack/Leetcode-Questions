class Solution {
public:
    void f(vector<int> nums, int ind, vector<int> &res, vector<vector<int>> &ans){
        if(ind>=nums.size()){
            ans.push_back(res);
            return;
        }    
        
        res.push_back(nums[ind]);
        f(nums, ind+1, res, ans);
        res.pop_back();
        f(nums, ind+1, res, ans);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> res;
        f(nums, 0, res, ans);
        return ans;
    }
};