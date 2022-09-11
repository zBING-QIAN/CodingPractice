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
    long long ans = 0;
    long long start_a = 0,start_b = 0;
    for(long long i=0,j=0;i<n;){
        while(j<m&&a[i]>b[j]){j++;}
        if(a[i]==b[j]){
            start_a = i;
            start_b = j;
            for(;b[j]==b[start_b]&&j<m;j++);    
            for(;a[i]==a[start_a]&&i<n;i++);
            ans += (i-start_a)*(j-start_b);    
        }else i++;
    }
    cout<<ans;
    return 0;
}