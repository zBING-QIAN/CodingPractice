#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int sum = 0;
        vector<int> dp0(stones.size(),0);
        vector<int> dp1(stones.size(),0);
        for(auto s :stones)sum+=s;
        dp0[stones.size()-2]=sum;
        for(int i=stones.size()-3;i>=0;i--){
            sum-=stones[i+2];
            if(sum+dp1[i+1]-dp0[i+1]>dp0[i+1]-dp1[i+1]){
                dp0[i] = sum+dp1[i+1];
                dp1[i] = dp0[i+1];
            }else{
                dp0[i]=dp0[i+1];dp1[i]=dp1[i+1];
            }
        }
        return dp0[0]-dp1[0];
    }
};