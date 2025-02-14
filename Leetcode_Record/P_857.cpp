#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = wage.size();
        vector<double> ratio(n);
        vector<pair<int,int>> qw(n);
        for(int i=0;i<n;i++){qw[i] = {quality[i],wage[i]};ratio[i] = double(wage[i])/double(quality[i]);}
        sort(qw.begin(),qw.end());
        sort(ratio.begin(),ratio.end());
        int total_cnt = 0;
        double ans = 0;
        set<pair<double,int>> table;
        for(int i=0;i<k;i++){
            total_cnt += qw[i].first;
            table.insert({double(qw[i].second)/double(qw[i].first),i});
        }
        ans = ratio[n-1]*total_cnt;
        for(int i=n-2,j=k;i>=0;i--){
            while(table.size()&&table.rbegin()->first>ratio[i]){
                total_cnt-=qw[table.rbegin()->second].first;
                // cout<<"erase "<<table.rbegin()->first<<" "<<table.rbegin()->second<<endl;
                table.erase(*table.rbegin());
            }
            while(table.size()<k&&j<n){
                double nr = double(qw[j].second)/double(qw[j].first);
                if(nr<=ratio[i]){table.insert({nr,j});total_cnt+=qw[j].first;}
                j++;
            }
            if(table.size()==k){
                ans = min(ans,total_cnt*ratio[i]);
            }else break;
        }
        return ans;


    }
};