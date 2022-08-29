class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int row=0,col=0;
        while(row<n and col<m){
            int lo=row,hi=m-1;
            while(lo<=hi){
                int mid=lo+(hi-lo)/2;
                if(matrix[row][mid]==target)
                    return true;
                else if(matrix[row][mid]>target)
                    hi=mid-1;
                else 
                    lo=mid+1;
            }
            lo=row,hi=n-1;
            while(lo<=hi){
                int mid=lo+(hi-lo)/2;
                if(matrix[mid][col]==target)
                    return true;
                else if(matrix[mid][col]>target)
                    hi=mid-1;
                else
                    lo=mid+1;
            }
            row++;
            col++;
        }
        return false;
    }
};