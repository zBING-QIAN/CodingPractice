#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(horizontalCut.begin(),horizontalCut.end());
        sort(verticalCut.begin(),verticalCut.end());
        long long h=1,v=1;
        long long ans =0;
        for(int i=m-2,j=n-2;i>=0||j>=0;){
            if(j<0||(i>=0&&horizontalCut[i]>verticalCut[j])){
                ans+=v*horizontalCut[i];
                h++;
                i--;
            }else if (j>=0){
                ans+=h*verticalCut[j];
                v++;
                j--;
            }
        }
        return ans;
    }
};