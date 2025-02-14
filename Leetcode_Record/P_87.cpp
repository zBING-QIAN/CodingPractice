#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    map<array<int,4>,bool> dp;
    bool isS(string &s1,string &s2,int l1,int r1,int l2,int r2){
        if(r1==l1)return s1[r1]==s2[r2];
        if(dp.find({l1,r1,l2,r2})!=dp.end()){return dp[{l1,r1,l2,r2}];}
        for(int i=0;i<r1-l1;i++){
            if(isS(s1,s2,l1,l1+i,r2-i,r2)&&isS(s1,s2,l1+i+1,r1,l2,l2+r1-l1-i-1)){dp[{l1,r1,l2,r2}] = 1;return 1;}
            if(isS(s1,s2,l1,l1+i,l2,l2+i)&&isS(s1,s2,l1+i+1,r1,l2+i+1,r2)){dp[{l1,r1,l2,r2}] = 1;return 1;}
        }
        dp[{l1,r1,l2,r2}] = 0;
        return 0;
    }
    

    bool isScramble(string s1, string s2) {
        return isS(s1,s2,0,s1.size()-1,0,s2.size()-1);
    }


};