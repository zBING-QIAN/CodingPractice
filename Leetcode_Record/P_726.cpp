#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    inline bool isUpper(char c){return c>='A'&&c<='Z';}

    inline bool isLower(char c){return c>='a'&&c<='z';}

    inline bool isNum(char c){return c>='0'&&c<='9';}

    string readElement(string &f,int &l){
        string out ;out +=f[l++];
        for(;l<f.size();l++){
            if(isLower(f[l])){out+=f[l];}
            else break;
        }
        return out;
    }

    int readNum(string &f,int &l){
        int n = f[l++]-'0';
        for(;l<f.size();l++){
            if(isNum(f[l])){n*=10;n+= (f[l]-'0');}
            else break;
        }
        return n;
    }

    map<string,int> parse(string &f,int &l){
        map<string,int> rec;
        for(;l<f.size();){
            if(f[l]=='('){
                auto tmp = parse(f,++l);
                int cnt =1;
                if(isNum(f[l])){
                    cnt= readNum(f,l);
                }
                for(auto &[k,v]:tmp){rec[k]+=v*cnt;}
            }else if(f[l]==')'){
                l++;return rec;
            }else if(isUpper(f[l])){
                string ele=readElement(f,l);
                int cnt =1;
                if(isNum(f[l])){
                    cnt= readNum(f,l);
                }
                rec[ele]+=cnt;
            }else if(isLower(f[l])){
                assert(0);
            }else if(isNum(f[l])){
                assert(0);
            }else assert(0);

        }
        return rec;
    }

    string countOfAtoms(string formula) {
        int l =0;
        auto out = parse(formula,l);
        string ans = "";
        for(auto &[k,v]:out){
            ans+=k+((v==1)?"":to_string(v));
        }
        return ans;
    }
};