#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int K;
    long long dp[11][11][20],dp0[11][11][20];
    int solve(int a){
        int msb =1;for(long long i=10;i<=a;i*=10,msb++);
        int ans = 0;
        if(msb&1){
            msb--;
            for(;msb;msb-=2){
                ans+=dp[msb][msb>>1][0];//cout<<ans<<endl;
            }
            return ans;
        }else{
            for(int msb_tmp=msb-2;msb_tmp;msb_tmp-=2){
                ans+=dp[msb_tmp][msb_tmp>>1][0];
            }
            int cnt_0=0,cnt_1=0,prefix=0,total_digit=msb;
            long long cur=1;
            for(;cur*10<=a;cur*=10);prefix = cur;
            while(msb){
                // cout<<msb<<" "<<prefix<<" "<<cur<<endl;
                int d = (a/cur)%10;
                
                for(int t=(prefix==cur);t<d;t++,prefix+=cur){
                    int div = prefix%K;
                    int cnt_1_tmp =(total_digit>>1)- (cnt_1+(t&1));
                    // cout<<cnt_1_tmp<<endl;
                    if(cnt_1_tmp>=0){
                        ans+= dp0[msb-1][cnt_1_tmp][(K-div)%K];
                    }
                }

                cur/=10;msb--;cnt_0+=(~d&1);cnt_1+=(d&1);
            }

        }
        return ans;
    }    


    int numberOfBeautifulIntegers(int low, int high, int k) {
        K=k;
        for(int i=0;i<11;i++)for(int j=0;j<11;j++)for(int t=0;t<k;t++){dp[i][j][t]=0;dp0[i][j][t]=0;}
        for(int t=1;t<10;t++)dp[1][t&1][t%k]++;
        for(int t=0;t<10;t++)dp0[1][t&1][t%k]++;dp0[0][0][0]=1;
        for(int i=1;i<10;i++){
            for(int j=0;j<=i;j++){
                for(int f=0;f<k;f++){
                    for(int t=0;t<10;t++){
                        if((t&1)){
                            dp[i+1][j+1][(f*10+t)%k] += dp[i][j][f];
                            dp0[i+1][j+1][(f*10+t)%k] += dp0[i][j][f];
                        }
                        if(~t&1){
                            dp[i+1][j][(f*10+t)%k] += dp[i][j][f];
                            dp0[i+1][j][(f*10+t)%k] += dp0[i][j][f];
                        }
                    }
                }
            }
        }
        return solve(high+1)-solve(low);
    }
};