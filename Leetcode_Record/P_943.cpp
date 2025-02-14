#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestSuperstring(vector<string>& words) {
        vector<vector<int>> link(words.size(),vector<int>(words.size(),0));
        for(int i=0;i<words.size();i++){
            vector<int>fp(words[i].size(),-1);
            for(int j=1;j<words[i].size();j++){
                int p = fp[j-1];
                while(p>=0&&words[i][p+1]!=words[i][j]){p = fp[p];}
                if(words[i][j]==words[i][p+1]){
                    fp[j] = p+1;
                }
            }
            for(int j=0;j<words.size();j++){
                if(j==i){link[i][i] = words[i].size();continue;}
                else {
                    int h=-1;
                    for(int k=0;k<words[j].size();k++){
                        while(h>=0&&words[i][h+1]!=words[j][k]){h = fp[h];}
                        if(words[i][h+1]==words[j][k]){
                            h++;
                        }
                    }
                    link[j][i] = words[i].size()-(h+1);
                }
            }

        }
        // for(int i=0;i<words.size();i++)for(int j=0;j<words.size();j++)cout<<i<<" "<<j<<" "<<link[i][j]<<endl;
        // init link
        //
        vector<vector<int>> dp(words.size(),vector<int>(1<<words.size(),INT_MAX));
        vector<vector<array<int,2>>> from(words.size(),vector<array<int,2>>(1<<words.size(),{-1,0}));
        vector<array<int,2>> q;
        for(int i=0;i<words.size();i++){q.push_back({i,(1<<i)});dp[i][(1<<i)]=words[i].size();}
        for(int i=0;i<words.size();i++){  // i = 1
            vector<array<int,2>> nxt;
            for(auto &[f,cur]:q){
                // cout<<cur<<" "<<dp[cur]<<" "<<endwith[cur]<<" "<<from[cur]<<endl;
                for(int j=0;j<words.size();j++){
                    if((cur&(1<<j))==0){
                        int to = cur+(1<<j);
                        if(from[j][to][0]==-1)nxt.push_back({j,to});
                        
                        if(dp[j][to]>dp[f][cur]+link[f][j]){
                            from[j][to] = {f,cur};
                            dp[j][to] = dp[f][cur]+link[f][j];
                            // cout<<f<<" "<<j<<" "<<to<<" "<<dp[j][to]<<endl;
                        }
                    }
                }
            }
            q=nxt;
        }

        int last=0,tail = (1<<words.size())-1;
        for(int mindp= INT_MAX,i=0 ;i<words.size();i++){
            if(dp[i][tail]<mindp){last=i;mindp = dp[last][tail];}
            // cout<<mindp<<endl;
        }
        cout<<dp[last][tail]<<endl;
        vector<int> seq;
        while(tail){
            seq.push_back(last);
            auto [f,p] = from[last][tail];
            // cout<<tail<<" "<<last<<endl;//-link[tail][last]<<endl;
            
            tail = p;
            last = f;
        }
        reverse(seq.begin(),seq.end());
        // for(auto s:seq)cout<<s<<" ";cout<<endl;
        string ans=words[seq[0]];
        cout<<seq[0]<<endl;
        for(int i=1;i<seq.size();i++){
            // cout<<seq[i]<<" "<<words[seq[i]].size()-link[seq[i-1]][seq[i]]<<endl;
            ans += words[seq[i]].substr(words[seq[i]].size()-link[seq[i-1]][seq[i]]);
        }
        return ans;
    }
};