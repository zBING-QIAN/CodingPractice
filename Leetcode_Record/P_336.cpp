#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Trie{
        int idx,ridx;
        map<char,Trie*> nxt;
        Trie(){idx = -1;ridx=-1;}
    }root;
    void run_pal(string &s,vector<int> &pal){
        string tmp = " ";
        for(auto &c:s)tmp+=c,tmp+=" ";
        vector<int> dp(tmp.size(),0);
        int mid = 0,width = 0;
        for(int i=1,c=1,w=0;i<tmp.size();i++){
            int mir = 2*c-i;
            if(c+w<=dp[mir]+i){
                w = c+w-i+1;c = i;
                while(c+w<tmp.size()&&c-w>=0&&tmp[c+w]==tmp[c-w]){
                    w++;
                }
                w--;
                dp[i] = w;
            }else{
                dp[i] = dp[mir];
            }
        }
        for(int i=0;i<tmp.size();i++){
            if(i+dp[i]==tmp.size()-1){
                pal[(i-dp[i])/2] = 1;
            }
        }
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        for(int i=0;i<n;i++){
            string w = words[i];
            Trie *cur = &root;
            for(auto c:w){
                if(cur->nxt.find(c)==cur->nxt.end())cur->nxt[c] = new Trie();
                cur = cur->nxt[c];
            }
            cur->idx = i;
            reverse(w.begin(),w.end());
            cur = &root;
            for(auto c:w){
                if(cur->nxt.find(c)==cur->nxt.end())cur->nxt[c] = new Trie();
                cur = cur->nxt[c];
            }
            cur->ridx = i;
        }
        set<pair<int,int>> ans_set;
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            Trie *cur = &root;
            string tmp = words[i];
            vector<int> pal(tmp.size()+1,0);
            run_pal(tmp,pal);
            for(int j=0;j<pal.size();j++){
                
                if(cur->ridx!=-1&&pal[j]&&cur->ridx!=i)ans_set.insert({i,cur->ridx});
                if(tmp.size()>j&&cur->nxt.find(tmp[j])!=cur->nxt.end())
                {
                    cur = cur->nxt[tmp[j]];
                }
                else break;
            }
            
            vector<int> pal_r(tmp.size()+1,0);
            reverse(tmp.begin(),tmp.end());
            run_pal(tmp,pal_r);
            cur=&root;
            for(int j=0;j<pal_r.size();j++){
                
                if(cur->idx!=-1&&pal_r[j]&&cur->idx!=i)ans_set.insert({cur->idx,i});
                if(tmp.size()>j&&cur->nxt.find(tmp[j])!=cur->nxt.end())
                {
                    cur = cur->nxt[tmp[j]];
                }
                else break;
            }
        }
        for(auto &a:ans_set){ans.push_back({a.first,a.second});}
        return ans;
    }
};