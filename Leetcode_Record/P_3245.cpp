#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int query(vector<int> &seg, vector<int> &lazy, int pos, int ts, int n)
    {
        int res = 0, l = 0, r = ts - 1, cur = 1;
        // for(int i=0;i<ts*2;i++)cout<<seg[i]<<" "<<lazy[i]<<"      ";cout<<endl;
        while (l < r)
        {
            if (cur < ts && lazy[cur] != 0)
            {
                lazy[cur * 2] += lazy[cur];
                lazy[cur * 2 + 1] += lazy[cur];
            }
            seg[cur] += lazy[cur] * (r - l + 1);
            lazy[cur] = 0;
            int mid = (l + r) >> 1;
            if (pos <= mid)
            {
                cur *= 2;
                r = mid;
            }
            else
            {
                res += (seg[cur * 2] + lazy[cur * 2] * (r - mid));
                cur = cur * 2 + 1;
                l = mid + 1;
            }
            // cout<<cur<<" "<<res<<" "<<l<<" "<<r<<" "<<pos<<endl;
        }
        return n - res;
    }
    void range_update(vector<int> &seg, vector<int> &lazy, int cur, int left, int right, int value, int l, int r, int n)
    {
        // cout<<"update \n";
        // cout<<cur<<" "<<left<<" "<<right<<" "<<l<<" "<<r<<" "<<value<<endl;
        if (left <= l && right >= r)
        {
            lazy[cur] += value;
            return;
        }
        seg[cur] += (right - left + 1) * value;
        int mid = (l + r) >> 1;
        if (left <= mid)
            range_update(seg, lazy, cur * 2, left, min(mid, right), value, l, mid, n);
        if (right > mid)
            range_update(seg, lazy, cur * 2 + 1, max(left, mid + 1), right, value, mid + 1, r, n);
    }
    vector<int> numberOfAlternatingGroups(vector<int> &colors, vector<vector<int>> &queries)
    {
        map<int, int> chain_head;
        int n = colors.size(), ts = 1;
        for (; ts <= n; ts <<= 1)
            ;
        vector<int> seg(ts << 1, 0), lazy(ts << 1, 0), res;
        vector<int> aux(n, 0);
        bool is_loop = false;
        for (int i = 0, j = 1; i < n; i++)
        {
            if (i == j)
                j++;
            while ((j % n) != i && colors[j % n] != colors[(j - 1) % n])
                j++;
            aux[i] = j;
            if (i == 0 || aux[i - 1] <= i)
            {
                chain_head[i] = j - i;
                if (j - i == n)
                    is_loop = 1;
            }
            seg[ts + j - i]++;
        }
        if (aux[n - 1] > n && chain_head.size() > 1)
            chain_head.erase(0);
        for (int i = ts - 1; i; i--)
            seg[i] = seg[i << 1] + seg[(i << 1) + 1];
        for (auto &q : queries)
        {
            if (q[0] == 1)
            {
                res.push_back(query(seg, lazy, q[1], ts, n));
            }
            else
            {
                // for(auto gg:chain_head)cout<<gg.first<<" "<<gg.second<<"     ";cout<<endl;
                if (colors[q[1]] == q[2])
                    continue;
                colors[q[1]] = q[2];
                int next_pos = (q[1] + 1) % n, prev_pos = (q[1] - 1 + n) % n;
                int cond1 = (colors[q[1]] != colors[next_pos]);
                int cond0 = (colors[q[1]] != colors[prev_pos]);
                if (cond0)
                {
                    auto cur = chain_head.find(q[1]);
                    auto pre = (cur == chain_head.begin()) ? chain_head.end() : cur;
                    pre--;
                    if (cond1)
                    {
                        auto nxt = chain_head.find(next_pos);
                        range_update(seg, lazy, 1, 1, pre->second, -1, 0, ts - 1, n);
                        pre->second += 1;
                        if (nxt != pre)
                        {
                            pre->second += nxt->second;
                            range_update(seg, lazy, 1, 1, pre->second, 1, 0, ts - 1, n);
                            range_update(seg, lazy, 1, 1, nxt->second, -1, 0, ts - 1, n);
                            chain_head.erase(next_pos);
                            range_update(seg, lazy, 1, 1, 1, -1, 0, ts - 1, n);
                        }
                        else
                        {
                            range_update(seg, lazy, 1, 1, 1, -1, 0, ts - 1, n);
                            range_update(seg, lazy, 1, pre->second, pre->second, n, 0, ts - 1, n);
                        }
                    }
                    else
                    {
                        range_update(seg, lazy, 1, cur->second, cur->second, -1, 0, ts - 1, n);
                        cur->second -= 1;
                        pre->second += 1;
                        range_update(seg, lazy, 1, pre->second, pre->second, 1, 0, ts - 1, n);
                        chain_head[next_pos] = cur->second;
                    }
                    chain_head.erase(q[1]);
                }
                else
                {
                    auto pre = chain_head.lower_bound(q[1]);
                    if (pre == chain_head.begin())
                        pre = chain_head.end();
                    pre--;
                    if (cond1)
                    {
                        auto nxt = chain_head.find(next_pos);
                        range_update(seg, lazy, 1, pre->second, pre->second, -1, 0, ts - 1, n);
                        pre->second--;
                        range_update(seg, lazy, 1, 1 + nxt->second, 1 + nxt->second, 1, 0, ts - 1, n);
                        chain_head[q[1]] = 1 + nxt->second;
                        chain_head.erase(next_pos);
                    }
                    else
                    {
                        int cur_pos = q[1];
                        int end_pos = pre->first + pre->second;
                        if (pre->first > cur_pos)
                            cur_pos += n;
                        if (pre->second == n && ((n & 1) == 0))
                        {
                            range_update(seg, lazy, 1, n, n, -n, 0, ts - 1, n);
                            end_pos = cur_pos + n;
                            chain_head.erase(pre);
                        }
                        else
                        {
                            range_update(seg, lazy, 1, 1, pre->second, -1, 0, ts - 1, n);
                            pre->second = cur_pos - pre->first;
                            range_update(seg, lazy, 1, 1, pre->second, 1, 0, ts - 1, n);
                        }

                        range_update(seg, lazy, 1, 1, end_pos - cur_pos - 1, 1, 0, ts - 1, n);
                        chain_head[next_pos] = end_pos - cur_pos - 1;

                        range_update(seg, lazy, 1, 1, 1, 1, 0, ts - 1, n);
                        chain_head[q[1]] = 1;
                    }
                }
                // cout<<"after \n";
                // for(auto gg:chain_head)cout<<gg.first<<" "<<gg.second<<"     ";cout<<endl;
            }
        }
        return res;
    }
};