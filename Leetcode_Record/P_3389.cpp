#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int makeStringGood(string s)
    {
        vector<int> cnt(26, 0);
        for (auto c : s)
            cnt[c - 'a']++;

        int ans = s.size();
        for (int t = 0; t <= s.size(); t++)
        {
            int cost0 = 0, costt = 0, r0 = 0, rt = 0;
            for (int i = 0; i < 26; i++)
            {
                int cost0_prev = cost0, costt_prev = costt;
                if (cnt[i] > 0)
                {
                    if (cnt[i] < t)
                    {
                        int tmp = s.size();
                        if (r0 + cnt[i] >= t)
                            tmp = cost0_prev;
                        else
                            tmp = cost0_prev + t - (cnt[i] + r0);
                        if (rt + cnt[i] >= t)
                            tmp = min(tmp, costt_prev);
                        else
                            tmp = min(tmp, costt_prev + t - (cnt[i] + rt));
                        rt = 0;
                        costt = tmp;
                    }
                    else
                    {
                        rt = cnt[i] - t;
                        costt = min(costt_prev, cost0_prev) + rt;
                    }
                    cost0 = min(cost0_prev, costt_prev) + cnt[i];
                    r0 = cnt[i];
                }
                else
                {
                    r0 = 0;
                    rt = 0;
                }
            }
            ans = min(ans, min(cost0, costt));
        }

        return ans;
    }
};