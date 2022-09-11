#include<bits/stdc++.h>
using namespace std;

int searchbig(vector<int> &arr,int v){
    int l = 0,r = arr.size()-1;
    while(l<r){
        int mid = (l+r)>>1;
        if(v>=arr[mid])l = mid+1;
        else r = mid;
    }
    return  l;
}
int searchsmall(vector<int> &arr,int v){
    int l = 0,r = arr.size()-1;
    while(l<r){
        int mid = (l+r)>>1;
        if(v>arr[mid])l = mid+1;
        else r = mid;
    }
    return  l;

}

int main(){
    int n,k;cin>>n;
    vector<int> arr(n+2);arr[0] = -1e9-10;arr[n+1] = 1e9+10;
    for(int i=1;i<=n;i++)cin>>arr[i];
    sort(arr.begin(),arr.end());
    cin>>k;
    for(int i=0;i<k;i++){
        int l,r;cin>>l>>r;
        cout<<searchbig(arr,r)-searchsmall(arr,l)<<endl;

    }

    return 0;
}