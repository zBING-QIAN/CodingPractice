#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;long long s;cin>>n>>s;
    vector<long long> arr(n);
    long long ans=0;
    for(int i=0;i<n;i++){
        scanf("%lld",&arr[i]);
    }
    long long sum=0,tmp;
    for(int i=0,j=0;i<n;){
        if(i==j){sum = arr[i];j++;}
        while(sum<=s){
            tmp = j-i;
            ans+=(tmp*(tmp+1))/2;//cout<<"i j "<<i<<" "<<j<<" "<<(tmp*(tmp+1))/2<<endl;
            if(j==n){cout<<ans;return 0;}
            sum+=arr[j];
            j++;
        }
        while(sum>s){
            sum-=arr[i];
            if(i==j)break;
            i++;
        }
    }
    cout<<ans;
    return 0;
}