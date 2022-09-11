#include<bits/stdc++.h>
using namespace std;
vector<array<int,2>> link;
vector<array<int,2>> dlink;
vector<int> team;
vector<int> falltime;
#define FALLING 1e9
int leader(int a){
    if(team[a]!=a&&falltime[a]==FALLING)team[a] = leader(team[a]);
    return team[a];
}
void unionfn(int a,int b){
    int t1 = leader(a),t2 = leader(b);
    if(t1>t2)team[t1] = t2;
    else if(t1<t2)team[t2] = t1;
}

int main(){
    int n,m;cin>>n>>m;
    int a,b;
    team.resize(n+1);falltime.resize(n+1,FALLING);falltime[1] = -1; link.push_back({0,0});
    for(int i=1;i<=n;i++){team[i]=i;scanf("%d %d",&a,&b);link.push_back({a,b});}
    for(int i=0;i<m;i++){
        scanf("%d %d",&a,&b);
        int tmp = link[a][b-1];
        dlink.push_back({a,tmp});
        link[a][b-1] = -1;
    }
    for(int i=1;i<=n;i++){
        if(link[i][0]>0)unionfn(i,link[i][0]);
        if(link[i][1]>0)unionfn(i,link[i][1]);
    }
    for(int i=m-1;i>=0;i--){
        int tmp1 = leader(dlink[i][0]), tmp2 = leader(dlink[i][1]);
        if(falltime[tmp1]!=FALLING&&falltime[tmp2]==FALLING){
            falltime[tmp2] = i;
        }else if(falltime[tmp2]!=FALLING&&falltime[tmp1]==FALLING){
            falltime[tmp1] = i;
        }
        else if(falltime[tmp2]==FALLING&&falltime[tmp1]==FALLING){unionfn(dlink[i][0],dlink[i][1]);}    
    }
    for(int i=1;i<=n;i++){
        if(falltime[i]==FALLING){
            int lead = leader(i);falltime[i] = falltime[lead];
        }
        printf("%d\n",falltime[i]);
    }
    return 0;
}