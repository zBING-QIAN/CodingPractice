#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int ans = 0,n=grid.size(),m=grid[0].size();
        vector<pair<int,int>> que;que.push_back({0,0});
        vector<vector<int>> rec(n,vector<int>(m,-1));
        rec[0][0]=0;
        while(rec.back().back()==-1){
            int flag = 0;
            while(flag<que.size()){
                auto [x,y] = que[flag];
                if(grid[x][y]==1&&y+1<m&&rec[x][y+1]==-1){
                    rec[x][y+1] = rec[x][y];
                    que.push_back({x,y+1});
                }
                if(grid[x][y]==2&&y&&rec[x][y-1]==-1){
                    rec[x][y-1] = rec[x][y];
                    que.push_back({x,y-1});
                }
                if(grid[x][y]==3&&x+1<n&&rec[x+1][y]==-1){
                    rec[x+1][y] = rec[x][y];
                    que.push_back({x+1,y});
                }
                if(grid[x][y]==4&&x&&rec[x-1][y]==-1){
                    rec[x-1][y] = rec[x][y];
                    que.push_back({x-1,y});
                }
                flag++;
            }
            vector<pair<int,int>> nxt_que;
            for(auto &p:que){
                for(int i=-1;i<2;i++){
                    if(i==0)continue;
                    if(p.first+i>=0&&p.first+i<n&&rec[p.first+i][p.second]==-1){
                        nxt_que.push_back({p.first+i,p.second});
                        rec[p.first+i][p.second] = rec[p.first][p.second]+1;
                    }
                    
                    if(p.second+i>=0&&p.second+i<m&&rec[p.first][p.second+i]==-1){
                        nxt_que.push_back({p.first,p.second+i});
                        rec[p.first][p.second+i] = rec[p.first][p.second]+1;
                    }
                }
                // cout<<p.first<<" "<<p.second<<" "<<rec[p.first][p.second]<<endl;
            }
            que = nxt_que;
        }
        return rec.back().back();
    }
};