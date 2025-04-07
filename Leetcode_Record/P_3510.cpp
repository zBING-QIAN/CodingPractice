#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minimumPairRemoval(vector<int> &nums)
    {
        set<array<long long, 2>> pq;
        int n = nums.size();
        vector<long long> num(n, 0);
        for (int i = 0; i < n; i++)
            num[i] = nums[i];
        vector<int> link_pre(n, -1), link_back(n, n);
        int rev_cnt = 0;
        for (int i = 0; i < n - 1; i++)
        {
            link_pre[i + 1] = i;
            link_back[i] = i + 1;
            pq.insert({num[i] + num[i + 1], i});
            if (num[i] > num[i + 1])
                rev_cnt++;
        }
        int ans = 0;
        while (rev_cnt)
        {
            auto [sum, pos] = *pq.begin();
            pq.erase({sum, pos});
            // if(sum != num[pos]+num[link_back[pos]]){
            //     cout<<num[pos]<<" "<<num[link_back[pos]]<<" "<<pos<<" "<<link_back[pos]<<" "<<sum<<endl;
            // }
            // assert(sum == num[pos]+num[link_back[pos]]);
            if (num[pos] > num[link_back[pos]])
                rev_cnt--;
            int pre_pos = link_pre[pos], back_pos = (link_back[pos] == n) ? n : link_back[link_back[pos]];
            if (pre_pos >= 0)
            {

                // cout<<sum<<" "<<pos<<" "<<link_back[pos]<<" "<<back_pos<<" "<<rev_cnt<<endl;
                if (num[pre_pos] > num[pos] && num[pre_pos] <= sum)
                    rev_cnt--;
                else if (num[pre_pos] <= num[pos] && num[pre_pos] > sum)
                    rev_cnt++;
            }

            if (back_pos < n)
            {
                // cout<<sum<<" "<<pos<<" "<<link_back[pos]<<" "<<back_pos<<" "<<rev_cnt<<endl;
                if (num[link_back[pos]] <= num[back_pos] && num[back_pos] < sum)
                    rev_cnt++;
                else if (num[link_back[pos]] > num[back_pos] && num[back_pos] >= sum)
                    rev_cnt--;
                // cout<<sum<<" "<<pos<<" "<<rev_cnt<<endl;
            }
            if (pre_pos >= 0)
            {
                pq.erase({num[pos] + num[pre_pos], pre_pos});
                pq.insert({num[pre_pos] + sum, pre_pos});
            }
            if (back_pos < n)
            {
                pq.erase({num[link_back[pos]] + num[back_pos], link_back[pos]});
                pq.insert({num[back_pos] + sum, pos});
                link_pre[back_pos] = pos;
            }
            link_back[pos] = back_pos;
            num[pos] = sum;
            ans++;
        }
        return ans;
    }
};