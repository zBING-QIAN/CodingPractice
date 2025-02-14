#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ans;
    vector<int> x,y;
    void dfs(int i,int n){
        if(i==n){ans++;return;}
        for(int j=0;j<n;j++){
            bool skip = 0;
            for(int k =0;k<x.size();k++){
                int xtmp = abs(x[k]-i),ytmp = abs(y[k]-j);
                if(xtmp==0||ytmp==0||xtmp==ytmp)skip = 1;
            }
            if(!skip){
                x.push_back(i);y.push_back(j);
                dfs(i+1,n);
                x.pop_back();y.pop_back();
            }
        }
    }
    int totalNQueens(int n) {
        ans = 0;
        dfs(0,n);
        return ans;
    }
};