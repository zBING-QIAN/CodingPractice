#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct trie{
        int word_cnt;
        map<char,trie*> son;
        trie(){word_cnt=0;}
    }root;
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int> ans;
        trie *rt=&root;
        for(auto &w:words){
            trie *cur = rt;
            for(int i=0;i<w.size();i++){
                if(cur->son.find(w[i])==cur->son.end()){cur->son[w[i]]= new trie();}
                cur=cur->son[w[i]];
                cur->word_cnt++;
            }
        }
        for(auto &w:words){
            trie *cur = rt;
            int tmp=0;
            for(int i=0;i<w.size();i++){
                cur=cur->son[w[i]];
                tmp+=cur->word_cnt;
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};