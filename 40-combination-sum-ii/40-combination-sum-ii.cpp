class Solution {
public:
      void printcombinations(int ind, vector<int> &ds, vector<vector<int>> &ans, int target, vector<int> arr){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        
        for(int i=ind;i<arr.size();i++){
            if(i>ind and arr[i]==arr[i-1]) continue;
            if(arr[i]>target) break;
            ds.push_back(arr[i]);
            printcombinations(i+1, ds, ans, target-arr[i], arr);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> ds;
        vector<vector<int>> ans;
        printcombinations(0, ds, ans, target, candidates);
        return ans;
    }
};