class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        long long int sum=0;
        long long int mod=1e9+7;
        
        for(int i=0;i<nums1.size();i++)
            sum+=abs(nums1[i]-nums2[i]);
        
        vector<int> temp = nums1;
        sort(temp.begin(), temp.end());
        
        long long int ans=sum;
        
        for(int i=0;i<nums2.size();i++){
            long long int currsum=sum-abs(nums1[i]-nums2[i]);
            
            int lb=lower_bound(temp.begin(), temp.end(), nums2[i])-temp.begin();
            if(lb==nums2.size()){
                ans=min(ans, currsum+abs(temp[lb-1]-nums2[i]));
            }
            else if(lb==0){
                ans=min(ans, currsum+abs(temp[lb]-nums2[i]));
            }
            else{
                ans=min(ans, currsum+abs(temp[lb]-nums2[i]));
                ans=min(ans, currsum+abs(temp[lb-1]-nums2[i]));
            }
        }
        return ans%mod;
    }
};