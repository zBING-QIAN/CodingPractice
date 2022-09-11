#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;cin>>n>>k;
    vector<int> arr(n+1),rec(1e5+1,0);
    int sum =0;
    long long ans=0;
    for(int i=0;i<n;i++)scanf("%d",&arr[i]);
    for(int i=0,j=0;i<n;i++){
        while(j<n){
            if(rec[arr[j]]==0){
                if(sum==k)break;
                sum++;
            }
            rec[arr[j]]++;
            j++;
        }
        ans+=j-i;
        rec[arr[i]]--;
        if(rec[arr[i]]==0)sum--;
        
    }   
    cout<<ans; 
    return 0;
}