#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mod = 1e9+7;
    struct node{
        char c;
        int idx;
        node *pre;
        map<int,node*> son;
        node(char C,int i){idx= i;
            c=C;pre = 0;
        }
        node(){pre =0;idx =0;}

    }root;
    vector<node*> state;
    int nxt_idx(char c,int cur,vector<int> &mis,string &evil){  // make sure cur<evil.size()
        while(cur>=0 && c!=evil[cur+1]){
            cur = mis[cur];
        }
        return cur+1;
    }
    long long calc(vector<int> &mis,vector<vector<long long>> &dp,string &low,string &high,string &evil,int idx){
        long long ans =0;
        // cout<<low<<" "<<high<<endl;
        for(int i=0;i<low.size()&&idx < evil.size()-1;i++){
            if(high[i]-low[i]>0){
                int remain_size= low.size()-i-1;
                int idxtmp;
                for(char c = low[i]+1;c<high[i];c++){
                    long long tmp = dp[remain_size][evil.size()-1];   // dp[len][state]
                    // cout<<remain_size<<" "<<evil.size()-1<<endl;
                    idxtmp=nxt_idx(c,idx,mis,evil);
                    tmp = (tmp-dp[remain_size][idxtmp])%mod;
                    // cout<<dp[remain_size][idxtmp]<<endl;
                    // cout<<"in calc, low: "<<low<<" "<<i<<" "<<c<<" "<<tmp<<" "<<idxtmp<<endl;
                    ans = (ans+tmp)%mod;
                }
                idxtmp = nxt_idx(low[i],idx,mis,evil);
                string nxt_low = low.substr(i+1);
                string nxt_high = string(nxt_low.size(),'z');
                // cout<<"low : "<<nxt_low<<" high : "<<nxt_high<<endl;
                if(nxt_low == string(nxt_high.size(),'a')){
                    long long tmp = dp[remain_size][evil.size()-1];   // dp[len][state]
                    tmp = (tmp-dp[remain_size][idxtmp])%mod;
                    ans = (ans+tmp)%mod;
                }
                else ans = (ans+calc(mis,dp,nxt_low,nxt_high,evil,idxtmp))%mod;


                idxtmp = nxt_idx(high[i],idx,mis,evil);
                nxt_high = high.substr(i+1);
                nxt_low = string(nxt_high.size(),'a');
                // cout<<"low : "<<nxt_low<<" high : "<<nxt_high<<endl;
                if(nxt_low == string(nxt_high.size(),'z')){
                    long long tmp = dp[remain_size][evil.size()-1];   // dp[len][state]
                    tmp = (tmp-dp[remain_size][idxtmp])%mod;
                    ans = (ans+tmp)%mod;
                }
                else ans = (ans+calc(mis,dp,nxt_low,nxt_high,evil,idxtmp))%mod;
                return ans;
            }
            idx=nxt_idx(low[i],idx,mis,evil);
        }
        return (idx < evil.size()-1);
    }
    int findGoodStrings(int n, string s1, string s2, string evil) {
        node *cur = &root;
        int elen = evil.size();
        cur->idx = elen;
        state.resize(evil.size()+1,0);state[evil.size()]=cur;
        for(int i=evil.size()-1;i>=0;i--){
            state[i+1]=cur;
            node *p = cur->pre;
            if(p)cur->son = p->son;
            int eidx = evil[i]-'a';
            cur->son[eidx] = new node(evil[i],i);
            // state[i] = cur->son[eidx];
            if(p&&p->son.find(eidx)!=p->son.end())
                cur->son[eidx]->pre = p->son[eidx];
            else cur->son[eidx]->pre = &root;
            cur = cur->son[eidx];
        }
        // cout<<"state transition over\n";
        vector<vector<long long>> dp(n+1,vector<long long>(elen+1,0));dp[0][elen]=1;
        for(int t=1;t<=n;t++){
            cur = &root;
            while(cur->son.size()){   // check last one should not enter this block
                for(auto &[c,nxt]:cur->son)
                    if(nxt->idx != 0)
                        dp[t][nxt->idx] = (dp[t][nxt->idx]+dp[t-1][cur->idx])%mod;
                dp[t][elen] = (dp[t][elen] + dp[t-1][cur->idx]*(26-cur->son.size()))%mod; 
                cur = cur->son[evil[cur->idx-1]-'a'];
            }
        }
        // cout<<"dp first stage over\n";
        for(int t=1;t<=n;t++){
            for(int i=1;i<elen;i++){
                int pre = state[i]->pre->idx;
                dp[t][pre] = (dp[t][pre]+ dp[t][i])%mod;
            }
            // for(int i=0;i<=elen;i++){
            //     cout<<t<<" "<<i<<" "<<dp[t][i]<<" ";
            // }cout<<endl;
        }

        // cout<<"dp over\n";
        evil = " "+evil;
        vector<int> mis(evil.size(),0);mis[0]=-1;
        for(int i=1;i<evil.size()-1;i++){
            int tmp = mis[i];
            while(tmp>=0&&evil[tmp+1] != evil[i+1]){
                tmp = mis[tmp];
            }
            mis[i+1] = tmp+1;
        }
        // cout<<"mis pointer over\n";


        // evil = evil.substr(1);
        long long ans = calc(mis,dp,s1,s2,evil,0);
        
    
        return ans;
    }
};