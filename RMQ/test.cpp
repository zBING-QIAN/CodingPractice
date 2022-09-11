#include<bits/stdc++.h>
using namespace std;

int MAXN = 10,m = 1000;

int main(){
    srand(time(NULL));cout<<MAXN<<" "<<m<<endl;
    vector<int> arr(MAXN,0);
    for(int i=0;i<m;i++){
        int l,r,v,op;
        op = rand()%2;l = rand()%MAXN;r = rand()%MAXN;if(l>r)swap(l,r);v = rand()%100000;
         printf("%d %d %d %d\n",op+1,l,r,v);
        if(op==0){
            for(;l<=r;l++){
                if(arr[l]<v)arr[l] = v; 
            }
        }else{
            for(;l<=r;l++){
                if(arr[l]>v)arr[l] = v; 
            }
        }
    }
    for(int i=0;i<10;i++)cout<<endl;
    for(int i=0;i<MAXN;i++)cout<<arr[i]<<endl;

    return 0;
}