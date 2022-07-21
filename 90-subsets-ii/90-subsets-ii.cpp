class Solution {
public:
      void printcombinations(int ind, vector<int> &ds, vector<vector<int>> &ans, vector<int> arr){
        ans.push_back(ds);
        
        for(int i=ind;i<arr.size();i++){
            if(i>ind and arr[i]==arr[i-1]) continue;
            ds.push_back(arr[i]);
            printcombinations(i+1, ds, ans, arr);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& candidates) {
        sort(candidates.begin(),candidates.end());
        vector<int> ds;
        vector<vector<int>> ans;
        printcombinations(0, ds, ans, candidates);
        return ans;
    }
};