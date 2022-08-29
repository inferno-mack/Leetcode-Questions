class Solution {
public:
    int trap(vector<int>& heights) {
        int res=0;
        int n=heights.size();
        vector<int> mxl(n);
        vector<int> mxr(n);
        mxl[0]=heights[0];
        mxr[n-1]=heights[n-1];
        
        for(int i=1;i<n;i++){
            mxl[i]=max(mxl[i-1],heights[i]);
        }
        
        for(int j=n-2;j>=0;j--){
            mxr[j]=max(mxr[j+1],heights[j]);
        }
        
        for(auto it:mxl){
            cout<<it<<" ";
        }
        
        for(int i=0;i<n;i++){
            res=res+(min(mxr[i],mxl[i])-heights[i]);
        }
        
        return res;
    }
};