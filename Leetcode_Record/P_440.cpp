#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ans = 0;
    int first_bit=1;
    void run(int n,int k,int bits){
        if(bits==0)return ;
        int cnt = 0,i=1;      
        ans*=10;  
        for(int b=1;b<bits;b++,i*=10){
            cnt+=i;
        }
        
        int cnt_tmp = cnt,sum = 0;
        for(int j=first_bit;j<10;j++){
            if(i*(j+1)>n){
                cnt_tmp = cnt;
                if(i*j<=n)cnt_tmp+=n-i*j+1;
            }else {
                cnt_tmp = i+cnt;
            }
            if(cnt_tmp+sum>=k){
                ans+=j;//cout<<j<<" "<<ans<<" "<<n<<" "<<k<<" "<<sum<<" "<<cnt_tmp<<endl;
                first_bit=0;
                int n_tmp = cnt_tmp-cnt-1;
                if(n_tmp<0){bits--;n_tmp+=i/10;}
                if(k-sum-1)run(n_tmp,k-sum-1,bits-1);
                return;
            }
            sum+=cnt_tmp;
            
        }


        
    }
    int findKthNumber(int n, int k) {
        int b=0;for(int i=1;i<=n;i*=10)b++;
        run(n,k,b);
        return ans;
    }
};