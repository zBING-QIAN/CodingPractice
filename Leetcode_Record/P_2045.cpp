#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> edge(n+1,vector<int>());
        for(auto e:edges){
            edge[e[0]].push_back(e[1]);
            edge[e[1]].push_back(e[0]);
        }
        vector<int> rec(n+1,1e9);
        vector<int> q;q.push_back(1);rec[1] = 0;
        int flag =0,shortest_step = 1e9;
        while(flag<q.size()){
            int cur = q[flag];
            for(auto e:edge[cur]){
                if(rec[e]==1e9){
                    q.push_back(e);
                    rec[e] = rec[cur]+1;   
                }
            }
            flag++;
        }
        flag=0;
        vector<int> rec2=rec;
        while(flag<q.size()){
            int cur = q[flag];
            for(auto e:edge[cur]){
                if((rec[cur]==rec[e]||rec2[cur]==rec[e])&&rec2[e]==rec[e]){
                    q.push_back(e);
                    rec2[e] = rec[e]+1;//   cout<<"add one pos "<<cur<<" "<<e<<" "<<rec[e]<<" "<<rec2[e]<<endl;
                }
            }
            flag++;
        }
        
        
        if(rec2[n] == rec[n]){ 
            rec2[n]+=2;
        }
        
        int per =0;
        int ans = 0;
        for(int i=0;i<rec2[n];i++){
            per = ans/change;
            ans = (per&1)?change*(per+1)+time:ans+time;
        }
       
        
        return ans;
    }
};