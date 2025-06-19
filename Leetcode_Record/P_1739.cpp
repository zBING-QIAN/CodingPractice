#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumBoxes(int n)
    {
        long long sum = 0;
        for (int i = 0; i <= n; i++)
        {
            long long tmp = ((i + 1) * i) / 2;
            if (sum + tmp > n)
            {
                int ans = ((i - 1) * i) / 2;
                n -= sum;
                for (int j = 1; n > 0; j++)
                {
                    n -= j;
                    ans += 1;
                }
                return ans;
            }
            sum += tmp;
        }
        return 1;
    }
};