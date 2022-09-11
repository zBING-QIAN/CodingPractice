#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;long long s,A,B;cin>>n>>m>>s>>A>>B;
    vector<long long> arrA(n),arrB(m);
    for(int i=0;i<n;i++){
        scanf("%lld",&arrA[i]);
    }
    for(int i=0;i<m;i++){
        scanf("%lld",&arrB[i]);
    }
    sort(arrA.begin(),arrA.end(),[](auto a,auto b){return a>b;});
    sort(arrB.begin(),arrB.end(),[](auto a,auto b){return a>b;});
    long long ans=0,sum=0,cost= 0;
    int Aidx = min(n,(int)(s/A));sum = A*Aidx; 
    for(int i=0;i<Aidx;i++){cost += arrA[i];}
    int Bidx = min(m,(int)((s-sum)/B));sum+=B*Bidx;
    for(int i=0;i<Bidx;i++){cost += arrB[i];}
    ans = cost;//cout<<"Aidx "<<Aidx<<" Bidx "<<Bidx<<"first ans "<<ans<<endl;
    for(int i=Aidx-1,j=Bidx;i>=0&&j<m;i--){
        cost-=arrA[i];sum-=A;
        while(j<m&&sum+B<=s){
            sum+=B;cost+=arrB[j];j++;
        }
        ans = max(ans,cost);
    }
    cout<<ans;
    return 0;
}