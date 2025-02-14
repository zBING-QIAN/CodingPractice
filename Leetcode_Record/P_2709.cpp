#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int head(int cur, vector<int> &rec)
    {
        vector<int> stac;
        while (cur != rec[cur])
        {
            stac.push_back(cur);
            cur = rec[cur];
        }
        while (stac.size())
        {
            rec[stac.back()] = cur;
            stac.pop_back();
        }
        return cur;
    }
    bool canTraverseAllPairs(vector<int> &nums)
    {
        if (nums.size() == 1)
            return 1;
        vector<int> rec(1e5 + 5, 0);
        vector<bool> prime(1e5 + 5, 1), has_num(1e5 + 5, 0);
        for (auto n : nums)
        {
            has_num[n] = 1;
            if (n == 1)
                return 0;
        }
        for (int i = 0; i < 1e5 + 4; i++)
            rec[i] = i;
        for (int i = 2; i < 1e5; i++)
        {
            if (prime[i])
            {
                int cur = head(i, rec);
                long long start = 1e5 - (100000) % i, end = 1ll * i * i;
                for (int j = start; j >= end; j -= i)
                {
                    prime[j] = 0;
                    if (has_num[j])
                    {
                        int jtmp = j;
                        int jhead;
                        while ((jtmp % i) == 0 && jtmp > i)
                        {
                            jhead = head(jtmp, rec);
                            rec[jhead] = cur;
                            has_num[jtmp] = 0;
                            jtmp /= i;
                        }
                        has_num[jtmp] = 1;
                        jhead = head(jtmp, rec);
                        rec[jhead] = cur;
                    }
                }
            }
        }
        int h = 0;
        for (int i = 2; i < 1e5 + 2; i++)
        {
            if (has_num[i])
            {
                int tmp = head(i, rec);
                // cout<<i<<" "<<tmp<<endl;
                if (h == 0)
                    h = tmp;
                else if (h != tmp)
                    return 0;
            }
        }
        return 1;
    }
};