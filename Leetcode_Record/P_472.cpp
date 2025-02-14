#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct trie{
        char c;
        bool isword;
        vector<trie*> nxt;
        trie(char C){c=C;isword = 0;nxt.resize(26,0);}
    }*rt;
    
    bool dfs(trie *cur,string &w,int i,set<pair<int,trie*>> &rec){
        // cout<<w<<" "<<i<<" "<<rec.size()<<endl;
        if(rec.find({i,cur})!=rec.end())return 0;
        if(i==w.size())return cur->isword;
        
        if(cur->nxt[w[i]-'a']){
            if(dfs(cur->nxt[w[i]-'a'],w,i+1,rec))return 1;
        }
        if(cur->isword){
            if(dfs(rt,w,i,rec))return true;
        }
        rec.insert({i,cur});
        return false;
        
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        rt = new trie(0);
        vector<string> ans;
        sort(words.begin(),words.end(),[&](auto &a,auto &b){return a.size()<b.size();});
        for(auto &w : words){
            // run trie
            trie *cur =rt;
            set<pair<int,trie*>> rec;
            if(dfs(cur,w,0,rec)){ans.push_back(w);}
            // add trie
            for(int i=0;i<w.size();i++){
                if(cur->nxt[w[i]-'a']==0){
                    cur->nxt[w[i]-'a'] = new trie(w[i]);
                }
                cur=cur->nxt[w[i]-'a'];
            }
            cur->isword = 1;
        }
        return ans;
        
    }
};