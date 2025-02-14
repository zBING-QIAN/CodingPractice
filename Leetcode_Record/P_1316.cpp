#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distinctEchoSubstrings(string text) {
        vector<int> kmp(text.size()+1,-1),start(text.size()+1,0);
        int ans=0;
        for(int t=0;t<text.size();t++){
            int pre = -1;
            for(int i=t+1;i<text.size();i++){
                while(pre>=0&&text[t+pre+1] != text[i]){
                    pre = kmp[pre];
                }
                if(text[t+pre+1] == text[i])pre++;
                kmp[i-t] = pre;
                int mod = (pre+1)%(i-t-pre);
                int div = (pre+1)/(i-t-pre);
                if(start[t]<i-t&&mod == 0&&(div&1)){
                    ans++;
                }
                start[i-pre] = max(pre,start[i-pre]);
            }
        }
        return ans;
    }
};