#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,a,b;
    cin>>n>>a>>b;if(a<b)swap(a,b);
    if(n == 1)cout<<b;
    else {
        n-=1;
        long long  r = b*n,l = 0;
        while(l<r){
            long long  mid = (long long )(l+r)>>1;
            long long tmp = mid/a+mid/b;
            if(tmp>=n)r = mid;
            else l = mid+1;
        }
        cout<<l+b;
    }

    return 0;
}