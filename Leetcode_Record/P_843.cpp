#include <bits/stdc++.h>
using namespace std;
class Master {
    public:
    int guess(string word);
};
class Solution {
public:
    bool matchn(string &a,string &b,int match){
        for(int i=0;i<6;i++){if(a[i]==b[i]){match--;}}
        //cout<<a<<" "<<b<<" "<<match<<endl;
        return match==0;
    }
    void findSecretWord(vector<string>& words, Master& master) {
        vector<int> rec(words.size());for(int i=0;i<words.size();i++)rec[i]=i;
        // int cnt = 0;
        int times = 0;
        // cout<<rec.size()<<endl;
        while(rec.size()>0){
            vector<int> cnt;
            vector<int> score(rec.size(),0);
            for(int i=0;i<6;i++){
                cnt.clear();cnt.resize(26,0);
                for(auto &wid : rec){
                    cnt[words[wid][i]-'a']++;
                }
                for(int j=0;j<rec.size();j++){
                    int gg = (cnt[words[rec[j]][i]-'a']<rec.size()-cnt[words[rec[j]][i]-'a'])
                        ?cnt[words[rec[j]][i]-'a']:rec.size()-cnt[words[rec[j]][i]-'a'];
                    score[j]+=gg;
                }
            }
            int id=0,good =0 ;//= rand()%rec.size();//rec.size()-1;//
            for(int i=0;i<rec.size();i++){if(good<score[i]){id = i;good = score[i];}}
            string cur = words[rec[id]];
            // cout<<++times<<" times "<<rec.size()<<" "<<cur<<"\n";
            int tmp = master.guess(cur);
            // cout<<tmp<<endl;
            // cout<<tmp<<endl;
            if(tmp == 6)return;
            // rec.pop_back();
            vector<int> rec_tmp;
            for(int i=0;i<rec.size();i++){
                if(id == i)continue;
                if(matchn(cur,words[rec[i]],tmp))rec_tmp.push_back(rec[i]);
            }
            // cout<<rec_tmp.back()<<endl;
            rec=rec_tmp;
        }
    }
};