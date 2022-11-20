//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string strs[], int N)
    {
        
        // your code here
        string ans = "";

            int len = INT_MAX;
            for (int i = 0; i < N; i++)
            {
                len = min(len, (int)(strs[i].size()));
            }

            bool flag = true;
            for (int j = 0; j <= len - 1; j++)
            {
                for (int i = 0; i < N - 1; i++)
                {
                    if (strs[i][j] != strs[i + 1][j])
                    {
                        flag = false;
                        break;
                    }
                }

                if (flag == false) break;
                else
                {
                    ans += strs[0][j];
                }
            }
            if(ans.size()==0){
                ans += "-1";
                return ans;
            }
            return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends