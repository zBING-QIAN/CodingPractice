#include<bits/stdc++.h>
using namespace std;
vector<int>exper,team;
int flag;
int SUMTMP;
int leader(int a){
    if(team[a] != a){team[a] = leader(team[a]);exper[a]+=SUMTMP;SUMTMP = exper[a];}
    else SUMTMP = 0;
    return team[a];
}
void unionfn(int a,int b){
    int tmp1 = leader(a),tmp2 = leader(b);
    if(tmp1!=tmp2)team[tmp1] = team[tmp2] = flag++;

}
void add(int a,int v){
    int tmp = leader(a);
    exper[tmp] += v;
}


int main(){
    int n,m;cin>>n>>m;
    string op;int a,b;
    flag = n;
    exper.resize(3*n,0);team.resize(3*n);
    for(int i=0;i<3*n;i++){
        team[i] = i;
    }
    for(int i=0;i<m;i++){
        cin>>op;
        if(op == "add"){
            scanf("%d %d",&a,&b);a--;add(a,b);
        }else if(op == "get"){
            scanf("%d",&a);a--;
            int lead = leader(a);
            if(lead == a)printf("%d\n",exper[lead]);
            else printf("%d\n",exper[a]+exper[lead]);
        }else if(op == "join"){
            scanf("%d %d",&a,&b);a--,b--;
            unionfn(a,b);
        }


    }

    return 0;
}