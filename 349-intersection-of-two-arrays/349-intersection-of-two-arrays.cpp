class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        map<int,int>  mp1,mp2;
        for(auto it:nums1)
            mp1[it]++;
        for(auto it:nums2)
            mp2[it]++;
        
        for(auto x:mp1){
            if(mp2.find(x.first)!=mp2.end())
                ans.push_back(x.first);
        }
        return ans;
    }
};