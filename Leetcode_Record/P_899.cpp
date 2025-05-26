#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string orderlyQueue(string s, int k)
    {
        if (k > 1)
            sort(s.begin(), s.end());
        else
        {
            int i = 0, j = 1, n = s.size();
            while (j < n)
            {
                int k = 0;
                while (k < n && s[(i + k) % n] == s[(j + k) % n])
                {
                    k++;
                }
                if (s[(i + k) % n] > s[(j + k) % n])
                {
                    i = j;
                    if (j - i > k)
                        j += k;
                    else
                        j += j - i;
                }
                else
                    j++;
            }
            return s.substr(i) + s.substr(0, i);
        }

        return s;
    }
};