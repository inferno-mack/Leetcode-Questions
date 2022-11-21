class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        vector<int> ans;
        
        for(int i=0; i<nums.size(); i++){
            int val = target-nums[i];
            if(mp.find(val)!=mp.end()){
                ans.push_back(mp[val]);
                ans.push_back(i);
                return ans;
            }
            else{
                mp[nums[i]]=i;
            }
        }
        return ans;
    }
};