#include<bits/stdc++.h>
using namespace std;
vector<int>boss;
vector<int>depth;
int dep_tmp;
int leader(int a){
    if(a!=boss[a]){boss[a] = leader(boss[a]);depth[a]+=dep_tmp;}
    dep_tmp = depth[a];
    return boss[a];
}
void unionfn(int a,int b){
    int t1 = leader(a),t2 = leader(b);
    boss[t1] = t2;depth[t1] = depth[t2] +1;
}

int main(){
    int n,m;
    cin>>n>>m;
    boss.resize(n);depth.resize(n,0);//dtmp.resize(n,0);
    for(int i=0;i<n;i++)boss[i]=i;
    int op,a,b;
    for(int i=0;i<m;i++){
        scanf("%d ",&op);
        if(op==1){
            scanf("%d %d",&a,&b);a--,b--;
            unionfn(a,b);
        }else{
            scanf("%d",&a);a--;
            leader(a);printf("%d\n",depth[a]);
        }

    }
    return 0;
}