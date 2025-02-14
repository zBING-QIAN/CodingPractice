#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        map<int,int> table;
        for(auto &w:words){
            int tmp =0,cnt =0;
            for(auto c:w){
                if((tmp&(1<<(c-'a')))==0){
                    tmp|=(1<<(c-'a'));
                    cnt++;
                }
                if(cnt>7)break;
            }
            if(cnt<=7)table[tmp]++;
        }
        vector<int> ans;
        
        for(int i=0;i<puzzles.size();i++){
            string &p = puzzles[i];
            vector<int> cand;cand.push_back((1<<(p[0]-'a')));
            int cnt =table[cand[0]];
            for(int j=1;j<7;j++){
                int cs = cand.size();
                for(int k=0;k<cs;k++){
                    int tmp = cand[k]|(1<<(p[j]-'a'));
                    cand.push_back(tmp);
                    cnt+=table[tmp];
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};