#include<vector>
#include<iostream>
using namespace std;
#define LOWBIT(a) (a&-a)
vector<long long> BIT;
vector<int> arr;

int m,n;
    
void add(int p,int v){
    while(p<=m){
        BIT[p]+=v;
        p+=LOWBIT(p);
    }
}
void build(){
    for(int i=1;i<arr.size();i++){
        add(i,arr[i]);
    }

}
void build_v2(){
    long long total = 0;
    for(int i=1;i<arr.size();i++){
        total+=arr[i];
        int tmp = i - LOWBIT(i);
        BIT[i] = total;
        while(tmp>0){
            BIT[i]-=BIT[tmp];
            tmp -= LOWBIT(tmp);
        }
    }

}
long long  sum(int a){
    long long  ans= 0;
    while(a>0){
        ans+=BIT[a];
        a-=LOWBIT(a); 
    }
    return ans;
}


long long query(int l,int r){
    return sum(r)-sum(l);
}
int main(){
    cin>>m>>n;
    BIT.resize(m+1,0);arr.resize(m+1,0);
    for(int i=1;i<=m;i++){
        cin>>arr[i];
    }
    build_v2();
    for(int i=0;i<n;i++){
        int op,a,v;
        cin>>op>>a>>v;
        if(op==1){
            a++;
            add(a,v-arr[a]);
            arr[a] = v;
        }else{
            cout<<query(a,v)<<endl;
        }
    }
}