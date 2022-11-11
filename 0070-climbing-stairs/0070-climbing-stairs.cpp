class Solution {
public:
    int climbStairs(int n) {
        stack<pair<int,int>>s1;
        s1.push({1,2});
        
        if(n==1)
            return n;
        
        for(int i=2;i<n;i++)
        {
            s1.push({s1.top().second,s1.top().first+s1.top().second});
        }
            return s1.top().second;
    }
};