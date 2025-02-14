#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ans = 0,target=0;
    map<pair<pair<int,int>,bool>,int> dp;
    int dfs(int k,int t,bool down){
        if(k>target+5||t<0)return 0;
        if(dp.find({{k,t},down})!=dp.end())return dp[{{k,t},down}];
        int sum = 0;
        if (down==0){
            sum+=dfs(k+1,t,1);
        }else if (t>0){
            long long to = k-(1<<(t-1));
            if(to>=0){
                sum +=dfs(to,t-1,0);
                sum +=dfs(to,t-1,1);
            }
        }
        
        dp[{{k,t},down}] = sum;
        
        return sum;
    }
    int waysToReachStair(int k) {
        target=k;
        dp[{{1,0},1}] = 1;
        for(int i=0;i<31;i++){
            ans+=dfs(k,i,1);
            ans+=dfs(k,i,0);
        }
        return ans;
    }
};