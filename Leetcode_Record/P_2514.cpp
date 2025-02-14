#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> prime;
    vector<int> check;
    vector<int> skip;
    void setup(){
        vector<bool> is_prime(1e5+5,1);
        for(int i=2;i*i<1e5+3;i++){
            if(is_prime[i]){for(int j=i;j*i<1e5+3;j++)is_prime[i*j]=0;}
        }
        for(int i=2;i<1e5+3;i++){
            if(is_prime[i]){
                prime.push_back(i);
                for(long long k=i;k<1e5+3;k*=i)check.push_back(k);
                while(skip.size()<check.size())skip.push_back(check.size());
            }
        }
    }
    vector<int> bar(int n){
        vector<int> out;
        for(int i=0,sum=0;i<check.size();){
            int tmp = n/check[i];
            sum += tmp;
            // cout<<"n checki sum "<<n<<" "<<check[i]<<" "<<sum<<endl;
            if(skip[i]!=skip[i+1]||tmp==0){
                out.push_back(sum);sum=0;//cout<<"check bar "<<check[i]<<endl;
                if(check[skip[i]]>n)break;
                i=skip[i];
            }else i++;
        }
        return out;
    }
    int exp(long long e,int n,long long mod){
        long long out = 1;
        for(int k=n;k>0;k>>=1,e=(e*e)%mod){
            if(k&1)out = (out*e)%mod;
        }
        return int(out);
    }

    int countAnagrams(string s) {
        setup();
        vector<string> arr;
        long long mod = 1e9+7;
        for(int i=0;i<s.size();){
            size_t p = s.find(' ',i);
            if(p==string::npos){
                p = s.size();
            }
            arr.push_back(s.substr(i,p-i));
            i = p+1;
        }
        long long ans=1;
        for(auto &s:arr){
            if(s.size()<=1)continue;
            vector<long long> rec(26,0);
            long long tmp = 1;
            vector<int> sbar = bar(s.size());
            for(int i=0;i<s.size();i++){
                rec[s[i]-'a']++;
            }
            // cout<<s<<endl;
            for(int i=0;i<26;i++){
                vector<int> bar_tmp = bar(rec[i]);
                for(int j=0;j<bar_tmp.size();j++){
                    sbar[j] -= bar_tmp[j];
                    // cout<<j<<" "<<bar_tmp[j]<<" "<<sbar[j]<<endl;
                    assert(sbar[j]>=0);
                }
            }
            for(int i=0;i<sbar.size();i++){
                // cout<<sbar[i]<<endl;
                if(sbar[i])tmp = (tmp*exp(prime[i],sbar[i],mod))%mod;
                // if(sbar[i])cout<<exp(prime[i],sbar[i],mod)<<endl;
            }
            ans = (ans*tmp)%mod;
        }


        return ans;
    }
};