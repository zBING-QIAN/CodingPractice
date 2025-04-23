#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int tree_query(vector<int> &tree, int l, int r, int ts, int k)
    {
        if (l == r)
            return tree[l + ts];
        l += ts, r += ts;
        int res = (tree[l] * tree[r]) % k;
        while ((l >> 1) != (r >> 1) && res)
        {
            if ((l & 1) == 0)
                res *= tree[l + 1];
            if (r & 1)
                res *= tree[r ^ 1];
            res %= k;
            l >>= 1;
            r >>= 1;
        }
        return res;
    }
    void tree_update(vector<int> &tree, int pos, int v, int ts, int k)
    {
        pos += ts;
        tree[pos] = v % k;
        while (pos)
        {
            tree[pos >> 1] = (tree[pos] * tree[pos ^ 1]) % k;
            pos >>= 1;
        }
    }
    vector<int> dp_query(vector<vector<int>> &dp, vector<int> &tree, int pos, int k, int ts)
    {
        vector<int> res = dp[pos];
        int bits = pos - (pos & -pos);
        while (bits)
        {
            int interval = tree_query(tree, bits, pos - 1, ts, k);
            for (int i = 0; i < k; i++)
            {
                res[(interval * i) % k] += dp[bits][i];
            }
            bits -= (bits & -bits);
        }
        return res;
    }
    void dp_update(vector<vector<int>> &dp, vector<int> &tree, int pos, int v, int k, int n, int ts)
    {
        vector<int> buf = dp[pos];
        int bup = pos + (pos & -pos), bdown = pos - (pos & -pos);
        while (bup < n)
        {
            while (bdown && ((bdown & -bdown)) < (bup & -bup))
            {
                int interval = tree_query(tree, bdown, pos - 1, ts, k);
                for (int i = 0; i < k; i++)
                {
                    buf[(interval * i) % k] += dp[bdown][i];
                }
                bdown -= (bdown & -bdown);
            }
            int interval = (pos + 1 == bup) ? 1 : tree_query(tree, pos + 1, bup - 1, ts, k);
            for (int i = 0; i < k; i++)
            {
                dp[bup][(interval * i * tree[ts + pos]) % k] -= buf[i];
            }
            for (int i = 0; i < k; i++)
            {
                dp[bup][(interval * i * v) % k] += buf[i];
            }
            bup += (bup & -bup);
        }
        tree_update(tree, pos, v, ts, k);
    }

    vector<int> resultArray(vector<int> &nums, int k, vector<vector<int>> &queries)
    {
        nums.push_back(0);
        int n = nums.size();
        reverse(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
            nums[i] %= k;
        vector<vector<int>> dp(n + 5, vector<int>(k, 0));
        vector<int> res;
        int ts = 1;
        for (; ts < n; ts <<= 1)
            ;
        vector<int> tree(ts << 1, 0);
        for (int i = 0; i < n; i++)
            tree[ts + i] = nums[i];
        for (int i = ts - 1; i; i--)
            tree[i] = (tree[i << 1] * tree[(i << 1) + 1]) % k;
        for (int i = 1; i < n; i++)
        {
            int idx = i + (i & -i);
            if (k > 1)
                dp[i][1]++;
            else
                dp[i][0]++;
            while (idx < n)
            {
                int interval = tree_query(tree, i, idx - 1, ts, k);
                dp[idx][interval]++;
                idx += (idx & -idx);
            }
        }
        // cout<<"dp init  \n";
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<k;j++){
        //         cout<<dp[i][j]<<" ";
        //     }cout<<endl;
        // }cout<<endl;
        for (auto &q : queries)
        {
            int ans = 0, pos = n - q[0] - 1, st = n - q[2] - 1;
            // dp update
            dp_update(dp, tree, pos, q[1] % k, k, n, ts);
            // dp query
            vector<int> tmp = dp_query(dp, tree, st, k, ts);
            for (int i = 0; i < k; i++)
            {
                int vmk = (i * tree[ts + st]) % k;
                if (vmk == q[3])
                    ans += tmp[i];
            }
            // for(int i=0;i<n;i++){
            //     for(int j=0;j<k;j++){
            //         cout<<dp[i][j]<<" ";
            //     }cout<<endl;
            // }cout<<endl;

            // for(int i = 1;i<(ts<<1);i++){cout<<tree[i]<<" ";}cout<<endl;
            res.push_back(ans);
        }
        return res;
    }
};