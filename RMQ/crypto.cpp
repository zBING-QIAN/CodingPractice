#include<bits/stdc++.h>
using namespace std;




int main(){
    int r,n,m,p;cin>>r>>n>>m;for(p=1;p<n;p<<=1);
   
    vector<vector<int>> seg(2*p,vector<int>(4,0));
    vector<bool> aux(2*p,0);
    for(int i=0;i<n;i++){
        int tmp;
        for(int j= 0;j<4;j++){scanf("%d",&tmp);seg[i+p][j] = tmp%r;}
        aux[i+p] = !(seg[i+p][0] || seg[i+p][1]|| seg[i+p][2] ||seg[i+p][3]);
    }
    for(int i=p-1;i>0;i--){
        aux[i] = aux[(i<<1)] || aux[(i<<1)+1];
        if(!aux[i]){
            seg[i][0] = (seg[(i<<1)][0]*seg[(i<<1)+1][0]+seg[(i<<1)][1]*seg[(i<<1)+1][2])%r;
            seg[i][1] = (seg[(i<<1)][0]*seg[(i<<1)+1][1]+seg[(i<<1)][1]*seg[(i<<1)+1][3])%r;
            seg[i][2] = (seg[(i<<1)][2]*seg[(i<<1)+1][0]+seg[(i<<1)][3]*seg[(i<<1)+1][2])%r;
            seg[i][3] = (seg[(i<<1)][2]*seg[(i<<1)+1][1]+seg[(i<<1)][3]*seg[(i<<1)+1][3])%r;
            aux[i] = !(seg[i][0] || seg[i][1]|| seg[i][2] ||seg[i][3]);
        }
    }
    // cout<<" seg :  "; for(int i=1;i<2*p;i++){
    //     cout<<seg[i][0]<<" "<<seg[i][1]<<endl<<seg[i][2]<<" "<<seg[i][3]<<endl<<endl;

    // }
    for(int i=0;i<m;i++){
        int a,b;
        bool zero = false;
        scanf("%d %d",&a,&b);
        int ansl[4];ansl[0] = 1,ansl[3] = 1;ansl[1] = 0,ansl[2] = 0;
        int ansr[4];ansr[0] = 1,ansr[3] = 1;ansr[1] = 0,ansr[2] = 0;
        for(a+=p-2,b+=p;a^b^1;a>>=1,b>>=1){
            if(~a&1){
                if(aux[a^1]){zero = true;break;}
                int tmp0 = (ansl[0]*seg[a^1][0]+ansl[1]*seg[a^1][2])%r;
                int tmp1 = (ansl[0]*seg[a^1][1]+ansl[1]*seg[a^1][3])%r;
                int tmp2 = (ansl[2]*seg[a^1][0]+ansl[3]*seg[a^1][2])%r;
                int tmp3 = (ansl[2]*seg[a^1][1]+ansl[3]*seg[a^1][3])%r;
                ansl[0] = tmp0;
                ansl[1] = tmp1;
                ansl[2] = tmp2;
                ansl[3] = tmp3;
                if(!(ansl[0]||ansl[1]||ansl[2]||ansl[3])){zero = true;break;}
            }
            if(b&1){
                 if(aux[b^1]){zero = true;break;}
                int tmp0 = (seg[b^1][0]*ansr[0]+seg[b^1][1]*ansr[2])%r;
                int tmp1 = (seg[b^1][0]*ansr[1]+seg[b^1][1]*ansr[3])%r;
                int tmp2 = (seg[b^1][2]*ansr[0]+seg[b^1][3]*ansr[2])%r;
                int tmp3 = (seg[b^1][2]*ansr[1]+seg[b^1][3]*ansr[3])%r;
                ansr[0] = tmp0;
                ansr[1] = tmp1;
                ansr[2] = tmp2;
                ansr[3] = tmp3;
                if(!(ansr[0]||ansr[1]||ansr[2]||ansr[3])){zero = true;break;}
            }
        }
        if(zero){
            cout<<"0 0\n0 0\n\n";
        }else {
            int tmp0 = ((ansl[0]*ansr[0]+ansl[1]*ansr[2])%r);
            int tmp1 = ((ansl[0]*ansr[1]+ansl[1]*ansr[3])%r);
            int tmp2 = ((ansl[2]*ansr[0]+ansl[3]*ansr[2])%r);
            int tmp3 = ((ansl[2]*ansr[1]+ansl[3]*ansr[3])%r);
            printf("%d %d\n%d %d\n\n",tmp0,tmp1,tmp2,tmp3);
        }
    }

    return 0 ;
}