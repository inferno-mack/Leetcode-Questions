class Solution {
public:
    
    void subsets(int ind, vector<int> nums, vector<vector<int>> &ans, vector<int> &temp, int n){
        if(ind == n){
            ans.push_back(temp);
            return;
        }
        
        temp.push_back(nums[ind]);
        subsets(ind+1, nums, ans, temp, n);
        temp.pop_back();
        subsets(ind+1, nums, ans, temp, n);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        subsets(0, nums, ans, temp, n);
        return ans;
    }
};