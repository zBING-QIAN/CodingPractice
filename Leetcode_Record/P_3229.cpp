#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        long long ans = 0;
        int pre_dif = 0;
        for(int i=0;i<nums.size();i++){
            int dif = nums[i]-target[i];
            if (dif>0&&pre_dif>0&&pre_dif>dif){
                pre_dif = dif;continue;
            }
            if (dif<0&&pre_dif<0&&pre_dif<dif){
                pre_dif = dif;continue;
            }
            int tmp = dif - pre_dif;
            tmp = (abs(tmp)>abs(dif))?abs(dif):abs(tmp);
            ans += tmp;


            pre_dif = dif;
        }
        return ans;
    }
};