class Solution {
public:
    vector<int> nextSmallerRight(vector<int> &heights, int n){
        vector<int> res(n);
        stack<int> st;
        
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()]>=heights[i])
                st.pop();
            if(st.empty())
                res[i] = n;
            else
                res[i] = st.top();
            st.push(i);
        }
        return res;
        
    }
    
    vector<int> nextSmallerLeft(vector<int> &heights, int n){
        vector<int> res(n);
        stack<int> st;
        
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()]>=heights[i])
                st.pop();
            if(st.empty())
                res[i] = -1;
            else
                res[i] = st.top();
            st.push(i);
        }
        return res;
    }
    
    int MAH(vector<int> &right, vector<int> &left,vector<int> &heights){
        int ans=INT_MIN;
        for(int i=0;i<right.size();i++){
            ans=max(ans,(heights[i]*(right[i]-left[i]-1)));
        }
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int res=INT_MIN;
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> v(n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='0'){
                    v[j]=0;
                }
                else{
                    v[j]=v[j]+(matrix[i][j]-'0');
                }
            }
            
            vector<int> right=nextSmallerRight(v,n);
            vector<int> left=nextSmallerLeft(v,n);
            res=max(res,MAH(right,left,v));
            cout<<res<<endl;
        }
        return res;
    }
};