#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> dist;
        vector<bool>rec(n+1);rec[0]=0;
        for(int i=1;i*i<=n;i++)dist.push_back(i*i);
        for(int i=1;i<=n;i++)
        {
            bool win = 0;
            for(auto &d:dist){
                if(d<=i){
                    if(rec[i-d]==0){win=1;break;}
                }else break;
            }
            rec[i]=win;
        }
        return rec[n];
    }
};