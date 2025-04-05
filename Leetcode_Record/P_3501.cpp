#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int search(vector<int> &tree, int l, int r, int m, int n)
    {
        if (l >= r)
            return 0;
        else
        {
            int curl = l + m, curr = r + m, out = max(tree[l + m], tree[r + m]);
            while (curl > 0 && curr > 0 && (curl >> 1) != (curr >> 1))
            {
                if ((curl & 1) == 0)
                {
                    out = max(tree[curl + 1], out);
                }
                if (curr & 1)
                {
                    out = max(tree[curr - 1], out);
                }
                curl >>= 1;
                curr >>= 1;
            }
            return out;
        }
    }
    int run(vector<int> &tree, vector<int> &l0, vector<int> &l1, vector<int> &r0, vector<int> &r1, int l, int r, int m, string &s, int cnt1)
    {
        int n = s.size();
        int out = search(tree, r1[l] + 1, l1[r] - 1, m, n);
        if (s[l] == '0')
        {
            int tmp = min(r, r0[r1[l]]);
            if (tmp - r1[l] > 0)
            {
                int c = r0[l] - l + 1 + (tmp - r1[l]);
                out = max(c, out);
            }
        }
        if (s[r] == '0')
        {
            int tmp = max(l, l0[l1[r]]);
            if (l1[r] - tmp > 0)
            {
                int c = r - l0[r] + 1 + (l1[r] - tmp);
                out = max(c, out);
            }
        }
        return out + cnt1;
    }
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>> &queries)
    {
        int n = s.size(), m = 1, cnt1 = 0;
        for (; m < n; m <<= 1)
            ;
        vector<int> l0(n, 0), r0(n, 0), l1(n, 0), r1(n, 0), tree(m << 1, 0), ans;
        for (int i = 0, last0 = 0, last1 = 0; i < n; i++)
        {
            if (s[i] == '1')
                cnt1++;
            if (s[i] == '1' && (i == 0 || s[i - 1] == '0'))
                last1 = i;
            if (s[i] == '0' && (i == 0 || s[i - 1] == '1'))
                last0 = i;
            l0[i] = last0;
            l1[i] = last1;
        }
        for (int i = n - 1, last0 = n - 1, last1 = n - 1; i >= 0; i--)
        {
            if (s[i] == '1' && (i == n - 1 || s[i + 1] == '0'))
                last1 = i;
            if (s[i] == '0' && (i == n - 1 || s[i + 1] == '1'))
                last0 = i;
            r0[i] = last0;
            r1[i] = last1;
        }
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1' && l1[i] - l0[i] > 0 && r0[i] - r1[i] > 0)
                tree[m + i] = r0[i] - r1[i] + l1[i] - l0[i];
        }
        for (int i = m - 1; i; i--)
            tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
        for (auto &q : queries)
        {
            ans.push_back(run(tree, l0, l1, r0, r1, q[0], q[1], m, s, cnt1));
        }
        return ans;
    }
};