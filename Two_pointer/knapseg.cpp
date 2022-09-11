#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;long long s;cin>>n>>s;
    vector<long long> w(n),c(n);
    for(int i=0;i<n;i++){
        scanf("%d",&w[i]);
    }
     for(int i=0;i<n;i++){
        scanf("%d",&c[i]);
    }
    long long sum=0,cost = 0,ans =0;
    for(int i=0,j=0;i<n;){
        while(sum+w[j]<=s){
            sum+=w[j];cost+=c[j];
            j++;
        }
        ans = max(ans,cost);
        if(j<n){
            if(i==j){sum = 0,cost=0,i++,j++;}
            else {sum-=w[i];cost-=c[i];i++;}
        }else break;
    }
    cout<<ans;
    return 0;
}