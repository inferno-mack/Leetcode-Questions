class Solution {
public:
    void sortColors(vector<int>& a) {
        int l = 0, r = a.size() - 1;
        for(int i = 0; i <= r; i++){
            while(i <= r and a[i] == 2){
                swap(a[i], a[r--]);
            }
            if(i > r) break;
            if(a[i] == 0){
                swap(a[i], a[l]);
                l++;
            }
        }
    }
};