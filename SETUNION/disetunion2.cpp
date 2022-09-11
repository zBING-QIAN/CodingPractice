#include<bits/stdc++.h>
using namespace std;
vector<int>small,big,tot;
int leader(int a){
    if(small[a]!=a)small[a] = leader(small[a]);
    return small[a];
}


void unionfn(int a,int b){
    int tmp1 = leader(a),tmp2 = leader(b);
    if(tmp1 == tmp2)return;
    if(tmp1>tmp2)swap(tmp1,tmp2);
    small[tmp2] = tmp1;
    big[tmp1] = max(big[tmp1],big[tmp2]);
    tot[tmp1] +=tot[tmp2];
}


int main(){
    int n,m;
    cin>>n>>m;
    string op;
    int a,b;
    small.resize(n);big.resize(n);tot.resize(n);
    for(int i=0;i<n;i++)small[i] = i,big[i]=i,tot[i]=1;
    for(int i=0;i<m;i++){
        cin>>op;
        if(op == "union"){
            scanf("%d %d",&a,&b);a--,b--;
            unionfn(a,b);
        }else {
            scanf("%d",&a);a--;
            int tmp = leader(a);
            printf("%d %d %d\n",small[tmp]+1,big[tmp]+1,tot[tmp]);
        }
    }

    return 0;
}