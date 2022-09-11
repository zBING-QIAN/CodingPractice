#include<bits/stdc++.h>
using namespace std;
vector<int> arr;
int leader(int a){
    if(arr[a]!=a)arr[a] = leader(arr[a]);
    return arr[a];
}

int main(){
    int n;cin>>n;
    int tmp;
    arr.resize(n+1);
    for(int i=1;i<=n;i++){
        arr[i] = i;
    }
    for(int i=0;i<n;i++){
        scanf("%d",&tmp);
        int a = leader(tmp);printf("%d ",a);
        if(a==n){
            arr[n] = leader(1);
        }else {
            arr[a] = leader(a+1);
        }
    }

    return 0;
}