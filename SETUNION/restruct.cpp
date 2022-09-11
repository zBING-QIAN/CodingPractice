#include<bits/stdc++.h>
using namespace std;
vector<int> arr;
vector<int> team;
int lead(int a){
    if(arr[a]!=a){
        arr[a] = lead(arr[a]);
    }
    return arr[a];
}
int leader(int a){
    if(team[a]!=a){
        team[a] = leader(team[a]);
    }
    return team[a];
}
void showError(){
    int a=0;
    cout<<1/a;
}
void unionfn(int a,int b){
    int t1=leader(lead(a)),t2=leader(lead(b));
    if(t1!=t2){
        team[t1] = t2;
    }
}
void uniongp(int from,int to){
    int loa = lead(to);
    int lot = leader(loa);
    for(int i=from;i<=to;i++){
        int tmp = lead(i);
        i = tmp;
        team[leader(tmp)] = lot;
        arr[tmp] = loa;
    }
}


int main(){
    int n,m;cin>>n>>m;
    int op,a,b;
    team.resize(n);
    arr.resize(n);
    for(int i=0;i<n;i++)arr[i]=team[i]=i;
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&op,&a,&b);
        a--,b--;
        if(op==1){
            unionfn(a,b);
        }else if(op==2){
            uniongp(a,b);
        }else{
            if(leader(lead(a))==leader(lead(b)))printf("YES\n");
            else printf("NO\n");
        }

    }

    return 0;
}