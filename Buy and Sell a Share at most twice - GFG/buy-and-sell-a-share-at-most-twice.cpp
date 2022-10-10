//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

int maxProfit(vector<int>&prices){
    //Write your code here..
     int n=prices.size();
        vector<vector<int>> after(2, vector<int>(3,0));
        vector<vector<int>> curr(2, vector<int>(3,0));
        
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){
                    if(buy)
                        curr[buy][cap]=max(-prices[ind]+after[0][cap], after[1][cap]);
                    else
                        curr[buy][cap]=max(prices[ind]+after[1][cap-1], after[0][cap]);
                }
            }
            after=curr;
        }
        return after[1][2];
}

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends