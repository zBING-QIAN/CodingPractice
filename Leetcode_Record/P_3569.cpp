#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct Node
    {
        int maxn, v;
        Node()
        {
            maxn = 0;
            v = 0;
        }
    };
    void range_update(int l, int r, int v, vector<Node> &seg, int cur, int left, int right)
    {
        // cout<<cur<<" "<<left<<" "<<right<<" "<<seg[cur].maxn<<" "<<l<<" "<<r<<" "<<v<<endl;
        if (left >= l && right <= r)
        {
            seg[cur].v += v;
            return;
        }
        if (cur * 2 + 1 < seg.size() && seg[cur].v)
        {
            seg[cur << 1].v += seg[cur].v;
            seg[(cur << 1) + 1].v += seg[cur].v;
            seg[cur].v = 0;
        }
        int mid = (left + right) >> 1;
        if (l <= mid)
        {
            range_update(l, min(mid, r), v, seg, cur << 1, left, mid);
        }
        if (r > mid)
        {
            range_update(max(mid + 1, l), r, v, seg, (cur << 1) + 1, mid + 1, right);
        }
        if (cur * 2 + 1 < seg.size())
            seg[cur].maxn = max(seg[cur << 1].maxn + seg[cur << 1].v, seg[1 + (cur << 1)].maxn + seg[(cur << 1) + 1].v);
    }

    vector<int> maximumCount(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        vector<bool> primes(1e5 + 1, 1);
        primes[1] = 0;
        primes[0] = 0;
        for (int i = 2; i * i <= 1e5; i++)
        {
            if (primes[i])
                for (int j = i * i; j <= 1e5; j += i)
                    primes[j] = 0;
        }
        map<int, set<int>> prim_pos;
        int sz = 1;
        for (; sz < n; sz <<= 1)
            ;
        vector<Node> seg(sz << 1, Node());

        for (int i = 0; i < n; i++)
        {
            if (primes[nums[i]])
                prim_pos[nums[i]].insert(i);
        }
        set<int> pos;
        for (int i = 0; i < n; i++)
        {
            seg[sz + i].maxn = pos.size();
            if (primes[nums[i]])
                pos.insert(nums[i]);
        }
        pos.clear();
        for (int i = n - 1; i; i--)
        {
            if (primes[nums[i]])
                pos.insert(nums[i]);
            seg[sz + i].maxn += pos.size();
        }
        for (int i = sz - 1; i; i--)
        {
            int l = i << 1, r = (i << 1) + 1;
            seg[i].maxn = max(seg[l].maxn, seg[r].maxn);
        }
        vector<int> ans;
        for (auto q : queries)
        {
            int idx = q[0], val = q[1];
            // cout<<"query "<<q[0]<<" "<<q[1]<<endl;
            if (nums[idx] == val)
            {
                ans.push_back(seg[1].maxn);
                continue;
            }
            if (primes[nums[idx]])
            {
                int f = *prim_pos[nums[idx]].begin(), e = *prim_pos[nums[idx]].rbegin();
                prim_pos[nums[idx]].erase(idx);
                if (prim_pos[nums[idx]].size() == 0)
                {
                    range_update(1, sz - 1, -1, seg, 1, 0, sz - 1);
                }
                else
                {
                    if (f < *prim_pos[nums[idx]].begin())
                    {
                        range_update(f + 1, *prim_pos[nums[idx]].begin(), -1, seg, 1, 0, sz - 1);
                    }
                    if (e > *prim_pos[nums[idx]].rbegin())
                    {
                        range_update(*prim_pos[nums[idx]].rbegin() + 1, e, -1, seg, 1, 0, sz - 1);
                    }
                }
            }
            if (primes[val])
            {
                int f = n - 1, e = 0;
                if (prim_pos[val].size() > 0)
                {
                    f = *prim_pos[val].begin(), e = *prim_pos[val].rbegin();
                }
                prim_pos[val].insert(idx);
                if (idx < f)
                {
                    range_update(idx + 1, f, 1, seg, 1, 0, sz - 1);
                }
                if (idx > e)
                {
                    range_update(e + 1, idx, 1, seg, 1, 0, sz - 1);
                }
            }
            nums[idx] = val;
            ans.push_back(seg[1].maxn + seg[1].v);
        }
        return ans;
    }
};