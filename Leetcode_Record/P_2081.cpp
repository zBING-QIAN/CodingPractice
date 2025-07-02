#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> buf;
    bool iskmirror(long long v, int k)
    {
        int i = 0;
        for (; v; i++)
        {
            buf[i] = v % k;
            v /= k;
        }
        for (int j = (i >> 1) - 1; j >= 0; j--)
            if (buf[i - j - 1] != buf[j])
                return 0;
        return 1;
    }

    long long kMirror(int k, int n)
    {
        long long ans = 0;
        buf.resize(70, 0);
        priority_queue<long long> pq;
        for (int i = 1;; i++)
        {
            // cout<<i<<endl;
            long long v = 0, pow10 = 1, itmp = i;
            while (itmp)
            {
                v *= 10;
                v += itmp % 10;
                pow10 *= 10;
                itmp /= 10;
            }
            if (pq.size() == n && v + pow10 * (i / 10) > pq.top())
                break;
            if (iskmirror(v + pow10 * (i / 10), k))
            {
                pq.push(v + pow10 * (i / 10));
            }
            if (iskmirror(v + pow10 * i, k))
            {
                pq.push(v + pow10 * i);
            }
            while (pq.size() > n)
                pq.pop();
        }
        while (pq.size())
        {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};