class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        vector<long long> prefixsum(costs.size(), costs[0]);
        
        for(int i=1;i<costs.size();i++)
            prefixsum[i]=costs[i]+prefixsum[i-1];
        
        for(int i=0;i<prefixsum.size();i++){
            if(prefixsum[i]>coins){
                return i;
            }
        }
        return costs.size();
    }
};