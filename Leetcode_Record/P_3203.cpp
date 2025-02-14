#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int DiaOfTree(vector<vector<int>> &edges){
        vector<vector<int>> t(edges.size()+1);
        for(auto &e:edges){
            t[e[0]].push_back(e[1]);
            t[e[1]].push_back(e[0]);
        }
        vector<int> que,nxt_que,in_cnt(t.size(),0),rec(t.size(),0);
        
        for(int i=0;i<t.size();i++){
            if(t[i].size()==1){
                que.push_back(i);
            }
        }
        int center = 0;
        while(que.size()){
            int idx = 0;
            while(idx<que.size()){
                center = que[idx];
                in_cnt[center]++;
                for(auto to :t[center]){
                    if(in_cnt[to] != t[to].size()&&rec[to]<rec[center]+1){
                        rec[to] = rec[center]+1;
                    }    
                    in_cnt[to]++;
                    if(in_cnt[to] == t[to].size()-1)nxt_que.push_back(to);
                    
                }

                idx++;
            }
            que= nxt_que;
            nxt_que.clear();
        }
        int l0=-1,l1=-1;
        for(auto to : t[center]){
            if(rec[to]>l0){
                if(rec[to]>l1){l0=l1;l1=rec[to];}
                else l0 = rec[to];
            }
        }
        return l0+l1+2;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int d1 = DiaOfTree(edges1);
        int d2 = DiaOfTree(edges2);
        if(d1<d2)swap(d1,d2);
        return (d1+1)/2+max((d2+1)/2+1,d1/2);
    }
};