#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string shortestPalindrome(string s) {
        if(s.size()==0)return "";
        vector<int> dp0(s.size(),0),dp1(s.size(),0);
        int l0=0,l1=0;
        for(int i=0,c = 0,cd =0;i<s.size();i++){
            if(i-c>cd){c=i;cd=0;}
            int d = i-c;

            if(dp0[c-d]+i>=c+cd){
                cd = c+cd-i;
                c = i;
                while(c+cd<s.size()&&(c-cd)>=0&&s[c+cd]==s[c-cd]){cd++;}
                cd--;
                dp0[i] = max(0,cd);
                if(cd ==i)l0 = i;
            }else {
                dp0[i]=dp0[c-d];
            }
        }
        if(s.size()>1&&s[0]==s[1])dp1[0]=1;
        for(int i=1,c = 0,cd =0;i<s.size();i++){
            if(i>=cd+c-1){c=i;cd=0;}
            int d = i-c;
            if(dp1[c-d-1]+i>=c+cd-1){
                cd = c+cd-i;c = i;
                while(c+cd<s.size()&&(c-cd-1)>=0&&s[c+cd]==s[c-cd-1]){cd++;}
                if(cd ==i)l1 = cd;
                dp1[i] = max(0,cd);
            }else{
                dp1[i]=dp1[c-d-1];
            }
        }
        string ans="";
        if(l0>=l1){
            cout<<l0<<" "<<l1<<endl;
            ans= s.substr(l0*2+1);
            reverse(ans.begin(),ans.end());ans += s;
        }else{
            cout<<l0<<" "<<l1<<endl;
            ans= s.substr(l1*2);
            reverse(ans.begin(),ans.end());ans += s;
        }
        return ans;
    }
};