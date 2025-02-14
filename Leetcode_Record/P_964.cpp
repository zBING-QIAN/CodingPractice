#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int aim,ans = INT_MAX;
    map<int,int>rec;
    int loet(int x,long long target,int cur = 0){
        // cout<<"begin "<<target<<" "<<cur<<endl;
        if(rec.find(target)!=rec.end())return rec[target];
        long long xx = x;
        int times = 1;
        while(xx<target){times++;xx*=x;}
        if(xx==target){
            rec[target] = times-1;ans = min(ans,cur+times-1);return times-1;
        }
        xx/=x;times--;
        int cnt = (abs(times-1)+1)*(target/xx);
        // if(cur+cnt-1<ans){
            // cout<<target<<" "<<cur<<" "<<cnt<<endl;
            int tmp = -1;
            if(target%xx){tmp = loet(x,target%xx,cur+cnt);}
            if(tmp < 1e9){rec[target] = cnt+tmp;ans = min(ans,cur+rec[target]);}
        // }
        // if(cur+times<ans){
            times++;xx*=x;
            
            tmp = (xx-target>0)?loet(x,xx-target,cur+times):-1;
            
            if(tmp < 1e9){
                if(rec.find(target)==rec.end())rec[target] = times+tmp;
                else rec[target] = min(rec[target],times+tmp);
                ans = min(ans,cur+rec[target]);
            }
            
        // }
        if(rec.find(target)!=rec.end())return rec[target];
        return 1e9;
    }

    int leastOpsExpressTarget(int x, int target) {
        aim = target;rec[0]=0;
        loet(x,target);
        return ans;
    }
};