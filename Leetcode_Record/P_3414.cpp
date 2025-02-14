#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        map<int,array<long long,5>> dp[5];dp[0][0] = {0,-1,-1,-1,-1};
        vector<int> idx(n,0);for(int i=0;i<n;i++)idx[i]=i;
        sort(idx.begin(),idx.end(),[&](auto &a,auto &b){return (intervals[a][0]<intervals[b][0]);});
        int cnt= 0 ;
        for(auto i:idx){
            // cout<<"cnt = "<<cnt<<endl;cnt++;
            int start = intervals[i][0], end = intervals[i][1],w = intervals[i][2];
            
            for(int t = 4;t;t--){
                auto iter = dp[t].lower_bound(end);
                auto nxt_iter = dp[t-1].lower_bound(start);
                if(nxt_iter!=dp[t-1].begin()){
                    nxt_iter--;
                    array<long long,5> nxt_best = nxt_iter->second;
                    nxt_best[0]+=w;nxt_best[t] = n-i;
                    for(int j = t;j>1;j--){
                        if(nxt_best[j]>nxt_best[j-1])swap(nxt_best[j],nxt_best[j-1]);
                        else break;
                    }
                    if(iter!=dp[t].begin()){
                        iter--;
                        if(iter->second>=nxt_best)continue;
                        iter++;
                    }
                    vector<int> rmlist;
                    while(iter!=dp[t].end()){
                        if(iter->second<nxt_best)rmlist.push_back(iter->first);
                        iter++;
                    }
                    
                    // cout<<i<<", "<<t<<", "<<start<<" "<<end<<endl;
                    // for(int y=0;y<5;y++)cout<<nxt_best[y]<<" ";cout<<endl;
                    while(rmlist.size()){
                        // cout<<"rm "<<rmlist.back()<<endl;
                        dp[t].erase(rmlist.back());rmlist.pop_back();
                    }
                    if(dp[t].find(end)==dp[t].end()){
                        dp[t][end] = nxt_best;
                    }

                }
            }
        }
        auto ans = dp[1].rbegin()->second;
        for(int i=2;i<=4;i++){
            if(dp[i].size()>0){
                ans = max(ans,dp[i].rbegin()->second);
            }
        }
        vector<int> out;
        for(int i =1 ;i<=4;i++){
            if(ans[i]>=0)out.push_back(n-ans[i]);
        }
        return out;

    }
};