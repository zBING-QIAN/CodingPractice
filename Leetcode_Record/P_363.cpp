#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int h=matrix.size(),w = matrix[0].size();
        vector<vector<int>> rec;rec.resize(h,vector<int>(w,0));
        int ans = -1e5;
        for(int i=0;i<h;i++){
            for(int k=0;k<i;k++)for(int l=0;l<w;l++)rec[k][l]=0;
            for(int j=0;j<w;j++){
                int sum = 0;
                for(int a=i;a>=0;a--){
                    sum+=matrix[a][j];
                    for(int b=j;b>=0;b--){
                        rec[a][b]+=sum;
                        if(rec[a][b]<=k)ans = max(ans,rec[a][b]);
                    }
                }
            }
        }
        return ans;
    }
};