#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> rec(256,0),orig(256,0);
        for(auto &c:t){
            orig[c]++;
        }
        int cnt = 0,ans = 0,ans_len=1e9;
        for(int i=0,j=0;j<s.size();j++){
            if(orig[s[j]]>0){
                if(rec[s[j]]<orig[s[j]])cnt++;
                rec[s[j]]++;
                while(cnt==t.size()){
                    if(j-i+1<ans_len){ans = i,ans_len = j-i+1;}
                    if(orig[s[i]]>0){
                        rec[s[i]]--;
                        if(orig[s[i]]>rec[s[i]]){
                           cnt--;
                        }
                    }
                    i++;
                }
                
            }
            
        }
        
        if(ans_len>s.size()){
            return "";
        }
        else{
            return s.substr(ans,ans_len);    
        }
        
    }
};
                          