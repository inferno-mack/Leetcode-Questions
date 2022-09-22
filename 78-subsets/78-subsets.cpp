class Solution {
public:
    void generateAllSubsets(vector<int> nums, int currentInd, vector<int> &res, vector<vector<int>> &ans){
        if(currentInd>=nums.size()){
            ans.push_back(res);
            return;
        }    
        
        int currentval=nums[currentInd];
        res.push_back(currentval);
        generateAllSubsets(nums, currentInd+1, res, ans);
        res.pop_back();
        generateAllSubsets(nums, currentInd+1, res, ans);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> powerSet;
        vector<int> res;
        generateAllSubsets(nums, 0, res, powerSet);
        return powerSet;
    }
};