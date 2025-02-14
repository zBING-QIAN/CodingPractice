#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> seq,seq_len;
    vector<int> dp;
    vector<vector<array<int,2>>> edge;
    vector<int> ans;
    vector<int> num;
    vector<int> visit;
    int pre,len,pre_len;
    void dfs(int cur,int length=0){
        visit[cur] = 0;
        seq.push_back(cur);
        seq_len.push_back(length);
        int dp_backup = dp[num[cur]],pre_backup=pre,pre_len_backup=pre_len;
        while(pre<=dp_backup){
            pre++;pre_len+=seq_len[pre];
        }
        len+=length;
        dp[num[cur]] = seq.size()-1;
        int cur_len = len-pre_len;
        
        // cout<<len<<" "<<pre_len<<" "<<cur<<" "<<num[cur]<<" "<<pre<<endl;
        if(ans[0]<cur_len||(cur_len==ans[0]&&ans[1]>seq.size()-pre)){
            ans[0] = cur_len;ans[1] = seq.size()-pre;
        }
        for(auto &to:edge[cur]){
            if(visit[to[0]]){
                dfs(to[0],to[1]);
            }
        }
        seq.pop_back();
        seq_len.pop_back();
        len-=length;
        dp[num[cur]] = dp_backup;
        pre_len=pre_len_backup;
        pre = pre_backup;
    }
    vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
        edge.resize(nums.size(),vector<array<int,2>>());
        dp.resize(5e4+5,-1);
        visit.resize(edges.size()+2,1);
        num = nums;pre= -1;len=0;pre_len = 0;
        for(auto &e:edges){
            edge[e[0]].push_back({e[1],e[2]});
            edge[e[1]].push_back({e[0],e[2]});
        }        
        ans.push_back(0);ans.push_back(1);
        dfs(0);
        return ans;
    }

};