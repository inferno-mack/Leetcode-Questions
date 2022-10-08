class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        vector<long long> freq(100001,0);
        for(int i=0;i<costs.size();i++)
            freq[costs[i]]++;
        
        long long ans=0;
        for(long long i=0;i<100001;i++){
            if(freq[i]!=0){
                long long cost=i*freq[i];
                if(coins>=cost){
                    ans+=freq[i];
                    coins-=cost;
                }
                else{
                    ans+=(coins/i);
                    coins=coins-(i*(coins/i));
                }
            }
        }
        return ans;
    }
};