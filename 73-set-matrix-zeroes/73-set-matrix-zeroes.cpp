class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        vector<int> row(cols,1e9);
        vector<int> col(rows,1e9);
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]==0){
                    row[j]=0;
                    col[i]=0;
                }
            }
        }
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(row[j]==0 || col[i]==0)
                    matrix[i][j]=0;
            }
        }
    }
};