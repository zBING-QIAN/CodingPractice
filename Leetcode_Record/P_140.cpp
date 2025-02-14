#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    struct Trie{
        vector<Trie*> son;
        string *word;
        char c;
        Trie(){c=0;word=0;son.resize(26,0);}
        Trie(char C){c=C;word=0;son.resize(26,0);}
    }root;
    vector<string> ans;
    void search(string &s, string tmp,int idx){
        if(idx==s.size()){ans.push_back(tmp);return;}
        // cout<<tmp<<" " <<idx<<endl;
        Trie *cur = &root;
        if(tmp.size())tmp+=" ";
        for(;idx<s.size();idx++){
            if(cur->son[s[idx]-'a']){
                cur = cur->son[s[idx]-'a'];
                if(cur->word){
                    search(s,tmp+(*cur->word),idx+1);
                }
            }else break;
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto &w : wordDict){
            Trie *cur=&root;
            for(auto &c:w){
                if(cur->son[c-'a']==0){
                    cur->son[c-'a'] = new Trie(c);
                }
                cur = cur->son[c-'a'];
            }
            cur->word=&w;
        }
        string tmp;
        search(s,tmp,0);
        return ans;
    }
};