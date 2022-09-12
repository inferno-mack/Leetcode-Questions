class Solution {
public:
    int trap(vector<int>& height) {
        int res=0;
        int n=height.size();
        int low=0, high=n-1;
        int leftmax=0, rightmax=0;
        
        while(low<=high){
            if(height[low]<=height[high]){
                if(height[low]>=leftmax)
                    leftmax=height[low];
                else
                    res+=(leftmax-height[low]);
                low++;
            }
            else{
                if(height[high]>=rightmax)
                    rightmax=height[high];
                else
                    res+=(rightmax-height[high]);
                high--;
            }
        }
        return res;
    }
};