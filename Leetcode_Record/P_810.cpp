#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool xorGame(vector<int>& nums) {
        if(nums.size()&1){
            int tmp = 0;
            for(auto &n :nums){
                tmp ^= n;
            }
            return tmp==0;
        }else return true;
    }
};