#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool same(vector<int> &s, int a, int b, int len)
    {
        for (int i = 0; i < len; i++, a++, b++)
        {
            if (s[a] != s[b])
                return 0;
        }
        return 1;
    }
    void induce_sort(vector<int> &s, vector<int> &sa, vector<int> &lms, vector<int> &bucket, vector<bool> &types)
    {
        int n = s.size();
        sa.assign(n, 0);
        vector<int> _bucket = bucket;
        for (int i = lms.size() - 1; i >= 0; i--)
            sa[--_bucket[s[lms[i]]]] = lms[i];
        for (int i = 1; i < bucket.size(); i++)
            _bucket[i] = bucket[i - 1];
        for (int i = 0; i < n; i++)
        {
            if (sa[i] > 0 && !types[sa[i] - 1])
                sa[_bucket[s[sa[i] - 1]]++] = sa[i] - 1;
        } // L-type
        _bucket = bucket;
        for (int i = n - 1; i >= 0; i--)
        {
            if (sa[i] > 0 && types[sa[i] - 1])
                sa[--_bucket[s[sa[i] - 1]]] = sa[i] - 1;
        } // S-type
    }
    void sais(vector<int> &s, vector<int> &sa, int symbols = 27)
    {
        int n = s.size();
        sa.assign(n, 0);
        vector<int> bucket(symbols, 0);
        vector<bool> types(n, 0);
        for (auto &i : s)
            bucket[i]++;
        for (int i = 1; i < symbols; i++)
        {
            bucket[i] += bucket[i - 1];
        }
        types[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--)
            types[i] = (s[i] < s[i + 1] || (s[i] == s[i + 1] && types[i + 1]));
        int lms_size = 0;
        vector<int> lms2s, s2lms(n, -1);
        for (int i = 1; i < n; i++)
        {
            if (types[i] && !types[i - 1])
            {
                lms2s.push_back(i);
                s2lms[i] = lms_size++;
            }
        }
        induce_sort(s, sa, lms2s, bucket, types);
        int cnt = -1;
        vector<int> lms(lms_size, 0);
        for (int prev = -1, prev_len = 0, i = 0; i < n; i++)
        {
            int cur = s2lms[sa[i]];
            if (cur >= 0)
            {
                int len = (cur + 1 < lms_size) ? lms2s[cur + 1] - lms2s[cur] : 1;
                if (prev_len != len || !same(s, lms2s[cur], lms2s[prev], len))
                    cnt++;
                lms[cur] = cnt;
                prev = cur;
                prev_len = len;
            }
        }
        if (cnt + 1 == lms_size)
        {
            for (int i = 0; i < lms_size; i++)
                sa[lms[i]] = i;
        }
        else
            sais(lms, sa, cnt + 1);
        for (int i = 0; i < lms_size; i++)
            lms[i] = lms2s[sa[i]];
        induce_sort(s, sa, lms, bucket, types);
    }
    vector<int> preprocess(string &s, string &pattern)
    {
        int n = s.size(), m = pattern.size();
        vector<int> stmp;
        for (auto c : s)
            stmp.push_back(c - 'a' + 1);
        stmp.push_back(0);
        vector<int> sa(n + 1, 0), out(n, 0);
        vector<int> rank(n, 0), lcp(n, -1);
        sais(stmp, sa);
        // cout<<"sais finish\n";
        // for(int i=0;i<=n;i++)cout<<sa[i]<<" ";cout << endl;
        for (int i = 0; i < n; i++)
        {
            sa[i] = sa[i + 1];
            rank[sa[i]] = i;
        }

        for (int i = 0; i < n; i++)
        {
            int next = rank[i], length = 0;
            while (next + 1 < n && length >= 0 && lcp[next] == -1)
            {
                char *a = &s[0] + sa[next], *b = &s[0] + sa[next + 1];
                while (a[length] && b[length] && a[length] == b[length])
                    length++;
                lcp[next] = length--;
                if (sa[next] + 1 < n)
                    next = rank[sa[next] + 1];
            }
        }
        // cout<<"lcp finish\n";
        // for(int i=0;i<n;i++)cout<<lcp[i]<<" ";cout << endl;
        for (int i = 0, len = 0; i < n; i++)
        {
            // cout<<i<<" "<<sa[i]<<" "<<len<<endl;
            while (len < m && len + sa[i] < n && s[sa[i] + len] == pattern[len])
            {
                len++;
            }
            out[sa[i]] = len;
            len = min(len, lcp[i]);
        }
        // cout<<"preprocess done\n";
        return out;
    }

    int minStartingIndex(string s, string pattern)
    {
        int n = pattern.size(), m = s.size();
        int ans = m;
        vector<int> prev = preprocess(s, pattern);
        reverse(s.begin(), s.end());
        reverse(pattern.begin(), pattern.end());
        vector<int> post = preprocess(s, pattern);
        reverse(post.begin(), post.end());
        // cout<<"prev \n";
        // for(int i=0;i<m;i++)cout<<prev[i]<<" ";cout<<endl;
        // cout<<"post \n";
        // for(int i=0;i<m;i++)cout<<post[i]<<" ";cout<<endl;
        for (int i = 0; i + n <= m; i++)
        {
            if (prev[i] + post[i + n - 1] >= n - 1)
                return i;
        }
        return -1;
    }
};
