#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct sft{
        char c;
        map<char,sft*> son;
        int cand;
        sft(){cand=-1;}
        sft(char C){c=C;cand=-1;}//son.resize(26,0);
    }root;

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int t =0;
        for(auto &w:wordsContainer){
            sft *cur = &root;
            for(int i=w.size()-1;i>=0;i--){
                if(cur->cand==-1||wordsContainer[cur->cand].size()>w.size()){cur->cand=t;}
                if(cur->son[w[i]]==0)cur->son[w[i]]=new sft(w[i]);
                cur=cur->son[w[i]];
            }if(cur->cand==-1||wordsContainer[cur->cand].size()>w.size()){cur->cand=t;}
            t++;
        }
        vector<int> ans;
        for(auto &w:wordsQuery){
            sft *cur = &root;
            for(int i=w.size()-1;i>=0;i--){
                if(cur->son[w[i]]){
                    cur = cur->son[w[i]];
                }else {
                    break;
                }
            }ans.push_back(cur->cand);
        }
        return ans;
    }
};