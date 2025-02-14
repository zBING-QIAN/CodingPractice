#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int f=0,s=m-1;
        
        if(grid[0][s]<grid[0][f])swap(s,f);
        for(int i=0;i<m;i++){
            // cout<<"s dps i dpi "<<s<<" "<<dp[s]<<" "<<i<<" "<<dp[i]<<endl;
            if(grid[0][s]>grid[0][i]&&i!=f){
                s = i;
                if(grid[0][s]<grid[0][f])swap(s,f);
            }
        }
        for(int j=1;j<n;j++){
            // cout<<s<<" "<<f<<endl;
            for(int i=0;i<m;i++){
                if(i==f){
                    grid[j][i]=grid[j-1][s]+grid[j][i];
                }
                else {
                    grid[j][i]=grid[j-1][f]+grid[j][i];
                }
            }
            f=0,s=m-1;
            if(grid[j][s]<grid[j][f])swap(s,f);
            for(int i=0;i<m;i++){
                if(grid[j][s]>grid[j][i]&&i!=f){
                    s = i;
                    if(grid[j][s]<grid[j][f])swap(s,f);
                }
            }
        }
        return grid[n-1][f];
    }
};