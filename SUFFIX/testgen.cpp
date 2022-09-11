#include<bits/stdc++.h>
using namespace std;

int main(){
    char s[10005];
    srand(time(NULL));
    for(int i=0;i<10000;i++){
        s[i] = 'a'+rand()%26;
    }s[10000] = 0;
    cout<<string(s)<<endl;

    return 0;
}