#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    int longestValidParentheses(string s) {
        vector<int> stac(s.size()*2,-1),record(s.size(),-1);
        int flag=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){ 
                flag++;
                stac[flag]=i;             
            }
            else{
                if(flag==0)continue;
                record[i]=stac[flag];
                flag--;
            }
        }
        int Max=0,tmp=0;
        for(int i=s.size()-1;i>=0;i--){
           if(record[i]>=0){
               tmp=tmp+i-record[i]+1;
               i=record[i];
               Max=max(Max,tmp);
           }
            else {
               
                tmp=0;
             }
        }
        return Max;
    }
};