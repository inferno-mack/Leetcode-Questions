class Solution {
public:
    int hammingWeight(uint32_t n) {
        int countsetbit=0;
        while(n)
        {
            n=n & (n-1);
            countsetbit++;
        }
        
        return countsetbit;
    }
};