class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            int lo=0,hi=m-1;
            while(lo<=hi){
                int mid=lo+(hi-lo)/2;
                if(matrix[i][mid]==target)
                    return true;
                else if(matrix[i][mid]>target)
                    hi=mid-1;
                else if(matrix[i][mid]<target)
                    lo=mid+1;
            }
        }
        return false;
    }
};