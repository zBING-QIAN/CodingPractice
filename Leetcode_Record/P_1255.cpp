#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ans=0;
    map<vector<int>,int> dp;
    void search(vector<int> &cur,vector<int> &score,vector<pair<int,map<int,int>>> &table,int s,int idx){
        if(idx == table.size()){
            ans = max(ans,s);return;
        }
        bool yes = 1;
        for(auto &[i,c]:table[idx].second){
            if(cur[i]<c){yes = 0;break;}
        }
        if(yes){
            for(auto &[i,c]:table[idx].second){
                cur[i]-=c;
            }
            search(cur,score,table,s+table[idx].first,idx+1);
            for(auto &[i,c]:table[idx].second){
                cur[i]+=c;
            }
        }
        search(cur,score,table,s,idx+1);
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        sort(words.begin(),words.end());
        vector<pair<int,map<int,int>>> table;
        for(auto &w:words){
            int s = 0;
            map<int,int> tmp;
            for(auto c:w){
                tmp[c-'a']++;s+=score[c-'a'];
            }
            table.push_back({s,tmp});
        }
        vector<int> letter(26,0);for(auto l:letters)letter[l-'a']++;
        search(letter,score,table,0,0);
        return ans;
    }
};