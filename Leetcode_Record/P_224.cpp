#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int calculate(string s)
    {
        vector<int> nums;
        vector<char> ops;
        int state = 0;
        for (auto c : s)
        {
            if (c == ' ')
                continue;
            if (c == '(')
            {
                ops.push_back(c);
                state = 0;
            }
            else if (c == ')')
            {
                while (ops.size() && ops.back() != '(')
                {
                    int n0 = nums.back();
                    nums.pop_back();
                    if (ops.back() == '+')
                    {
                        nums.back() += n0;
                    }
                    else
                        nums.back() -= n0;
                    ops.pop_back();
                }
                ops.pop_back();
                state = 2;
            }
            else if (c == '+')
            {
                while (ops.size() && ops.back() != '(')
                {
                    int n0 = nums.back();
                    nums.pop_back();
                    if (ops.back() == '+')
                    {
                        nums.back() += n0;
                    }
                    else
                        nums.back() -= n0;
                    ops.pop_back();
                }
                state = 2;
                ops.push_back(c);
            }
            else if (c == '-')
            {
                if (state == 0)
                {
                    nums.push_back(0);
                }
                else
                {
                    while (ops.size() && ops.back() != '(')
                    {
                        int n0 = nums.back();
                        nums.pop_back();
                        if (ops.back() == '+')
                        {
                            nums.back() += n0;
                        }
                        else
                            nums.back() -= n0;
                        ops.pop_back();
                    }
                }
                state = 2;
                ops.push_back(c);
            }
            else
            {
                if (state == 1)
                {
                    nums.back() *= 10;
                    nums.back() += c - '0';
                }
                else
                    nums.push_back(c - '0');
                state = 1;
            }
        }
        while (ops.size())
        {
            int n0 = nums.back();
            nums.pop_back();
            if (ops.back() == '+')
            {
                nums.back() += n0;
            }
            else
                nums.back() -= n0;
            ops.pop_back();
        }
        return nums.back();
    }
};