#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double ans;
    double minTime(int n, int k, int m, vector<int> &time, vector<double> &mul)
    {
        if (k <= 1)
        {
            if (n > 1)
                return -1;
            else
                return mul[0] * time[0];
        }
        if (n == 1)
            return mul[0] * time[0];
        ans = 1e9;
        sort(time.begin(), time.end());
        int state = (1 << time.size()) - 1;
        vector<vector<vector<double>>> rec(state + 1, vector<vector<double>>(m, vector<double>(2, 1e9)));
        rec[state][0][0] = 0;
        set<pair<double, pair<int, int>>> pq;
        pq.insert({0, {0, state}});
        double ans = 1e9;
        while (pq.size())
        {
            auto tss = *pq.begin();
            if (tss.second.second == 0)
                return tss.first;
            pq.erase(pq.begin());
            int cur_state = tss.second.second;
            double t = tss.first;
            int stage = tss.second.first;
            bool isback = stage >= 100;
            if (stage >= 100)
                stage -= 100;
            if (rec[cur_state][stage][isback] < t)
                continue;

            for (int s = 0; s <= state; s++)
            {
                int dif = cur_state ^ s;
                int to = dif & cur_state;
                int back = dif & s;
                int tocnt = __builtin_popcount(to);
                int backcnt = __builtin_popcount(back);
                if (isback && tocnt == 0 && backcnt > 0 && backcnt <= k)
                {
                    int maxb = 0;
                    for (int i = n - 1; i >= 0; i--)
                        if ((1 << i) & back)
                        {
                            maxb = time[i];
                            break;
                        }
                    double backt = mul[stage] * maxb;
                    double cur_time = t + backt;
                    int backstage = backt;
                    backstage = (stage + backstage) % m;
                    if (cur_time < ans && rec[s][backstage][0] > cur_time)
                    {
                        pq.insert({cur_time, {backstage, s}});
                        rec[s][backstage][0] = cur_time;
                    }
                }
                else if (!isback && backcnt == 0 && tocnt > 0 && tocnt <= k)
                {
                    int maxt = 0;
                    for (int i = n - 1; i >= 0; i--)
                        if ((1 << i) & to)
                        {
                            maxt = time[i];
                            break;
                        }
                    double tot = mul[stage] * maxt;
                    double cur_time = t + tot;
                    int tostage = tot;
                    tostage = (tostage + stage) % m;
                    if (cur_time < ans && rec[s][tostage][1] > cur_time)
                    {
                        pq.insert({cur_time, {100 + tostage, s}});
                        if (s == 0)
                            ans = min(cur_time, ans);
                        rec[s][tostage][1] = cur_time;
                    }
                }
            }
        }

        return -1;
    }
};