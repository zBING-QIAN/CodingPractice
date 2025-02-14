#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        vector<vector<int>> link(n,vector<int>());
        vector<vector<int>> weight(n,vector<int>());
        vector<int> val(edges.size(),0);

        for(int i=0;i<edges.size();i++){
            val[i]=edges[i][2]<0;
            if(edges[i][2]<0)edges[i][2]=1;
            link[edges[i][1]].push_back(edges[i][0]);
            weight[edges[i][0]].push_back(i);
            link[edges[i][0]].push_back(edges[i][1]);
            weight[edges[i][1]].push_back(i);
        }
        vector<int> rec(n,-1);
        set<pair<int,int>> pq;pq.insert({0,source});
        rec[source]=0;
        while(pq.size()){
            int dis=pq.begin()->first,cur= pq.begin()->second;
            for(int i=0;i<link[cur].size();i++){
                int to = link[cur][i];
                int dis_to = dis+edges[weight[cur][i]][2];
                
                if(rec[to]<0||dis_to<rec[to]){
                    if(dis_to<rec[to])pq.erase({rec[to],to});
                    pq.insert({dis_to,to});
                    rec[to] =dis_to;
                }
                
            }
            pq.erase(pq.begin());
        } 
        vector<vector<int>> empty;
        if(rec[destination]>target)return empty;
        else if (rec[destination] == target)return edges;

        vector<int> rrec(n,-1);
        set<pair<int,int>> rpq;rpq.insert({0,destination});
        rrec[destination]=0;  
        while(rpq.size()){
            int dis=rpq.begin()->first,cur= rpq.begin()->second;
            for(int i=0;i<link[cur].size();i++){
                int to = link[cur][i];
                int total_dis = dis+rec[to]+edges[weight[cur][i]][2];
                if(total_dis<target){
                    if(val[weight[cur][i]]){
                        edges[weight[cur][i]][2] += target-total_dis;
                    }else {
                        int dis_to = dis+edges[weight[cur][i]][2];
                        if(rrec[to]<0||dis_to<rrec[to]){
                            if(dis_to<rrec[to])rpq.erase({rrec[to],to});
                            rpq.insert({dis_to,to});
                            rrec[to] =dis_to;
                        }
                    }
                }
                
                
            }
            rpq.erase(rpq.begin());

        }
        cout<<rrec[source]<<endl;
        if(rrec[source]!=-1)return empty;
        else return edges;
    }
};