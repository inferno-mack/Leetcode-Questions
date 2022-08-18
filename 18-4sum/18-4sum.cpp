class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.empty()) return ans;
        
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long targetsum=(long)target-nums[i]-nums[j];
                int front=j+1;
                int back=n-1;
                while(front<back){
                    long targetsum2=nums[front]+nums[back];
                    if(targetsum2<targetsum) front++;
                    else if(targetsum2>targetsum) back--;
                    else{
                        vector<int> quad(4,0);
                        quad[0]=nums[i];
                        quad[1]=nums[j];
                        quad[2]=nums[front];
                        quad[3]=nums[back];
                        ans.push_back(quad);
                        
                        while(front<back and nums[front]==quad[2]) front++;
                        while(front<back and nums[back]==quad[3]) back--;
                    }
                }
                
                while(j+1<n and nums[j+1]==nums[j]) j++;
                while(i+1<n and nums[i+1]==nums[i]) i++;
            }
        }
        
        return ans;
    }
};