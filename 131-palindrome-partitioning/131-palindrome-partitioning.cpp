class Solution {
public:
    void partition(int ind, string s, vector<string> &path, vector<vector<string>> &ans){
        if(ind==s.size()){
            ans.push_back(path);
            return;
        }
        
        for(int i=ind;i<s.size();i++){
            if(ispalindrome(s, ind, i)){
                path.push_back(s.substr(ind, i-ind+1));
                partition(i+1, s, path, ans);
                path.pop_back();
            }       
        }
    }
    
    bool ispalindrome(string str, int start, int end){
        while(start<=end){
            if(str[start++]!=str[end--])
                return false;
        }
        return true;
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        partition(0, s, path, ans);
        return ans;
    }
};