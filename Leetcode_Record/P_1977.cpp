#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfCombinations(string num)
    {
        if (num[0] == '0')
            return 0;
        int mod = 1e9 + 7, n = num.size();
        vector<vector<long long>> dp(n, vector<long long>(n, 0));
        vector<vector<bool>> sel(n, vector<bool>(n, 0));
        for (int start = 0; start < n; start++)
        {
            if (num[start] == '0')
                continue;
            string num_suf = num.substr(start);
            int cur = -1, size = num_suf.size();
            vector<int> z(num_suf.size(), -1);
            for (int i = 1; i < size; i++)
            {
                if ((num_suf[i] > num_suf[0]) && (start + 2 * i - 1 < n))
                {
                    sel[start + i][start + 2 * i - 1] = 1;
                }
                while (cur >= 0 && num_suf[i] != num_suf[cur + 1])
                {
                    int pos = i - cur - 1;
                    if ((num_suf[i] > num_suf[cur + 1] || cur >= pos - 1) && (start + 2 * pos - 1 < n))
                    {
                        // if(start==0) cout<<start<<" "<<start+pos<<" "<<start+2*pos-1<<" "<<z[i]<<" "<<i<<" "<<pos<<endl;
                        sel[start + pos][start + 2 * pos - 1] = 1;
                    }
                    cur = z[cur];
                }
                if (num_suf[cur + 1] == num_suf[i])
                {
                    cur++;
                }
                z[i] = cur;
            }
            while (cur >= 0)
            {
                int pos = size - cur - 1;
                if ((cur >= pos - 1) && (start + 2 * pos - 1 < n))
                {
                    // if(start==0) cout<<start<<" "<<start+pos<<" "<<start+2*pos-1<<" "<<z[i]<<" "<<i<<" "<<pos<<endl;
                    sel[start + pos][start + 2 * pos - 1] = 1;
                }
                cur = z[cur];
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<sel[i][j]<<" ";
        //     }cout<<endl;
        // }
        for (int i = 0; i < n; i++)
            dp[0][i] = 1;
        for (int i = 1; i < n; i++)
        {
            if (num[i] == '0')
            {
                continue;
            }
            long long iprev = 0;
            for (int j = 0; j + i < n; j++)
            {
                // cout<<iprev<<endl;
                if (sel[i][i + j])
                {
                    if (i - j - 1 >= 0)
                    {
                        iprev += dp[i - j - 1][i - 1];
                        iprev %= mod;
                    }
                    dp[i][i + j] = iprev;
                }
                else
                {
                    dp[i][i + j] = iprev;
                    if (i - j - 1 >= 0)
                    {
                        iprev += dp[i - j - 1][i - 1];
                        iprev %= mod;
                    }
                }
            }
        }
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += dp[i][n - 1];
            ans %= mod;
        }
        return ans;
    }
};