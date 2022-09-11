#include<bits/stdc++.h>
using namespace std;
vector<int> team,sign;
int leader(int a){
    if(a!=team[a]){
        int tmp = team[a];
        team[a] = leader(team[a]);sign[a] ^= sign[tmp];
    }
    return team[a];
}
int main(){
    int m,n;cin>>n>>m;
    int a,b,ans = -1;
    team.resize(n+1);sign.resize(n+1,0);
    for(int i=0;i<=n;i++)team[i] = i;
    for(int i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        if(ans == -1){
            int t1= leader(a),t2 = leader(b);
            if(t1!=t2){
                if(sign[a]==sign[b])sign[t1] = 1;
                team[t1] = t2;
            }else {
                if(sign[a]==sign[b])ans = i;
            }
        }
    }
    
    cout<<ans;
    return 0;
}