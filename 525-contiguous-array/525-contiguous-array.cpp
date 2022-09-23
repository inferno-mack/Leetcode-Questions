class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int,int> mp;
        int ans=0, ct=0;
        mp[0]=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)
                ct++;
            else ct--;
            if(mp.find(ct)!=mp.end()){
                ans=max(ans,i-mp[ct]);
            }
            else{
                mp[ct]=i;
            }
        }
        return ans;
    }
};