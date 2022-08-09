class Solution {
public:
    int maxsum(vector<int> &arr){
        int n=arr.size();
        if(n==1) return arr[0];
        int prev=arr[0];
        int prev2=0;
        
        for(int i=1;i<n;i++){
            int take=arr[i];
            if(i>1) take+=prev2;
            int nottake=0+prev;
            int curr=max(take,nottake);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
    
    int rob(vector<int>& nums) {
        vector<int> temp1,temp2;
        if(nums.size()==1) return nums[0];
        for(int i=0;i<nums.size();i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=(nums.size()-1)) temp2.push_back(nums[i]);
        }
        
        return max(maxsum(temp1),maxsum(temp2));
    }
};