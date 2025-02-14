#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct AC{
        char c;
        string tmp;
        int tmp_i;
        map<char,AC*> son;
        AC *fp;
        int len;
        AC(char C){c=C;len = INT_MAX;fp =0;}
        AC(char C,AC *FP){
            c=C;len = FP->len;fp = FP;
        }
        AC(){c=0;fp=0;len = INT_MAX;}
    }*root;



    int longestValidSubstring(string word, vector<string>& forbidden) {
        int ans =0;
        root= new AC();
        //build trie
        for(auto &f:forbidden){
            AC *cur  = root;
            for(int i=0;i<f.size();i++){
                if(cur->son.find(f[i])==cur->son.end()){
                    cur->son[f[i]]=new AC(f[i]);
                }
                cur = cur->son[f[i]];        cur->tmp = f;cur->tmp_i = i;
            }
            cur->len=f.size(); 
        }
        //add fp bfs
        vector<AC*> q;q.push_back(root);
        int flag=0;
        while(flag<q.size()){
            AC *cur = q[flag];
            for(auto &[c, to]:cur->son){
                AC *fp = cur->fp;
                while(fp&&fp->son.find(c)==fp->son.end()){
                    fp = fp->fp;
                }
                fp = (fp==0)?root:fp->son[c];
                AC *a = cur->son[c];
                a->fp = fp;
                a->len=min(a->fp->len,a->len);
                // cout<<fp->len<<" "<<cur->len<<endl;
                q.push_back(a);
            }
            flag++;
        }
        q.clear();

        int s=-1,l=0;AC *cur= root;
        for(int i=0;i<word.size();i++){
            if(cur->son.find(word[i])==cur->son.end()){
                cur = cur->fp;
                while(cur&&cur->son.find(word[i])==cur->son.end()){cur = cur->fp;}
                
            }
            cur = (cur==0)?root:cur->son[word[i]];
            s = max(s,i-cur->len+1);
            ans = max(ans,i-s);
        }
        return ans;
    }
};