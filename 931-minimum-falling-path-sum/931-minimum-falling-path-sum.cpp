
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int> front(n,0);
        
        for(int i=0;i<n;i++){
            front[i]=matrix[0][i];
        }
        
        for(int i=1;i<n;i++){
            vector<int> curr(n,0);
            for(int j=0;j<n;j++){
                int up=matrix[i][j]+front[j];
                int left=matrix[i][j];
                if((j-1)>=0) left+=front[j-1];
                else left=1e9;
                int right=matrix[i][j];
                if((j+1)<n) right+=front[j+1];
                else right=1e9;
                
                curr[j]= min(up,min(left,right));
            }
            front=curr;
        }
        
        int mini=1e8;
        for(int j=0;j<n;j++){
            mini=min(mini, front[j]);
        }
        
        return mini;
    }
};