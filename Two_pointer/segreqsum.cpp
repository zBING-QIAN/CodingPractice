#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,s;cin>>n>>s;
    vector<int> arr(n),rec(s+5,-1);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int ans = 1e9;
    for(int i=0;i<n;i++){
        
        for(int j=s;j>arr[i];j--){
            if(rec[j-arr[i]]!=-1){//cout<<"i "<<i<<" value "<<j<<" pre "<<rec[j]<<" "<<rec[j-arr[i]]<<endl;
                rec[j] = max(rec[j],rec[j-arr[i]]);
            }
        }rec[0] = rec[arr[i]] = i;
        if(rec[s]!=-1)ans = min(ans,i-rec[s]+1);
    }
    if(ans == 1e9)cout<<-1;
    else cout<<ans;
    return 0;
}