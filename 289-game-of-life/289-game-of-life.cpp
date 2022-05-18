class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int c0=0,c1=0;
                if((i-1)>=0 and (j-1)>=0)
                {
                    (board[i-1][j-1]==0 || board[i-1][j-1]==2) ? c0++:c1++;
                }
                
                if((i-1)>=0)
                {
                    (board[i-1][j]==0 || board[i-1][j]==2) ? c0++:c1++;
                }
                
                if((i-1)>=0 and (j+1)<n)
                {
                    (board[i-1][j+1]==0 || board[i-1][j+1]==2) ? c0++:c1++;
                }
                
                if((j-1)>=0)
                {
                    (board[i][j-1]==0 || board[i][j-1]==2) ? c0++:c1++;
                }
                
                if((j+1)<n)
                {
                    (board[i][j+1]==0 || board[i][j+1]==2) ? c0++:c1++;
                }
                
                if((i+1)<m and (j-1)>=0)
                {
                    (board[i+1][j-1]==0 || board[i+1][j-1]==2) ? c0++:c1++;
                }
                
                if((i+1)<m)
                {
                    (board[i+1][j]==0 || board[i+1][j]==2) ? c0++:c1++;
                }
                
                if((i+1)<m and (j+1)<n)
                {
                    (board[i+1][j+1]==0 || board[i+1][j+1]==2) ? c0++:c1++;
                }
                
                cout<<c0<<" "<<c1<<" ";
                if(board[i][j]==0 and c1==3)
                {
                    board[i][j]=2;
                }
                else if(board[i][j]==1 and c1<2)
                {
                    board[i][j]=3;
                }
                else if(board[i][j]==1 and c1>3)
                {
                    board[i][j]=3;
                }
                else if(board[i][j]==1 and (c1==2 || c1==3))
                {
                    board[i][j]=1;
                }   
            }
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==2)
                    board[i][j]=1;
                else if(board[i][j]==3)
                    board[i][j]=0;
            }
        }
    }
};