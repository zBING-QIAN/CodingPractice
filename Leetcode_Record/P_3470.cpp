#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> permute(int n, long long k)
    {
        set<int> odd, even;
        for (int i = 1; i <= n; i++)
        {
            if (i & 1)
                odd.insert(i);
            else
                even.insert(i);
        }
        vector<int> ans;
        for (int i = 1; i <= n; i++)
        {
            if (i & 1)
            {
                long long cnto = 1;
                for (int j = 1; j < odd.size(); j++)
                {
                    cnto *= j;
                    if (cnto >= k)
                        break;
                }
                long long cnte = 1;
                for (int j = 1; j <= even.size(); j++)
                {
                    cnte *= j;
                    if (cnte >= k)
                        break;
                }
                if (cnte > 1e9 || cnto * cnte >= k)
                {
                    ans.push_back((*odd.begin()));
                    odd.erase(ans.back());
                }
                else
                {
                    long long tmp = cnte * cnto;
                    int order = (k - 1) / tmp;
                    if (k % tmp)
                        k = k % tmp;
                    else
                        k = tmp;
                    auto it = odd.begin();
                    if (i == 1 && (n & 1) == 0)
                    {
                        if (order >= n)
                            return {};
                        ans.push_back(order + 1);
                        if (order & 1)
                        {
                            even.erase(order + 1);
                            i++;
                            n++;
                        }
                        else
                        {
                            odd.erase(order + 1);
                        }
                    }
                    else
                    {
                        while (order)
                        {
                            it++;
                            if (it == odd.end())
                                return {};
                            order--;
                        }
                        ans.push_back((*it));
                        odd.erase(it);
                    }
                }
            }
            else
            {
                long long cnto = 1;
                for (int j = 1; j <= odd.size(); j++)
                {
                    cnto *= j;
                    if (cnto >= k)
                        break;
                }
                long long cnte = 1;
                for (int j = 1; j < even.size(); j++)
                {
                    cnte *= j;
                    if (cnte >= k)
                        break;
                }
                if (cnto > 1e9 || cnto * cnte >= k)
                {
                    ans.push_back((*even.begin()));
                    even.erase(ans.back());
                }
                else
                {
                    long long tmp = cnte * cnto;
                    int order = (k - 1) / tmp;
                    if (k % tmp)
                        k = k % tmp;
                    else
                        k = tmp;
                    auto it = even.begin();
                    while (order)
                    {
                        if (it != even.end())
                            it++;
                        else
                            return {};
                        order--;
                    }
                    ans.push_back((*it));
                    even.erase(it);
                }
            }
        }
        return ans;
    }
};