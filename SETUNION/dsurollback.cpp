#include<bits/stdc++.h>
using namespace std;
vector<int>team;
vector<int>epoch;
int ans;
vector<vector<vector<int>>> persist;
int leader(int a){
    persist.back().back().push_back(a);
    if(team[a]!=a){
       team[a] = leader(team[a]);
    }else persist.back().back().push_back(a);
    return team[a];
}
int main(){
    int n,m;cin>>n>>m;ans = n;
    int a,b;
    team.resize(n+1);
    persist.push_back(vector<vector<int>>());epoch.push_back(ans);
    for(int i=0;i<=n;i++)team[i] = i;
    string op;
    for(int i=0;i<m;i++){
        cin>>op;
        if(op=="persist"){
            persist.push_back(vector<vector<int>>());
            epoch.push_back(ans);
        }
        else if(op == "union"){
            scanf("%d %d",&a,&b);
            persist.back().push_back(vector<int>());
            int t1 = leader(a);
            persist.back().push_back(vector<int>());
            int t2 = leader(b);
            if(t1!=t2){
                ans--;
                team[t2]=t1;
            }printf("%d\n",ans);
        }
        else{
            while(persist.back().size()){
                for(int j = 0;j<persist.back().back().size()-1;j++){
                    team[persist.back().back()[j]]=persist.back().back()[j+1];
                }
                persist.back().pop_back();
            }
            
            persist.pop_back();
            ans = epoch.back();
            printf("%d\n",ans);
            epoch.pop_back();
            // for(int i=0;i<epoch.size();i++){
            //     printf("%d\n",epoch[i]);
            // }
            
        }
    }
    return 0;
}