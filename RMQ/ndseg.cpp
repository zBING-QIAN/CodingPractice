#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,p;cin>>n>>m;
    for(p=1;p<n;p<<=1);
    vector<int> arr(n);
    vector<unsigned long long > seg(2*p,0);;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        seg[i+p]|= ((unsigned long long)1<<arr[i]);
    }
    for(int j=p-1;j;j--){
        seg[j] = seg[j<<1] | seg[(j<<1)^1];
    }
    for(int i=0;i<m;i++){
        int op,a,b;
        cin>>op>>a>>b;
        if(op==1){
            a--;
            unsigned long long  ans = 0;
            for(int A = a+p-1,B=b+p;A^B^1;A>>=1,B>>=1){
                if(~A&1){
                    ans |= seg[A^1];
                   
                }
                if(B&1){
                    ans|=seg[B^1];
                }
                
            }
            int tmp =0;for(;ans;ans>>=1)if(ans&1)tmp++;
            //int tmp =0;for(;ans>0;ans>>=1)if(ans&1)tmp++;
            cout<<tmp<<endl;
        }else{
            a--;
            int tmp = arr[a];arr[a] = b;
            
            seg[a+p]^=((unsigned long long)1<<tmp);
            seg[a+p]|=((unsigned long long) 1<<b);
            for(int A = a+p;A>1;A>>=1){
                seg[A>>1] = seg[A]|seg[A^1];
            }

        }
    }
    return 0;
}