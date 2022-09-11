#include<bits/stdc++.h>
using namespace std;
vector<int> seg_count,seg_min;
int m,n,p;
void modify(int a,int v){
    int c = 1;
    for( a+=p;a;a>>=1){
        seg_min[a] = v;seg_count[a] = c;
        if(seg_min[a]>seg_min[a^1]){
            v= seg_min[a^1];c = seg_count[a^1];
        }
        else if(seg_min[a]==seg_min[a^1]){
            c += seg_count[a^1];
        }
    }
}
void query(int a,int b){
    int ans_min=1e9,ans_count=0;
    for(a+=p-1,b+=p+1;a^b^1;a>>=1,b>>=1){
        if(~a&1){
            if(ans_min > seg_min[a^1]){
                ans_min = seg_min[a^1];
                ans_count = seg_count[a^1];
            }else if(ans_min == seg_min[a^1]){
                ans_count += seg_count[a^1];
            }
        }
        if(b&1){
             if(ans_min > seg_min[b^1]){
                ans_min = seg_min[b^1];
                ans_count = seg_count[b^1];
            }else if(ans_min == seg_min[b^1]){
                ans_count += seg_count[b^1];
            }
        }
    }
    cout<<ans_min<<" "<<ans_count<<endl;
}




int main(){
    cin>>m>>n;
    for(p=1;p<m;p<<=1);
    seg_count.resize(p*2+5,0);seg_min.resize(p*2+5,1e9+5);
    for(int i=0;i<m;i++){
        cin>>seg_min[p+i];
        seg_count[p+i]=1;
    }
    for(int i = p-1;i;i--){
        int tmp = i*2;
        seg_min[i] = seg_min[tmp];seg_count[i]=seg_count[tmp];
        if(seg_min[tmp]==seg_min[tmp+1]){
            seg_count[i]+=seg_count[tmp+1];
        }
        else if(seg_min[tmp]>seg_min[tmp+1]){
                seg_min[i] = seg_min[tmp+1];
                seg_count[i]=seg_count[tmp+1];
        }
    }
    for(int i = 0; i<n;i++){
        int op,a,b;
        cin>>op>>a>>b;
        if(op==1){
            modify(a,b);
        }else {
            query(a,b-1);
        }
    }
    return 0;
}