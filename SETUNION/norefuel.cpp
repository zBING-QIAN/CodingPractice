#include<bits/stdc++.h>
using namespace std;
vector<int> team;
int leader(int a){
    if(team[a]!=a){
        team[a] = leader(team[a]);
    }return team[a];
}
int main(){
    int k,n;cin>>n>>k;
    vector<array<int,3>> link;
    int a,b,v,ansi;
    for(int i=0;i<k;i++){
        cin>>a>>b>>v;link.push_back({a,b,v});
    }  
    team.resize(n+1);for(int j=0;j<=n;j++)team[j] =j;
    sort(link.begin(),link.end(),[](auto a,auto b){return a[2]<b[2];});
    for(int i=0;i<k;i++){
        int t1 = leader(link[i][0]),t2 = leader(link[i][1]);
        if(t1!=t2){team[t1] = t2;ansi = i;}
    }
    cout<<link[ansi][2];     

    return 0;
}