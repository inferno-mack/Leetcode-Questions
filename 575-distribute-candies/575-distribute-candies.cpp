class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        map<int,int> mp;
        int n=candyType.size();
        for(int i=0;i<candyType.size();i++)
            mp[candyType[i]]++;
        
        if(mp.size()<=(n/2))
            return mp.size();
        return (n/2);
    }
};