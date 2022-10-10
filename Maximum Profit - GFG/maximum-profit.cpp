//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int k, int n, int prices[]) {
        // code here
        vector<vector<int>> after(2, vector<int>(k+1,0));
        vector<vector<int>> curr(2, vector<int>(k+1,0));
        
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=k;cap++){
                    if(buy)
                        curr[buy][cap]=max(-prices[ind]+after[0][cap], after[1][cap]);
                    else
                        curr[buy][cap]=max(prices[ind]+after[1][cap-1], after[0][cap]);
                }
            }
            after=curr;
        }
        return after[1][k];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends