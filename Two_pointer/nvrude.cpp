#include<bits/stdc++.h>
using namespace std;

void callerr(){int a=2,b=4;cout<<a/(b-4);}


int main(){
    int n;long long c;cin>>n>>c;if(n==1){cout<<1;return 0;}
    string arr; cin>>arr;
    for(int i=0;i<n;i++)arr[i]-='a';
    int ans=1;
    long long rude = 0;
    long long num[2] = {0,0};
    for(int i=0,j=0;;){
        while(j<n){
            if(arr[j]<=1){
                if(arr[j])rude+=num[0];
                num[arr[j]]++;
            }j++;
            if(rude<=c){
                ans = max(j-i,ans);
            } 
            else break;
        }
        
        while(rude>c&&i<j){
            if(arr[i]<=1){
                if(arr[i]==0)rude-=num[1];
                num[arr[i]]--;
            }
            i++;
        }
        if(rude<=c)ans = max(ans,j-i);
        if(j==n)break;
        
    }
    cout<<ans;
    return 0;
}