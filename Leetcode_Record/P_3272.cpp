#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<long long> bar;
    long long calc(string &s, int n)
    {

        long long out = bar[n];
        for (int i = 0; i < 10; i++)
        {
            // cout<<0+s[i]<<" ";
            if (s[i] > 0)
                out /= bar[s[i]];
        }
        // cout<<endl;
        if (s[0] > 0)
        {
            long long tmp = bar[n - 1] / bar[s[0] - 1];
            for (int i = 1; i < 10; i++)
            {
                if (s[i] > 0)
                    tmp /= bar[s[i]];
            }
            // cout<<out-tmp<<endl;
            return out - tmp;
        }
        // cout<<out<<endl;
        return out;
    }
    long long countGoodIntegers(int n, int k)
    {
        if (n == 1)
            return 9 / k;
        int lim = 1;
        bool odd = n & 1;
        long long ans = 0;
        set<string> rec;
        bar.resize(11, 1);
        for (int i = 1; i <= 10; i++)
            bar[i] = bar[i - 1] * i;
        for (int i = 0; i < n / 2; i++, lim *= 10)
            ;
        for (int i = 1; i < lim; i++)
        {
            if ((i % 10) == 0)
                continue;
            string cur = "0000000000";
            long long rev = 0;
            for (int tmp = i, j = 0; j < n / 2; tmp /= 10, j++)
            {
                cur[tmp % 10]++;
                rev *= 10;
                rev += tmp % 10;
            }
            for (int j = 0; j < 10; j++)
            {
                cur[j] = (cur[j] - '0') * 2;
            }
            rev *= lim;
            if (odd)
            {
                rev *= 10;
                for (int j = 0; j < 10; j++)
                {
                    bool done = 0;
                    cur[j]++;
                    if (((rev + j * lim + i) % k) == 0 && rec.find(cur) == rec.end())
                    {
                        // cout<<(rev+j*lim+i)<<endl;
                        ans += calc(cur, n);
                        done = 1;
                    }
                    if (done)
                        rec.insert(cur);
                    cur[j]--;
                }
            }
            else
            {
                bool done = 0;
                if (((rev + i) % k) == 0 && rec.find(cur) == rec.end())
                {
                    ans += calc(cur, n);
                    done = 1;
                }
                if (done)
                    rec.insert(cur);
            }
        }
        return ans;
    }
};