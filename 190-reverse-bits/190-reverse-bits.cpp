class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ans=0,i=0;
        while(i<32)
        {
            int bit=(n&1);
            ans=(ans<<1)+bit;
            n=n>>1;
            i++;
        }
        
        return ans;
    }
};