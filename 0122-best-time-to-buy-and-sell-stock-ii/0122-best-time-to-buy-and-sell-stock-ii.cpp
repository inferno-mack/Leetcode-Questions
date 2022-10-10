class Solution {
public:    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int aheadNotBuy=0, aheadBuy=0, currNotBuy=0, currBuy=0;
        
        aheadNotBuy=aheadBuy=0;
        
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                    int profit=0;
                    if(buy)
                        profit=max(-prices[ind]+aheadNotBuy, 0 + aheadBuy);
                    else
                        profit=max(prices[ind]+aheadBuy, 0+aheadNotBuy);

                    if(buy)
                        currBuy=profit;
                    else
                        currNotBuy=profit;
            }
            aheadNotBuy=currNotBuy;
            aheadBuy=currBuy;
        }
        return aheadBuy;
    }
};