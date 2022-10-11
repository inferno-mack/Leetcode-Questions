class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        vector<int> leftmin(n), rightmax(n);
        leftmin[0]=nums[0];
        for(int i=1;i<n;i++)
            leftmin[i]=min(leftmin[i-1], nums[i]);
        
        rightmax[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
            rightmax[i]=max(rightmax[i+1], nums[i]);
        
        for(int i=1;i<n-1;i++){
            if(leftmin[i]<nums[i] and nums[i]<rightmax[i])
                return true;
        }
        return false;
    }
};