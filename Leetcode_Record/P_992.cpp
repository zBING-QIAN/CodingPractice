#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        vector<int> next(A.size()),rep(A.size(),0),pre(A.size()+1,-1);
      //  map<int,int> pre;
        int len=A.size();
        for(int i=0;i<len;i++){
            next[i]=pre[A[i]];
            pre[A[i]]=i;
        }
        int cnt=0,sa=len,ea=0,ans=0;
        for(int i=len-1,j=len-1;j>=0&&i>=0;){
            if(next[j]>=0)rep[next[j]]=-1;
            cnt+=rep[j]+1;
            if(cnt==K&&sa==len){
               sa=j;
            }
            if(cnt>K){
                ea=j+1;
                for(;i>=0;i--){
                   if(next[i]>=0) rep[next[i]]=0;
                    ans+=sa-ea+1;
                    if(next[i]>=ea){
                        sa=min(next[i],sa);
                    }
                    else {
                        cnt--;i--;
                        sa=j;
                        break;
                    }
                }
            }
            if(cnt==K&&j==0){
                ea=0;
                for(;i>=0;i--){
                    if(next[i]>=0) rep[next[i]]=0;
                    ans+=sa-ea+1;
                    if(next[i]>=ea){
                        sa=min(next[i],sa);
                    }
                    else {
                        break;
                    }
                }
                
            }
            j--;
            
        }
        return ans;
    }
};