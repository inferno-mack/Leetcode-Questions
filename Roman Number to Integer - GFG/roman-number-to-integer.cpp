//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &s) {
        // code here
         int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='I' and (i+1)!=s.size()){
                if(s[i+1]=='V'){
                    ans+=4;
                    i++;
                }
                else if(s[i+1]=='X'){
                    ans+=9;
                    i++;
                }
                else{
                    ans+=1;
                }
            }
            else if(s[i]=='X' and (i+1)!=s.size()){
                if(s[i+1]=='L'){
                    ans+=40;
                    i++;
                }
                else if(s[i+1]=='C'){
                    ans+=90;
                    i++;
                }
                else{
                    ans+=10;
                }
            }
            else if(s[i]=='C' and (i+1)!=s.size()){
                if(s[i+1]=='D'){
                    ans+=400;
                    i++;
                }
                else if(s[i+1]=='M'){
                    ans+=900;
                    i++;
                }
                else{
                    ans+=100;
                }
            }
            else if(s[i]=='I'){
                ans+=1;
            }
            else if(s[i]=='V'){
                ans+=5;
            }
            else if(s[i]=='X'){
                ans+=10;
            }
            else if(s[i]=='L'){
                ans+=50;
            }
            else if(s[i]=='C'){
                ans+=100;
            }
            else if(s[i]=='D'){
                ans+=500;
            }
            else if(s[i]=='M'){
                ans+=1000;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends