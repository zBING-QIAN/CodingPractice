#include <bits/stdc++.h>
using namespace std;


class Solution {

        
public:
    
    struct node{
        int isleaf;
        map<char,node*> son;
        node(){isleaf = -1;}
    };
    int flag = 0;
    
    vector<int> findSubstring(string s, vector<string>& words) {
        int len = words[0].length();
        int sz = words.size();
        int matchno =sz;
        vector<int> ans;
        vector<node> trie(30*5000+100);
        vector<int> count(sz,1);
        
        for(int t = 0;t<sz;t++){
            node *root = &trie[0];    
            for(int i=0;i<len;i++){
                if(root->son.find(words[t][i]) == root->son.end()){
                    root->son[words[t][i]] = &trie[++flag];
                    if(i==len-1)root->son[words[t][i]]->isleaf = t;
                }root=root->son[words[t][i]];  
            }if(root->isleaf!=t)count[root->isleaf]++,matchno--;
        }
        for(int i=0;i<len;i++){          
            vector<int>counttmp(sz,0);
            vector<int>rec;
            int st = 0,typ =0,cur = 0;
            for(int j=i;j<s.length();j+=len,cur++){
                node *root = &trie[0];  
                for(int k=0;k<len&&k+j<s.length();k++){
                    if(root->son.find(s[j+k])==root->son.end()){root = &trie[0];break;}
                    root = root->son[s[j+k]]; 
                }
                if(root->isleaf>=0){
                    counttmp[root->isleaf]++;
                    if(counttmp[root->isleaf]==count[root->isleaf])typ++;
                    cout<<root->isleaf<<" count "<< counttmp[root->isleaf]<<" need "<<count[root->isleaf]<<endl;
                    if(typ==matchno){ans.push_back(j-len*(sz-1));}
                }
                rec.push_back(root->isleaf);
                if(rec.size()>=sz&&rec[rec.size()-sz]>=0){
                    if(counttmp[rec[rec.size()-sz]]==count[rec[rec.size()-sz]])typ--;
                    counttmp[rec[rec.size()-sz]]--;
                }
            }
        }
        return ans;
    }
};