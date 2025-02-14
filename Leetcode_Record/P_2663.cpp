#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    string smallestBeautifulString(string s, int k) {
        if(k<=2&&s.size()>k)return "";
        string ans = s;k--;
        for(int i =ans.size()-1;i>=0;i--){
            if(ans[i]-'a'==k){ans[i] = 'a';if(i==0)return "";}
            else {ans[i]++;break;}
        }//cout<<ans<<endl;
        for(int idx= 0;idx<ans.size();idx++){
            if((idx>0&&ans[idx]==ans[idx-1])||(idx>1&&ans[idx-2]==ans[idx])){
                while((idx>0&&ans[idx]==ans[idx-1])||(idx>1&&ans[idx-2]==ans[idx])){
                    while(ans[idx]=='a'+k){
                        if(idx==0)return "";
                        idx--;
                    }
                    ans[idx]++;
                }
                string tmp = "aaa";
                while(ans[idx] == tmp[0]||(idx>=1&&ans[idx-1]==tmp[0]))tmp[0]++;
                while(tmp[0] == tmp[1]||ans[idx]==tmp[1])tmp[1]++;
                while(tmp[0] == tmp[2]||tmp[1]==tmp[2])tmp[2]++;
                
                for(int i=idx+1,j=0;i<ans.size();i++){ans[i] = tmp[j];j = (j==2)?0:j+1;}
                return ans;
            }
        }
        return ans;
    }
};