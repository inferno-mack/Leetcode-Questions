class Solution {
public:
    
    void findcombo(int ind, vector<int> candidates, int target, vector<int> &ds, vector<vector<int>> &ans){
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        
        for(int i=ind;i<candidates.size();i++){
            if(i>ind and candidates[i]== candidates[i-1]) continue;
            if(candidates[i] > target) break;
            ds.push_back(candidates[i]);
            findcombo(i+1, candidates, target - candidates[i], ds, ans);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        findcombo(0, candidates, target, ds, ans);
        return ans;
    }
};