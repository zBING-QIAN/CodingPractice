#include<bits/stdc++.h>
using namespace std;
vector<int>team;


int leader(int a){
    if(team[a]!=a){team[a] = leader(team[a]);}
    return team[a];
}
void unionfn(int a,int b){
    int t1 =  leader(a),t2 = leader(b);
    if(t1 != t2)team[t1] = t2;
}
int main(){
    int n,m,k;cin>>n>>m>>k;
    int a,b;
    team.resize(n+1);
    for(int i=0;i<n+1;i++)team[i]=i;
    for(int i=0;i<m;i++){
        scanf("%d %d",&a,&b);
    }
    string op;
    vector<array<int,3>> task;
    for(int i=0;i<k;i++){
        cin>>op;scanf("%d %d",&a,&b);
        if(op=="cut"){
            task.push_back({0,a,b});
        }else {
            task.push_back({1,a,b});
        }
    }
    
    vector<string> anslist;
    for(int i=k-1;i>=0;i--){
        if(task[i][0]){
            if(leader(task[i][1])==leader(task[i][2]))anslist.push_back("YES\n");
            else anslist.push_back("NO\n");
        }else{
            unionfn(task[i][1],task[i][2]);
        }

    }
    string ans;
    for(int i=anslist.size()-1;i>=0;i--){
        ans += anslist[i];
    }
    cout<<ans;
    return 0;
}