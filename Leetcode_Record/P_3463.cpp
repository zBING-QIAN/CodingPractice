#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> cnm10;
    int inv(long long a, int p)
    {
        int n = p - 2;
        long long out = 1;
        while (n)
        {
            if (n & 1)
                out = (out * a) % p;
            a = (a * a) % p;
            n >>= 1;
        }
        return out;
    }
    void preprocess(int n)
    {
        map<array<int, 2>, int> table;
        table[{0, 0}] = 0;
        table[{0, 1}] = 6;
        table[{0, 2}] = 2;
        table[{0, 3}] = 8;
        table[{0, 4}] = 4;
        table[{1, 0}] = 5;
        table[{1, 1}] = 1;
        table[{1, 2}] = 7;
        table[{1, 3}] = 3;
        table[{1, 4}] = 9;
        vector<int> cnm5;
        cnm10.resize(n + 1, 1);
        cnm5.resize(n + 1, 1);
        int cnt2 = 0, cnt5 = 0;
        for (int i = 1; i <= n; i++)
        {
            int tmp1 = n - i + 1;
            while (tmp1 % 5 == 0)
            {
                cnt5++;
                tmp1 /= 5;
            }
            int tmp51 = tmp1;
            while (tmp1 % 2 == 0)
            {
                cnt2++;
                tmp1 /= 2;
            }

            int tmp2 = i;
            while (tmp2 % 5 == 0)
            {
                cnt5--;
                tmp2 /= 5;
            }
            int tmp52 = tmp2;
            while (tmp2 % 2 == 0)
            {
                cnt2--;
                tmp2 /= 2;
            }
            cnm5[i] = (cnm5[i - 1] * (tmp51)*inv(tmp52, 5)) % 5;
            if (cnt2 > 0)
            {
                if (cnt5 > 0)
                {
                    cnm10[i] = 0;
                }
                else
                {
                    cnm10[i] = table[{0, cnm5[i]}];
                }
            }
            else
            {
                if (cnt5 > 0)
                {
                    cnm10[i] = 5;
                }
                else
                {
                    cnm10[i] = table[{1, cnm5[i]}];
                }
            }
        }
    }

    bool hasSameDigits(string s)
    {
        int n = s.size();
        preprocess(n - 2);
        int cur = 0;
        for (int i = 0; i < n; i++)
        {
            if (i < n - 1)
            {
                cur += cnm10[i] * (s[i] - '0');
            } // cout<<cnm10[i]<<endl;}
            if (i)
                cur -= cnm10[i - 1] * (s[i] - '0');

            cur %= 10;
        }
        return cur == 0;
    }
};