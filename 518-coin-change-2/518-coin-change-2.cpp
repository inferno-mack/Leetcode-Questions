class Solution {
public:
    int change(int val, vector<int>& arr) {
        int n=arr.size();
        vector<int> prev(val+1,0),curr(val+1,0);
        
        for(int tar=0;tar<=val;tar++)
            prev[tar]=(tar%arr[0]==0);
        
        for(int ind=1;ind<n;ind++){
            for(int tar=0;tar<=val;tar++){
                int nottake=prev[tar];
                int take=0;
                if(arr[ind]<=tar) take=curr[tar-arr[ind]];
                
                curr[tar]=take+nottake;
            }
            prev=curr;
        }
        return prev[val];
    }
};