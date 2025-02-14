#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n=heightMap.size(),m=heightMap[0].size();
        map<int,vector<array<int,2>>> table;
        set<array<int,2>> boundary;
        
        vector<vector<int>>walls(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            boundary.insert({i,m-1});
            boundary.insert({i,0});
        }
        for(int i=0;i<m;i++){
            boundary.insert({0,i});
            boundary.insert({n-1,i});
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(table.find(heightMap[i][j]) == table.end())table[heightMap[i][j]]=vector<array<int,2>>();
                table[heightMap[i][j]].push_back({i,j});
            }
        }
        int ans = 0;
        int air =n*m;
        int epoch = 0;
        for(auto iter=table.rbegin();iter!=table.rend();iter++){
            for(auto &p:iter->second){
                
                if(walls[p[0]][p[1]]!=epoch){
                    ans-=iter->first;
                }else air-=1;
                walls[p[0]][p[1]] = -1;
                boundary.erase({p[0],p[1]});
            }
            epoch++;
            vector<array<int,2>> que;
            for(auto b:boundary){que.push_back(b);walls[b[0]][b[1]] = epoch;}
            for(int flag = 0 ;flag<que.size();flag++){
                auto [x,y] = que[flag];
                
                for(int i=-1;i<2;i++){
                    if(i==0)continue;
                    if(x+i<n&&x+i>=0&&walls[x+i][y]==epoch-1){
                        walls[x+i][y]=epoch;
                        que.push_back({x+i,y});
                    }
                    if(y+i<m&&y+i>=0&&walls[x][y+i]==epoch-1){
                        walls[x][y+i]=epoch;
                        que.push_back({x,y+i});
                    }
                }
            }
            long long area = air-que.size();
            air = que.size();
            //run bfs
            //calc area
            if(area>0)ans+=area*iter->first;
            // cout<<iter->first<<" "<<area<<" "<<air<<endl;
        }
        return ans;
    }
};