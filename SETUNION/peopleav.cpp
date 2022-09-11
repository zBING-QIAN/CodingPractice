#include<bits/stdc++.h>
using namespace std;
vector<int> rec;

int findright(int a){if(rec[a]!=a)rec[a] = findright(rec[a]);return rec[a];}

int main(){
    int n,m;
    cin>>n>>m;
    char op[2];int a;
    rec.resize(n+2);
    for(int i=0;i<n+2;i++)rec[i] = i;
    for(int i=0;i<m;i++){
        scanf("%s %d",op,&a);
        // cin>>op>>a;
        if(op[0] == '?'){
            int ans = findright(a);
            if(ans<=n){printf("%d\n",ans);}
            else printf("-1\n");
        }else if(op[0] == '-'){
            rec[a] = findright(a+1);
        }
    }

    return 0;
}