#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        vector<vector<int>> dis(n,vector<int>(n,maxDistance+1));
        for(auto &r : roads){
            int u=r[0],v=r[1],w=r[2];
            dis[u][v] = min(w,dis[u][v]);
            dis[v][u] = min(w,dis[v][u]);
        }
        for(int i=0;i<n;i++)dis[i][i] = 0;
        int max_state = 1<<n,ans=0;
        for(int s=0;s<max_state;s++){
            vector<int> active;
            for(int b = 0;(1<<b)<max_state;b++){if(s&(1<<b))active.push_back(b);}
            // cout<<"state "<<s<<endl;
            // for(auto a:active)cout<<a<<" ";cout<<endl;
            vector<vector<int>> graph(active.size(),vector<int>(active.size(),maxDistance+1));
            for(int i=0;i<active.size();i++){
                for(int j=0;j<active.size();j++){
                    graph[i][j] = dis[active[i]][active[j]];
                    // cout<<graph[i][j]<<" ";
                }//cout<<endl;
            }//cout<<endl;
            //asp
            for(int p=0;p<active.size();p++){
                for(int i=0;i<active.size();i++){
                    for(int j=0;j<active.size();j++){
                        graph[i][j] = min(graph[i][j],graph[i][p]+graph[p][j]);
                    }
                }
            }
            bool good = 1;
            for(int i=0;i<active.size();i++){
                for(int j=i;j<active.size();j++){
                    if(graph[i][j]>maxDistance){good=0;break;}
                }
            }
            ans+=good;
        }
        return ans;
    }
};