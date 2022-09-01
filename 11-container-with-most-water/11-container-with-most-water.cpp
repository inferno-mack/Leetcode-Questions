class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;
        int left=0,right=height.size()-1;
        while(left<right){
            if(height[left]<=height[right]){
                int res=height[left]*(right-left);
                left++;
                ans=max(ans,res);
            }
            else{
                int res=height[right]*(right-left);
                right--;
                ans=max(ans,res);
            }
        }
        return ans;
    }
};