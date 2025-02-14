#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int id = 1;
    int dfs(int x,int y,vector<vector<int>> &grid,vector<vector<int>> &rec){
        rec[x][y] = id;
        int out = 1;
        for(int i=-1;i<2;i++){
            if(x+i>=0&&x+i<grid.size()&&grid[x+i][y]&&rec[x+i][y]==0){
                out += dfs(x+i,y,grid,rec);   
            }
            if(y+i>=0&&y+i<grid[0].size()&&grid[x][y+i]&&rec[x][y+i]==0){
                out += dfs(x,y+i,grid,rec);   
            }
        }
        return out;
    }
    
    
    int largestIsland(vector<vector<int>>& grid) {
        vector<vector<int>> rec(grid.size(),vector<int>(grid[0].size(),0));
        map<int,int> table;
        int ans = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]&&rec[i][j]==0){
                    table[id] = dfs(i,j,grid,rec);
                    ans = max(ans,table[id]);
                    id++;
                }
            }
        }
        table[0]=0;
        for(int x=0;x<grid.size();x++){
            for(int y=0;y<grid[0].size();y++){
                if(grid[x][y]==0){
                    set<int> s;
                    for(int i=-1;i<2;i++){
                        if(x+i>=0&&x+i<grid.size()){
                            s.insert(rec[x+i][y]);   
                        }
                        if(y+i>=0&&y+i<grid[0].size()){
                            s.insert(rec[x][y+i]);      
                        }
                    }
                    int ans_tmp=1;
                    for(auto h:s){
                        ans_tmp+=table[h];
                    }
                    ans = max(ans,ans_tmp);
                }
            }
        }
        return ans;
    }
};