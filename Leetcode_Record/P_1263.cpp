#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<vector<vector<int>>>> dp;
    int n,m,tx,ty,ans = INT_MAX;
    vector<array<int,4>> dfs(int sx,int sy,int bx,int by){
        queue<array<int,2>> que;
        vector<array<int,4>> nque;
        que.push({sx,sy});
        int cur = dp[sx][sy][bx][by];
        while(que.size()){
            auto [x,y] = que.front();
            que.pop();
            for(int i=-1;i<2;i++){
                if(i==0)continue;
                if(x+i<n&&x+i>=0){
                    if(dp[x+i][y][bx][by]==-1){
                        dp[x+i][y][bx][by] = cur;
                        que.push({x+i,y});
                    }
                    else if(x+i==bx&&y==by&&bx+i>=0&&bx+i<n&&dp[x+i][y][bx+i][by]==-1){
                        dp[x+i][y][bx+i][by] = cur+1;
                        nque.push_back({x+i,y,bx+i,by});
                    }
                }
                
                if(y+i<m&&y+i>=0){
                    if(dp[x][y+i][bx][by]==-1){
                        dp[x][y+i][bx][by] = cur;
                        que.push({x,y+i});
                    }
                    else if(x==bx&&y+i==by&&by+i>=0&&by+i<m&&dp[x][y+i][bx][by+i]==-1){
                        dp[x][y+i][bx][by+i] = cur+1;
                        nque.push_back({x,y+i,bx,by+i});
                    }
                }
            }
        }
        return nque;
    }
    int minPushBox(vector<vector<char>>& grid) {
        int sx,sy,bx,by;
        n =grid.size();m=grid[0].size();
        
        dp.resize(n,vector<vector<vector<int>>>(m,vector<vector<int>>(n,vector<int>(m,-1))));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i][j][i][j] = 1e9;
                if(grid[i][j] == 'S')sx=i,sy=j;
                if(grid[i][j] == 'B')bx=i,by=j;
                if(grid[i][j] == 'T')tx=i,ty=j;
                if(grid[i][j] == '#'){
                    for(int x=0;x<n;x++)for(int y=0;y<m;y++)dp[i][j][x][y] = 1e9,dp[x][y][i][j] = 1e9;
                }
            }
        }
        dp[sx][sy][bx][by]=0;
        queue<array<int,4>> que;
        que.push({sx,sy,bx,by});
        while(que.size()){
            auto [x0,y0,x1,y1] = que.front();que.pop();
            vector<array<int,4>> nxts = dfs(x0,y0,x1,y1);
            for(auto &nxt:nxts){
                if(nxt[2]==tx&&nxt[3]==ty)return dp[nxt[0]][nxt[1]][nxt[2]][nxt[3]];
                que.push(nxt);
            }

        }
        
        return -1;
    }
};