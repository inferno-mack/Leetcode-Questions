//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string str)
    {
        // Your code here
        stack<int> st;
        for(int i=0;i<str.size();i++){
            if(str[i]>='0' and str[i]<='9'){
                st.push(str[i] - '0');
            }
            else{
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                
                switch(str[i]){
                    case '+':
                        st.push(y + x);
                        break;
                    case '-':
                        st.push(y - x);
                        break;
                    case '*':
                        st.push(y * x);
                        break;
                    case '/':
                        st.push(y / x);
                        break;
                    defalult:
                        break;
                }
            }
        }
        return st.top();
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends