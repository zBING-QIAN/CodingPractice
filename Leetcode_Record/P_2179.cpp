#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long goodTriplets(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            nums[nums2[i]] = i;
        }
        for (int i = 0; i < n; i++)
        {
            nums2[i] = nums[nums1[i]];
        }
        for (int i = 0; i < n; i++)
            nums2[i]++;
        vector<long long> first(n + 1, 0), second(n + 1, 0);
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            // cout<<i<<" "<<nums2[i]<<endl;
            long long cnt = 0;
            // cout<<"cnt\n";
            for (int tmp = nums2[i]; tmp; tmp -= tmp & (-tmp))
            { // cout<<tmp<<" "<<cnt<<endl;
                cnt += first[tmp];
            }
            cout << cnt << endl;
            // cout<<"ans\n";
            for (int tmp = nums2[i]; tmp; tmp -= tmp & (-tmp))
            { // cout<<tmp<<" "<<ans<<endl;
                ans += second[tmp];
            }
            // cout<<"second\n";
            for (int tmp = nums2[i]; tmp <= n; tmp += tmp & (-tmp))
            { // cout<<tmp<<" "<<second[tmp]<<endl;
                second[tmp] += cnt;
            }
            for (int tmp = nums2[i]; tmp <= n; tmp += tmp & (-tmp))
            {
                first[tmp]++;
            }
        }
        return ans;
    }
};