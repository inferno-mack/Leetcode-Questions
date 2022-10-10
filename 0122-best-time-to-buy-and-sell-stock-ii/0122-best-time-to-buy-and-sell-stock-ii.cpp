class Solution {
public:
    int maxProfit(vector<int>& arr) {
        
        int ans=0;
        for(int i=0;i<arr.size()-1;i++)
        {
            if(arr[i+1]>arr[i])
                ans+=(arr[i+1]-arr[i]);
        }
        
        return ans;
    }
};