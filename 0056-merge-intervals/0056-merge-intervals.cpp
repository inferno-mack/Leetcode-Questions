class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if(intervals.size()==0) return ans;
        
        sort(intervals.begin(), intervals.end());
        vector<int> temp=intervals[0];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=temp[1]){
                temp[0]=min(intervals[i][0], temp[0]);
                temp[1]=max(intervals[i][1], temp[1]);
            }
            else{
                ans.push_back(temp);
                temp[0]=intervals[i][0];
                temp[1]=intervals[i][1];
            }
        }
        ans.push_back(temp);
        return ans;
    }
};