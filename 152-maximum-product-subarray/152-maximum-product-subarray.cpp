class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int mx=nums[0], a=1, b=1, c=1, c1=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                a=1;
                b=1;
                c=1;
                c1=0;
                mx=max(mx,0);
            }
            else{
                c=c*nums[i];
                mx=max(mx, c);
                mx=max(c/a, mx);
                if(c1==0){
                    a=a*nums[i];
                    if(nums[i]<0)
                        c1=1;
                }
            }
        }
        return mx;
    }
};