#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> link;
    int in[6],out[6];
    int ans;
    
    pair<string,int> bfs(){
        vector<int> que,mask,pre,root;
        for(int i=0;i<6;i++){
            if(out[i]){que.push_back(i);pre.push_back(-1);mask.push_back((1<<i));root.push_back(i);}
        }
        int flag = 0;
        while(flag<que.size()){
            for(int i=0;i<6;i++){
                if(link[que[flag]][i]){
                    if(mask[flag]&(1<<i)){
                        if(root[flag]==i){
                            int p = pre[flag],now = flag,maxflow= link[que[flag]][i];
                            while(p!=-1&&maxflow>0){
                                maxflow = min(maxflow,link[que[p]][que[now]]);
                                now = p;p = pre[p];
                            }
                            if(maxflow){
                                string tmp= string(1,'a'+que[flag]);
                                link[que[flag]][i]-=maxflow;
                                p = pre[flag];now = flag;
                                while(p!=-1){
                                    tmp = string(1,'a'+que[p])+tmp;
                                    link[que[p]][que[now]]-=maxflow;
                                    now = p;p = pre[p];
                                }
                                return {tmp,maxflow};
                            }
                        }
                    }else {
                        que.push_back(i);root.push_back(root[flag]);pre.push_back(flag);mask.push_back(mask[flag]|(1<<i));    
                    }
                    
                }
            }
            flag++;   
        }
        return {"",0};
    }
    void solve(){
        map<string,int> rec;
        while(true){
            pair<string,int> out = bfs();
            cout<<out.first<<" "<<out.second<<endl;
            if(out.second==0)break;
            rec[out.first] += out.second;
        }
        //handle 1 3-cycles and 1 6-cycles to 3 3-cycles
        for(auto &r : rec){
            if(r.first.size()==6){
                string odd="",even="";
                for(int i=0;i<6;i++){if(i&1)odd+=r.first[i];else even+=r.first[i];}
                reverse(odd.begin(),odd.end());
                reverse(even.begin(),even.end());
                for(int t=0;t<3;t++){
                    string tmpo = "",tmpe = "";
                    for(int i=0;i<3;i++){
                        tmpo+=odd[(i+t)%3];
                        tmpe+=even[(i+t)%3];            
                    }
                    if(rec.find(tmpo)!=rec.end()&&rec[tmpo]>0){
                        int c = min(r.second,rec[tmpo]);
                        r.second -=c ;ans+=6*c;rec[tmpo]-=c;
                    }      
                    if(rec.find(tmpe)!=rec.end()&&rec[tmpe]>0){
                        int c = min(r.second,rec[tmpe]);
                        r.second -=c ;ans+=6*c;rec[tmpe]-=c;
                    }
                    if(r.second==0)break;
                }
            }
        }
        for(auto &r : rec){
            ans+= (r.first.size()-1)*r.second;
        }
    }
    int kSimilarity(string s1, string s2) {
        link.resize(6,vector<int>(6,0));for(int i=0;i<6;i++){in[i]=0;out[i]=0;}
        ans = 0;
        for(int i=0;i<s1.size();i++){
            if(s1[i] !=s2[i]){
                link[s1[i]-'a'][s2[i]-'a']++;out[s1[i]-'a']++;in[s2[i]-'a']++;
            }
        }
        for(int i=0;i<6;i++){
            for(int j=i;j<6;j++){
                int m = min(link[i][j],link[j][i]);
                link[i][j]-=m;link[j][i]-=m;
                ans+=m;
            }
        }
        solve();
        return ans;
                    
    }
};