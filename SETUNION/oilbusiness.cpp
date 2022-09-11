#include<bits/stdc++.h>
using namespace std;
vector<int>team;
int leader(int a){
    if(team[a]!=a){
        team[a] = leader(team[a]);
    }return team[a];
}


int main(){
    long long n,m,s;cin>>n>>m>>s;
    vector<array<long long,4>> link;
    vector<bool> trim;trim.resize(m,1);
    long long a,b,v;
    team.resize(n+1);
    for(int i=0;i<=n;i++)team[i]=i;
    for(int i=0;i<m;i++){
        scanf("%lld %lld %lld",&a,&b,&v);
        link.push_back({a,b,v,i});
    }
    sort(link.begin(),link.end(),[](auto a,auto b){
        return a[2]<b[2];
    });
    for(int i=m-1;i>=0;i--){
        int t1 = leader(link[i][0]),t2 = leader(link[i][1]);
        if(t1 != t2){
            team[t1] = t2;trim[i] = 0;
        }
    }
    vector<int> ans;
    long long sum = 0;
    for(int i=0;i<m;i++){
        if(trim[i]){
            sum+=link[i][2];
            if(sum>s){break;}
            else ans.push_back(link[i][3]);
        }
    }
    
    sort(ans.begin(),ans.end());
    printf("%d\n",ans.size());
    for(auto out :ans){
        printf("%d ",out+1);
    }
    return 0;
}