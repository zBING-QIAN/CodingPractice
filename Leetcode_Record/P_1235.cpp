#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    map<int,int> dp;
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<int> sidx(startTime.size(),0);
        for(int i=0;i<startTime.size();i++){sidx[i]=i;}
        sort(sidx.begin(),sidx.end(),[&](auto &a,auto &b){
            return startTime[a]<startTime[b]||(startTime[a]==startTime[b]&&endTime[a]<endTime[b]);
        });
        for(int i=0;i<sidx.size();i++){
            int cur = sidx[i];
            map<int,int>::iterator iter = dp.upper_bound(startTime[cur]);
            int tmp = profit[cur];
            if(iter!=dp.begin()){
                iter--;tmp += iter->second;
            }
            if(dp.size()==0){dp[endTime[cur]] = tmp;continue;}
            map<int,int>::iterator enditer = dp.upper_bound(endTime[cur]);
            if(enditer!=dp.begin()){
                enditer--;
                if(tmp<=enditer->second)continue;
                enditer++;
            }
            iter = enditer;
            while(enditer!=dp.end()&&tmp>=enditer->second){
                enditer++;
            }
            dp.erase(iter,enditer);
            dp[endTime[cur]] = tmp;
        }
        return dp.rbegin()->second;

    }
};