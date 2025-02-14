#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string lastSubstring(string s) {
        vector<int> kmp(s.size()+1,-1);
        int best=0,pre=-1;
        for(int i=1;i<s.size();i++){
            int larger = -1;
            while(s[best+pre+1]!=s[i]){
                if (s[best+pre+1]<s[i])larger=pre+1;
                if(pre<0)break;
                pre = kmp[pre];    
            }
            if(s[best+pre+1]==s[i]){pre++;}
            if(larger>=0){
                best = i-larger;
            }
            kmp[i-best] = pre;
        }
        return s.substr(best);
    }
};