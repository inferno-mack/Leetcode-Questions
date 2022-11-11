class Solution {
public:
    int maxProfit(vector<int>& a) {
        int ans = 0;
        int sum = 0;
        for(int i = 1; i < a.size(); i++){
            sum = max({sum + a[i] - a[i - 1], a[i] - a[i - 1]});
            ans = max(ans, sum);
        }
        
        return ans;
    }
};