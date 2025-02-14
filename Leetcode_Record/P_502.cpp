#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<int> idx(n,0); for(int i=0;i<n;i++)idx[i]=i;
        sort(idx.begin(),idx.end(),[&](auto a,auto b){return capital[a]<capital[b];});
        int base = w,cur=0;
        int cur_times = 0;
        set<pair<int,int>> table;
        for(int i=0;i<n;i++){
            if(base<capital[idx[i]]){
                if(base+cur<capital[idx[i]])return base+cur;
                while(table.size()>0&&base<capital[idx[i]]){
                    cur_times++;
                    int tmp = prev(table.end())->first;
                    base+=tmp;cur-=tmp;
                    table.erase(prev(table.end()));
                }
                if(cur_times==k)break;
            }
            if(table.size()+cur_times==k&&profits[idx[i]]>table.begin()->first){cur-= table.begin()->first;table.erase(table.begin());}
            if(table.size()+cur_times<k){
                table.insert({profits[idx[i]],i});
                cur+=profits[idx[i]];
            }
        }
        return cur+base;
    }
};