#include<bits/stdc++.h>
using namespace std;

void callerr(){int a=2,b=4;cout<<a/(b-4);}
int main(){
    int m,n;cin>>n>>m;
    //char *s = new char(1e5+5),*let = new char(1e5+5);
    //scanf("%s",s);scanf("%s",let);
    string s,let;
    cin>>s>>let;
    //printf("%s , %s",s,let);
    vector<int> vol(28,0),cur(28,0);
    for(int i=0;i<n;i++){
        s[i]-='a';
        if(s[i]<0||s[i]>27)callerr();
    }
    for(int i=0;i<m;i++){
        vol[let[i]-'a']++; 
    }
    long long ans=0;
    for(int i=0,j=0;;){
        while(j<n&&cur[s[j]]<vol[s[j]]){
            cur[s[j]]++;
            j++;
            ans+=j-i;
        }
        if(j==n)break;
        if(vol[s[j]]==0){
            for(int k=0;k<28;k++)cur[k] = 0;
            j++;i=j;if(j==n)break;
        }
        else while(cur[s[j]]==vol[s[j]]){
            cur[s[i]]--;i++;
        }

    }
    cout<<ans;
    return 0;
}