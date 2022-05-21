// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    
    long long int dp[1001][1001];
  
    long long int res(int a[], int sum, int n){
        
        if(sum == 0) return 1;
        
        if(n<0) return 0;
        
        if(dp[sum][n] != -1) return dp[sum][n];
        
        if(a[n] <= sum){
            return dp[sum][n] = res(a, sum-a[n], n) + res(a, sum, n-1);
        }
        return dp[sum][n] = res(a, sum, n-1);
        
    }
  
    long long int count(int a[], int m, int sum) {

        // code here.
        memset(dp, -1, sizeof(dp));
        
        return res(a, sum, m-1);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends