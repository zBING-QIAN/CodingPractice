#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long pre2n(int pre,int mid,bool use_mid){
        long long out = pre;
        if(use_mid){out*=10;out+=mid;}
        while(pre>0){
            out*=10;
            out+=pre%10;
            pre/=10;
        }
        return out;
    }

    string nearestPalindromic(string n) {
        int s = n.size(),half = n.size()>>1;
        long long ans_pre=0,ans_pos=0,ans_mid=0,n_pos=0;
        long long ten = 1,n_ll;
        if(s&1)ans_mid = n[half]-'0';
        for(int i=0;i<s;i++){n_ll*=10;n_ll+=n[i]-'0';}
        for(int i=0;i<half;i++){
            ans_pre=ans_pre*10+(n[i]-'0');
            ans_pos=(n[i]-'0')*ten+ans_pos;
            n_pos =(n[s-i-1]-'0')*ten+n_pos;
            ten*=10;
        }
        long long larger,smaller;
            cout<<n_pos<<" "<<ans_pos<<endl;
        if(n_pos > ans_pos){
            if(s&1){
                smaller = (ans_pre*10+ans_mid)*ten+ans_pos;
                if(ans_mid==9)larger = pre2n(ans_pre+1,0,(ans_pre+1)==ten);
                else larger = pre2n(ans_pre,ans_mid+1,1);
            }else {
                smaller = ans_pre*ten+ans_pos;
                if(ans_pre+1==ten)larger = pre2n((ans_pre+1)/10,0,(ans_pre+1)==ten);
                else larger = pre2n(ans_pre+1,0,0);
            }
        }else if(n_pos<ans_pos){
            if(s&1){
                larger = (ans_pre*10+ans_mid)*ten+ans_pos;
                if(ans_mid==0&&(ans_pre-1)*10>=ten)smaller = pre2n(ans_pre-1,9,1);
                else if(ans_mid==0)smaller = pre2n((ans_pre-1)*10+9,0,0);
                else smaller = pre2n(ans_pre,ans_mid-1,1);
            }else {
                larger = ans_pre*ten+ans_pos;
                smaller = pre2n(ans_pre-1,9,(ans_pre*10)==ten); 
            }
        }else {
            if(s&1){
                if(ans_mid==0&&(ans_pre-1)*10>=ten)smaller = pre2n(ans_pre-1,9,1);
                else if(ans_mid==0)smaller = pre2n((ans_pre-1)*10+9,0,0);
                else smaller = pre2n(ans_pre,ans_mid-1,1);
                if(ans_mid==9)larger = pre2n(ans_pre+1,0,(ans_pre+1)!=ten);
                else larger = pre2n(ans_pre,ans_mid+1,1);
            }else {
                smaller = pre2n(ans_pre-1,9,(ans_pre*10)==ten);
                if(ans_pre+1==ten)larger = pre2n((ans_pre+1)/10,0,(ans_pre+1)==ten);
                else larger = pre2n(ans_pre+1,0,0);
            }
        }
        return (larger-n_ll<n_ll-smaller)?to_string(larger):to_string(smaller);
    }
};