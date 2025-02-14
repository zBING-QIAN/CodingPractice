#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& points, int m) {
        long long l=0,r = 1e15;
        int n = points.size();
        points.push_back(0);
        while(l<r){
            long long mid = (l+r)>>1;
            long long nxt_v = 0;
            long long mtmp = m;
            for(int i=0;i<n;i++){
                if(i==n-1&&nxt_v>=mid)continue;
                long long cur = nxt_v+points[i];nxt_v = 0;mtmp--;
                if(mid<=cur)continue;
                long long times = (mid-cur+points[i]-1)/points[i];
                mtmp-=times*2;
                // cout<<i<<" "<<times<<" "<<mtmp<<" "<<mid<<endl;
                if(mtmp<0)break;
                nxt_v = times*points[i+1];
            }
            // cout<<mid<<" "<<mtmp<<endl;
            if(mtmp>=0)l = mid+1;
            else r = mid;
        }
        if(l==0)return 0;
        return l-1;
    }
};