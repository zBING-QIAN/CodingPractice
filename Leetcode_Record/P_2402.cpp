#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int mostBooked(int n, vector<vector<int>> &meetings)
    {
        vector<int> cnt(n, 0);
        vector<long long> times(n, 0);
        sort(meetings.begin(), meetings.end());
        for (auto &m : meetings)
        {
            int best = 0;
            for (int i = 0; i < n; i++)
            {

                if (times[i] <= m[0])
                {
                    best = -1;
                    times[i] = m[1];
                    cnt[i]++;
                    break;
                }
                else if (times[best] > times[i])
                {
                    best = i;
                }
            }

            if (best >= 0)
            {
                times[best] = times[best] + m[1] - m[0];
                cnt[best]++;
            }
            // cout<<m[0]<<" "<<m[1]<<" "<<best<<" "<<times[best]<<endl;
        }
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            if (cnt[i] > cnt[ans])
                ans = i;
        }
        return ans;
    }
};