class Solution
{
    public:
        string longestCommonPrefix(vector<string> &strs)
        {
            string ans = "";

            int len = INT_MAX;
            for (int i = 0; i < strs.size(); i++)
            {
                len = min(len, (int)(strs[i].size()));
            }

            bool flag = true;
            for (int j = 0; j <= len - 1; j++)
            {
                for (int i = 0; i < strs.size() - 1; i++)
                {
                    if (strs[i][j] != strs[i + 1][j])
                    {
                        flag = false;
                        break;
                    }
                }

                if (flag == false) break;
                else
                {
                    ans += strs[0][j];
                }
            }
            return ans;
        }
};