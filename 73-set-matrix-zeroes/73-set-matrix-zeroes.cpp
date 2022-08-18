class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]==0){
                    for(int k=0;k<rows;k++){
                        if(matrix[k][j]!=0) matrix[k][j]=1e9;
                    }
                    
                    for(int l=0;l<cols;l++){
                        if(matrix[i][l]!=0) matrix[i][l]=1e9;
                    }
                }
            }
        }
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]==1e9)
                    matrix[i][j]=0;
            }
        }
    }
};