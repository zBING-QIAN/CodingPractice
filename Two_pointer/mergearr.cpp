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
    vector<int> ans;
    for(int i=0,j=0;i<n||j<m;){
        if(i==n||(j<m&&a[i]>b[j])){ans.push_back(b[j]);j++;}
        if(j==m||(i<n&&a[i]<=b[j])){ans.push_back(a[i]);i++;}
    }
    for(int i=0;i<n+m;i++)printf("%d ",ans[i]);
    return 0;
}