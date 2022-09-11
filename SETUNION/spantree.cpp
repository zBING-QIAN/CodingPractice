#include<bits/stdc++.h>
using namespace std;
vector<int> team;
int leader(int a){
    if(team[a]!=a)team[a] = leader(team[a]);
    return team[a];
}

int main(){
    int n,m;cin>>n>>m;
    team.resize(n+1);for(int i=1;i<=n;i++)team[i] = i;
    vector<array<int,3>> link;
    int a,b,v;
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&a,&b,&v);
        link.push_back({a,b,v});
    }
    sort(link.begin(),link.end(),[](auto a,auto b){
        return a[2]<b[2];
    });
    long long ans = 0;
    for(int i=0;i<m;i++){
        int t1 = leader(link[i][0]),t2= leader(link[i][1]);
        if(t1!=t2){ans+=link[i][2];team[t1] = t2;}
    }cout<<ans;
    return 0;
}