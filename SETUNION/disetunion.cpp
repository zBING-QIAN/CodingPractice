#include<bits/stdc++.h>
using namespace std;
vector<int>rec;
int leader(int a){
    if(rec[a]!=a)rec[a] = leader(rec[a]);
    return rec[a];
}


void unionfn(int a,int b){
    int tmp1 = leader(a),tmp2 = leader(b);
    rec[tmp1] = rec[tmp2];
}


int main(){
    int n,m;
    cin>>n>>m;
    string op;
    int a,b;
    rec.resize(n);
    for(int i=0;i<n;i++)rec[i] = i;
    for(int i=0;i<m;i++){
        cin>>op>>a>>b;a--,b--;
        if(op == "union"){
            unionfn(a,b);
        }else {
            if(leader(a) == leader(b))cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }

    return 0;
}