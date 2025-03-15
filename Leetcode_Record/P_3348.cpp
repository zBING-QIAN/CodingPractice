#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> smallest(int pow2, int pow3, int pow5, int pow7)
    {
        vector<int> cnt(11, 0);
        cnt[7] = pow7;
        cnt[5] = pow5;
        cnt[9] = pow3 / 2;
        cnt[8] = pow2 / 3;
        if (pow3 & 1)
        {
            if ((pow2 % 3) > 0)
            {
                cnt[6] = 1;
                if ((pow2 % 3) == 2)
                    cnt[2] = 1;
            }
            else
                cnt[3] = 1;
        }
        else
        {
            if ((pow2 % 3) == 1)
                cnt[2] = 1;
            if ((pow2 % 3) == 2)
                cnt[4] = 1;
        }
        return cnt;
    }

    int smallest_len(int pow2, int pow3, int pow5, int pow7)
    {
        vector<int> cnt(11, 0);
        cnt[7] = pow7;
        cnt[5] = pow5;
        cnt[9] = pow3 / 2;
        cnt[8] = pow2 / 3;
        if (pow3 & 1)
        {
            if ((pow2 % 3) > 0)
            {
                cnt[6] = 1;
                if ((pow2 % 3) == 2)
                    cnt[2] = 1;
            }
            else
                cnt[3] = 1;
        }
        else
        {
            if ((pow2 % 3) == 1)
                cnt[2] = 1;
            if ((pow2 % 3) == 2)
                cnt[4] = 1;
        }
        int len = 0;
        for (int i = 1; i < 11; i++)
            len += cnt[i];
        return len;
    }
    string smallestNumber(string num, long long t)
    {

        vector<int> primes = {2, 3, 5, 7}, pcnt = {0, 0, 0, 0};
        while (t % 2 == 0)
        {
            pcnt[0]++;
            t /= 2;
        }
        while (t % 3 == 0)
        {
            pcnt[1]++;
            t /= 3;
        }
        while (t % 5 == 0)
        {
            pcnt[2]++;
            t /= 5;
        }
        while (t % 7 == 0)
        {
            pcnt[3]++;
            t /= 7;
        }
        if (t > 1)
            return "-1";
        vector<int> rec;
        int len = 0, i = 0;
        for (; i < num.size(); i++)
        {
            len = smallest_len(max(0, pcnt[0]), max(0, pcnt[1]), max(0, pcnt[2]), max(0, pcnt[3]));
            if (num[i] == '0' || len > num.size() - i)
            {
                if (num[i] == '0')
                {
                    i++;
                    rec.push_back(0);
                }
                break;
            }
            int cur = num[i] - '0';
            for (int j = 0; j < 4; j++)
            {
                int p = primes[j];
                while ((cur % p) == 0)
                {
                    cur /= p;
                    pcnt[j]--;
                }
            }
            rec.push_back(num[i] - '0');
        }
        bool get_small = 0, leading_one = 0;
        for (int k = 0; k < 4; k++)
        {
            if (pcnt[k] > 0)
            {
                get_small = 1;
            }
        }
        if (get_small)
            while (i > 0)
            {
                i--;
                rec.pop_back();
                int g = num[i] - '0';
                if (g > 0)
                    for (int j = 0; j < 4; j++)
                    {
                        int p = primes[j];
                        while ((g % p) == 0)
                        {
                            g /= p;
                            pcnt[j]++;
                        }
                    }

                g = num[i] - '0';
                int head = 0;

                for (int k = g + 1; k < 10; k++)
                {

                    int cur = k;
                    vector<int> pcnt_tmp = pcnt;
                    for (int j = 0; j < 4; j++)
                    {
                        int p = primes[j];
                        while ((cur % p) == 0)
                        {
                            cur /= p;
                            pcnt_tmp[j]--;
                        }
                    }
                    int len_tmp = smallest_len(max(0, pcnt_tmp[0]), max(0, pcnt_tmp[1]), max(0, pcnt_tmp[2]), max(0, pcnt_tmp[3]));
                    if (rec.size() + len_tmp < num.size())
                    {
                        pcnt = pcnt_tmp;
                        head = k;
                        break;
                    }
                }
                if (head)
                {
                    rec.push_back(head);
                    break;
                }
                if (i == 0)
                    leading_one = 1;
            }
        vector<int> scnt = smallest(max(0, pcnt[0]), max(0, pcnt[1]), max(0, pcnt[2]), max(0, pcnt[3]));
        string prev = "";
        for (auto c : rec)
        {
            if (c == 0)
                c = 1;
            prev += char('0' + c);
        }
        string small = "";
        for (int i = 1; i < 10; i++)
        {
            for (int j = 0; j < scnt[i]; j++)
                small += char('0' + i);
        }
        string padding = "";
        if (prev.size() + small.size() < num.size())
        {
            while (padding.size() + prev.size() + small.size() < num.size())
            {
                padding += "1";
            }
        }
        if (leading_one)
            prev = "1";
        return prev + padding + small;
    }
};