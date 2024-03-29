class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        int ans=INT_MIN;
        unordered_set<char> st;
        int low=0;
        
        for(int i=0;i<s.size();i++){
            int len=st.size();
            st.insert(s[i]);
            if(len==st.size()){
                while(s[low]!=s[i]){
                    st.erase(s[low]);
                    low++;
                }
                low++;
            }
            ans=max(ans, (int)st.size());
        }
        return ans;
    }
};