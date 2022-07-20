class Solution {
public:
    
    void prints(int ind, vector<int> &ds, vector<int> arr, int target, vector<vector<int>> &ans){
        if(ind == arr.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        } 
        
        if(arr[ind]<=target){
            ds.push_back(arr[ind]);
            prints(ind, ds, arr, target-arr[ind], ans);
            ds.pop_back();
        }
        
        prints(ind+1, ds, arr, target, ans);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> ans;
        prints(0, ds, candidates, target, ans);
        return ans;
    }
};