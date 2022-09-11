#include<bits/stdc++.h>
using namespace std;
vector<int> team,teamnumber;
vector<array<int,3>> link;
int leader(int a){
    if(team[a]!=a)team[a] = leader(team[a]);
    return team[a];
}

void callerr(){
    int a=19,b =3;
    cout<<a/(b-3);
}
int main(){
    int n,m;cin>>n>>m;
    team.resize(n+1);teamnumber.resize(n+1);
    int a,b,v;
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&a,&b,&v);
        link.push_back({a,b,v});
    }
    sort(link.begin(),link.end(),[](auto a,auto b){
        return a[2]<b[2];
    });
    int ans = 2e9+5,small,big;
    for(int t = 0;t<m;t++){
        small = big = link[t][2];
        for(int i=0;i<=n;i++)team[i]=i,teamnumber[i]=1;
        for(int i=t;i<m;i++){
            a = leader(link[i][0]),b = leader(link[i][1]);
            if(a!=b){team[a] = b;big = link[i][2];teamnumber[b] += teamnumber[a];}
        }
        
        if(teamnumber[leader(1)] == n)ans = min(ans,big-small);
        else break;
    }
    if(ans == 2e9+5){cout<<"NO\n";return 0;}
    cout<<"YES\n"<<ans;
    return 0;
}