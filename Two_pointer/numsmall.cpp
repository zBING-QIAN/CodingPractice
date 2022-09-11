#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;cin>>n>>m;
    vector<int> a(n),b(m);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<m;i++){
        scanf("%d",&b[i]);
    }
    vector<int> ans(m,-1);
    for(int i=0,j=0;i<n||j<m;){
        if(i==n||(j<m&&a[i]>=b[j])){if(ans[j]==-1){ans[j] = i;printf("%d ",ans[j]);}j++;}
        if(j==m||(i<n&&a[i]<b[j])){i++;}
    }
    if( ans[m-1]==-1)printf("%d",n);
    return 0;
}