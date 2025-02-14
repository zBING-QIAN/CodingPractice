#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        vector<int> qx,qy,qx_0,qy_0,qx_1,qy_1;
        qx.push_back(0);qy.push_back(0);
        bool is_block=grid[0][0];
        int d = 0;
        while(visited[grid.size()-1][grid[0].size()-1]!=2){
            d+=is_block;
            int flag =0;
            while(flag<qx.size()){
                int x = qx[flag],y=qy[flag];
                visited[x][y]=2;
                if(x<grid.size()-1&&visited[x+1][y]==0){
                    if(grid[x+1][y]==0){
                        qx_0.push_back(x+1);qy_0.push_back(y);visited[x+1][y]=1;
                    }else{
                        qx_1.push_back(x+1);qy_1.push_back(y);visited[x+1][y]=1;
                    }
                }
                if(x&&visited[x-1][y]==0){
                    if(grid[x-1][y]==0){
                        qx_0.push_back(x-1);qy_0.push_back(y);visited[x-1][y]=1;
                    }else{
                        qx_1.push_back(x-1);qy_1.push_back(y);visited[x-1][y]=1;
                    }
                }
                if(y<grid[0].size()-1&&visited[x][y+1]==0){
                    if(grid[x][y+1]==0){
                        qx_0.push_back(x);qy_0.push_back(y+1);visited[x][y+1]=1;
                    }else{
                        qx_1.push_back(x);qy_1.push_back(y+1);visited[x][y+1]=1;
                    }
                }
                if(y&&visited[x][y-1]==0){
                    if(grid[x][y-1]==0){
                        qx_0.push_back(x);qy_0.push_back(y-1);visited[x][y-1]=1;
                    }else{
                        qx_1.push_back(x);qy_1.push_back(y-1);visited[x][y-1]=1;
                    }
                }
                flag++;
            }
            if(qx_0.size()>0){
                qx=qx_0;qy=qy_0;
                qx_0.clear();qy_0.clear();
                is_block = 0;
            }else{
                qx=qx_1;qy=qy_1;
                qx_1.clear();qy_1.clear();
                is_block = 1;
            }
            
        }
        return d;
        
    }
};