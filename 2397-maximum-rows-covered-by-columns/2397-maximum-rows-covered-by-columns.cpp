class Solution {
public:
    int maximumRows(vector<vector<int>>& mat, int cols) {
        int m=mat.size(),n=mat[0].size();
        int ans=0;
        
        string str="";
        for(int i=0;i<n;i++)
            str+='0';
        
        for(int i=0;i<cols;i++)
            str[i]='1';
        
        for(int i=0;i<m;i++){
            bool flag=true;
            for(int j=0;j<n;j++){
                if(str[j]=='0' and mat[i][j]==1){
                    flag=false;
                    break;
                }
            }
            if(flag) ans++;
        }
        
        string w=str;
        next_permutation(str.begin(),str.end());
        while(1){
            if(w==str) break;
            int x = 0;
            for(int i=0;i<m;i++){
                bool flag=true;
                for(int j=0;j<n;j++){
                    if(str[j]=='0' and mat[i][j]==1){
                        flag=false;
                        break;
                    }
                }
                if(flag) x++;
            }
            next_permutation(str.begin(),str.end());
            ans = max(ans, x);
        }
        return ans;
    }
};