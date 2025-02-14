#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> x,y;
    vector<vector<string>> ans;
    string empty_row = "";
    void dfs(int i,int n,vector<string> &cur_map){
        if(i==n){
            ans.push_back(cur_map);return;
        }
        for(int j=0;j<n;j++){
            bool skip = 0;
            for(int k=0;k<x.size();k++){
                int xtmp = abs(x[k]-i),ytmp = abs(y[k]-j);
                if(xtmp==0||ytmp==0||xtmp==ytmp){skip = 1;break;}
            }
            if(!skip){
                x.push_back(i);y.push_back(j);
                string stmp = empty_row;stmp[j] = 'Q';
                cur_map.push_back(stmp);
                dfs(i+1,n,cur_map);
                x.pop_back(),y.pop_back(),cur_map.pop_back();
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {    
        vector<string> tmp;
        for(int i=0;i<n;i++)empty_row += ".";
        dfs(0,n,tmp);

        return ans;
    }
};