#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sx,sy,tx,ty,total_step,h,w;
    int dfs(int x,int y,int steps,vector<vector<int>> &grid){
        // assert(x>=0&&x<w&&y>=0&&y<h);
        if(steps==total_step){return grid[y][x] == 2;}
        int out = 0;
        int tmp = grid[y][x];
        grid[y][x] = -1;
        
        if(x!=0&&grid[y][x-1]!=-1){
                out += dfs(x-1,y,steps+1,grid);
                // if(x==sx&&y ==sy)cout<<"after x-1 "<<out<<endl;
            }
        if(x!=w-1&&grid[y][x+1]!=-1){
                out += dfs(x+1,y,steps+1,grid);
                // if(x==sx&&y ==sy)cout<<"after x+1 "<<out<<endl;
            }
        if(y!=0&&grid[y-1][x]!=-1){
                out += dfs(x,y-1,steps+1,grid);
                // if(x==sx&&y ==sy)cout<<"after y-1 "<<out<<endl;
            }
        if(y!=h-1&&grid[y+1][x]!=-1){
                out += dfs(x,y+1,steps+1,grid);
                // if(x==sx&&y ==sy)cout<<"after y+1 "<<out<<endl;
            }
        
        
        grid[y][x] = tmp;
        return out;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        h=grid.size(),w = grid[0].size();
        total_step =1;
        for(int i=0;i<h;i++)for(int j=0;j<w;j++){
            if(grid[i][j] == 1){
                sx = j,sy=i;
            }
            else if(grid[i][j] == 2)tx = j,ty = i;
            else if(grid[i][j] == 0)total_step++;
        }
        grid[sy][sx]=-1;
        return dfs(sx,sy,0,grid);
    }
};