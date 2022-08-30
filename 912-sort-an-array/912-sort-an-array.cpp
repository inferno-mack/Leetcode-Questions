class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> ans;
        vector<int> freq(100001,0);
        for(int i=0;i<nums.size();i++){
            freq[nums[i]+50000]++;
        }
        
        for(int i=0;i<freq.size();i++){
            while(freq[i]--){
                ans.push_back(i-50000);
            }
        }
        return ans;
    }
};