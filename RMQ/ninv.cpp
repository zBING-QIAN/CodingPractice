#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,p;cin>>n>>m;for(p=1;p<n;p<<=1);
    vector<int> seg[41];for(int i=0;i<41;i++){seg[i].resize(2*p,0);}
    vector<int> arr(n),main_seg(2*p,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        seg[arr[i]][i+p] = 1;
    }
    for(int i=1;i<41;i++){for(int j  =p-1;j>0;j--){seg[i][j] = seg[i][j<<1]+seg[i][(j<<1)+1];}}
    for(int i=p-1;i>0;i--){
        main_seg[i] = main_seg[i<<1]+main_seg[(i<<1)+1];
        int tot = 0;
        for(int j = 2;j<41;j++){tot += seg[j-1][(i<<1)+1];main_seg[i] += tot*seg[j][i<<1];}
    }

    for(int i=0;i<m;i++){
        int op,a,b;
        cin>>op>>a>>b;
        if(op==1){
            //query
            a--;
            long long  ans=0;
            vector<int> count_L(41,0),count_R(41,0);
            for(a+=p-1,b+=p;a^b^1;a>>=1,b>>=1){
                if(~a&1){
                    ans+=main_seg[a^1];
                    long long  tot = 0;
                    for(int j = 2;j<41;j++){
                        tot+=seg[j-1][a^1];
                        ans+=tot*count_L[j];
                        count_L[j]+=seg[j][a^1];
                    }
                }
                if(b&1){
                    ans+=main_seg[b^1];
                    long long tot = 0;
                    for(int j=2;j<41;j++){
                        tot += count_R[j-1];
                        ans+=seg[j][b^1]*tot;
                        count_R[j-1]+=seg[j-1][b^1];
                    }
                    
                }
            }
            if(a^b){
                long long tot = 0;
                for(int j=2;j<41;j++){
                    //cout<<tot<<" "<<count_L[j]<<endl;
                    tot += count_R[j-1];
                    ans+=count_L[j]*tot;
                }
            }
            cout<<ans<<endl;

        }else {
            a--;
            int tmp = arr[a];arr[a] = b;
            for( int A = a+p;A;A>>=1){
                seg[tmp][A]--;seg[b][A]++;
            }
            for(int A=a+p;A^1;A>>=1){
                main_seg[A>>1] = main_seg[A] + main_seg[A^1];
                int tot = 0;
                for(int j = 2;j<41;j++){
                    tot+=seg[j-1][A|1];
                    main_seg[A>>1] += tot*seg[j][A-(A&1)];
                }   

            }
        }
    }
    return 0;
}