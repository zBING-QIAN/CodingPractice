#include<bits/stdc++.h>
using namespace std;
vector<int> team,sign;

int leader(int a){
    if(team[a] != a){int tmp = team[a];team[a] = leader(team[a]);sign[a] ^= sign[tmp];}
    return team[a];
}

int main(){
    int n,m;cin>>n>>m;
    team.resize(n+1),sign.resize(n+1);
    for(int i=0;i<=n;i++)sign[i] =0,team[i] =i;
    int op,a,b,shift=0;
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&op,&a,&b);
        if(op){
            if(leader((a+shift)%n)==leader((b+shift)%n)&&sign[(a+shift)%n]==sign[(b+shift)%n]){
                printf("YES\n");shift++;
            }else printf("NO\n");
        }else{
            int t1= leader((a+shift)%n),t2 = leader((b+shift)%n);
            if(sign[(a+shift)%n]^sign[(b+shift)%n]){
                team[t1] = t2;
            }else{
                team[t1] = t2;sign[t1] = 1;
            }
        }

    }


    return 0;
}