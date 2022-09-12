class Solution {
public:
    int trap(vector<int>& height) {
        int res=0;
        int n=height.size();
        
        vector<int> prefixsum(n, height[0]);
        vector<int> suffixsum(n, height[n-1]);
        
        for(int i=1;i<height.size();i++)
            prefixsum[i]=max(prefixsum[i-1],height[i]);
        
        for(int i=height.size()-2;i>=0;i--)
            suffixsum[i]=max(suffixsum[i+1],height[i]);
        
        for(int i=0;i<height.size();i++)
            res+=min(prefixsum[i], suffixsum[i]) - height[i];
        
        return res;
    }
};