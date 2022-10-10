class Solution {
public:    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int aheadNotBuy=0, aheadBuy=0, currNotBuy=0, currBuy=0;
        
        aheadNotBuy=aheadBuy=0;
        
        for(int ind=n-1;ind>=0;ind--){
            currBuy=max(-prices[ind]+aheadNotBuy, 0 + aheadBuy);
            currNotBuy=max(prices[ind]+aheadBuy, 0+aheadNotBuy);
            aheadNotBuy=currNotBuy;
            aheadBuy=currBuy;
        }
        return aheadBuy;
    }
};