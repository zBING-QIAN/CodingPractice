#include<bits/stdc++.h>
using namespace std;

int main(){
     int N,p = 1;
    vector<int> seg(100005*4,0);
    cin>>N;
    for(;p<N;p<<=1);
    for(int i = 0;i<N;i++)seg[i+p] = 1;
    for(int i=p-1;i>0;i--)seg[i] = seg[i<<1]+seg[(i<<1)+1];
    vector<int> buf(N);
    for(int i = 0;i<N;i++)cin>>buf[i];
    for(int i=N-1;i>=0;i--){
        int tmp;
        tmp =1;
        int sum = 0;
        while(tmp<p){
            if(seg[tmp*2+1]>buf[i])tmp =2*tmp+1;
            else {buf[i]-=seg[tmp*2+1];tmp *= 2;}
        }

        buf[i] = tmp-p+1;


       
        while(tmp>0){seg[tmp]--;tmp>>=1;}
       
    }for(int i=0;i<N;i++)cout<<buf[i]<<" ";
    return 0;
}

