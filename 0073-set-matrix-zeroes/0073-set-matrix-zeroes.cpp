class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        
        vector<int> row(m,-1), col(n,-1);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    row[i]=0;
                    col[j]=0;
                }
            }
        }
        
        for(int r=0;r<m;r++){
            if(row[r]==0){
                for(int j=0;j<n;j++)
                    matrix[r][j] = 0;
            }
        }
        
        for(int c = 0; c < n; c++){
            if(col[c] == 0){
                for(int i = 0; i < m ; i++)
                    matrix[i][c] = 0;
            }
        }
    }
};