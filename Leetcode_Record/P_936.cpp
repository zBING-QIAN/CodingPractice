#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> movesToStamp(string stamp, string target)
    {
        int n = target.size(), m = stamp.size();
        vector<int> ans;
        int cnt = n;
        int pre;
        do
        {
            pre = cnt;
            for (int i = 0; i + m - 1 < n; i++)
            {

                int j = 0, c = 0;
                for (; j < m; j++)
                {
                    if (target[i + j] == stamp[j])
                    {
                        c++;
                    }
                    else if (target[i + j] != '*' || c)
                    {
                        break;
                    }
                }
                if ((j == m || target[i + j] == '*') && c)
                {
                    for (j = 0; j < m; j++)
                    {
                        if (target[i + j] != '*')
                        {
                            target[i + j] = '*';
                            cnt--;
                        }
                    }
                    ans.push_back(i);
                }
            }
        } while (cnt && cnt != pre);
        reverse(ans.begin(), ans.end());
        if (cnt == 0)
            return ans;
        return vector<int>();
    }
};