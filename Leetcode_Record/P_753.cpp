#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> times;
    int K,N;
    string dfs(int cur){
        string out="";
        if(times[cur]<K){
            int nxt = (cur-(cur/N)*N)*10;
            // cout<<cur<<" "<<nxt<<" "<<times[cur]<<endl;
            int to = times[cur];times[cur]++;
            string tmp = dfs(nxt+to);
            out = to_string(to)+tmp;
            // cout<<"cur to "<<cur<<" "<<to<<" "<<tmp<<" "<<out<<endl;
            while(times[cur]<K){
                // cout<<cur<<" "<<nxt<<" "<<times[cur]<<endl;
                to = times[cur];times[cur]++;
                out = to_string(to)+dfs(nxt+to)+out;
            }
        }//
        return out;
    }
    string crackSafe(int n, int k) {
        if(n==1){string ans;for(int i=0;i<k;i++)ans+='0'+i;return ans;}
        int total = 1;
        K=k;N=1;for(int i=2;i<n;i++)N*=10;
        for(int i=0;i<n;i++)total*=10;
        times.resize(total,0);
        string out;
        out=dfs(0);
        return string(n-1,'0')+out;
    }
};