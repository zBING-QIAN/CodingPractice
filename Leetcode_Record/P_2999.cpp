#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long cnt(string &v, int limit, string &s)
    {
        if (v.size() < s.size())
            return 0;
        long long out = 1;
        long long tmplimit = 1;
        reverse(v.begin(), v.end());
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] > v[i])
            {
                out = 0;
                break;
            }
            else if (v[i] > s[i])
                break;
        }
        for (int i = s.size(); i < v.size(); i++)
        {
            if (limit >= v[i] - '0')
            {
                out += 1ll * (v[i] - '0') * tmplimit;
            }
            else
            {
                out = 1ll * (limit + 1) * tmplimit;
            }
            tmplimit *= (limit + 1);
        }
        return out;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s)
    {
        int len = s.size();
        for (int i = 0; i < len; i++)
        {
            if (s[i] - '0' > limit)
                return 0;
        }
        reverse(s.begin(), s.end());
        string f = to_string(finish), st = to_string(start - 1);
        return cnt(f, limit, s) - cnt(st, limit, s);
    }
};