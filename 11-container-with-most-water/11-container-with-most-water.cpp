class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;
        int left=0,right=height.size()-1,res=0;
        while(left<right){
            if(height[left]<=height[right]){
                res=height[left]*(right-left);
                left++;
            }
            else{
                res=height[right]*(right-left);
                right--;
            }
            
            if(res>ans) ans=res;
        }
        return ans;
    }
};