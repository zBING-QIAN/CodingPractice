#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int test_one_node(int x,int y,vector<vector<int>> &grid,int total){
        int sx=-1,sy=-1,n=grid.size(),m=grid[0].size();
        if(x>0&&grid[x-1][y]){
            sx=x-1;sy =y;
        }else if(x<grid.size()-1&&grid[x+1][y]){
            sx=x+1;sy =y;
        }else if(y>0&&grid[x][y-1]){
            sx=x;sy =y-1;
        }else if(y<grid[0].size()-1&&grid[x][y+1]){
            sx=x;sy =y+1;
        }
        if(sx==-1&&sy==-1){return 0;}
        vector<vector<int>> rec=grid;
        vector<int> qx,qy;qx.push_back(sx);qy.push_back(sy);rec[sx][sy] = 0;rec[x][y] =0;
        int flag = 0;
        while(flag<qx.size()){
            int cx=qx[flag],cy=qy[flag];
            if(cx>0&&rec[cx-1][cy]){
                qx.push_back(cx-1);qy.push_back(cy);
                rec[cx-1][cy]=0;
            }
            if(cx<grid.size()-1&&rec[cx+1][cy]){
                qx.push_back(cx+1);qy.push_back(cy);
                rec[cx+1][cy]=0;
            }
            if(cy>0&&rec[cx][cy-1]){
                qx.push_back(cx);qy.push_back(cy-1);
                rec[cx][cy-1]=0;
            }
            if(cy<grid[0].size()-1&&rec[cx][cy+1]){
                qx.push_back(cx);qy.push_back(cy+1);
                rec[cx][cy+1]=0;
            }   
            flag++;
        }
        
        if(qx.size()==total-1)return 2;
        if(x>0&&rec[x-1][y]){
            return 1;
        }else if(x<grid.size()-1&&rec[x+1][y]){
           return 1;
        }else if(y>0&&rec[x][y-1]){
           return 1;
        }else if(y<grid[0].size()-1&&rec[x][y+1]){
           return 1;
        }
        return 0;
    }
    int minDays(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),total = 0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                total+=grid[i][j];
                
        if(total==0)return 0;
        else if(total==1)return 1;
        int ans =2;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    int score = test_one_node(i,j,grid,total);
                    if(ans>score)ans = score;
                    if(ans==0)return 0;
                }
            }
        }
        return ans;
    }
};
