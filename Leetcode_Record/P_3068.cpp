#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<long long> dp[2];for(int i=0;i<2;i++)dp[i].resize(n,0);
        vector<vector<int>> edge(n,vector<int>());
        for(auto &e:edges){edge[e[0]].push_back(e[1]);edge[e[1]].push_back(e[0]);}
        vector<int> que,rec(n,0),pre(n,-1);
        for(int i=0;i<n;i++){
            if(edge[i].size()==1){que.push_back(i);rec[i]=1;pre[i]=-1;dp[0][i] = 0;dp[1][i] = 0;}
        }
        int flag= 0;
        while(flag<que.size()){
            int cur = que[flag];
            long long sum=0,min_dif=1e16;
            int fcnt=0;

            for(auto &e:edge[cur]){
                if(pre[e] == cur){ 
                    long long f0 = dp[1][e]+nums[e],f1=dp[0][e]+(nums[e]^k),nf0 = dp[0][e]+nums[e],nf1=dp[1][e]+(nums[e]^k);
                    long long fmax = max(f0,f1),nfmax= max(nf0,nf1);
                    if(fmax>nfmax){
                        sum+=fmax;
                        min_dif = min(fmax-nfmax,min_dif);
                        fcnt++;
                    }else{
                        sum+=nfmax;
                        min_dif = min(nfmax-fmax,min_dif);
                    }
                }else{
                    pre[cur] = e;
                    rec[e]++;
                    if(rec[e]==edge[e].size()-1)que.push_back(e);
                }
            }
            if(fcnt&1){
                dp[1][cur] = sum;dp[0][cur] = sum-min_dif;
            }else{
                dp[0][cur] = sum;dp[1][cur] = sum-min_dif;
            }
            flag++;
        }
        int last = que.back();
        return max(dp[0][last]+nums[last],dp[1][last]+(nums[last]^k));
    }
};