#include<bits/stdc++.h>
using namespace std;
int main(){
    int m=100,n=100;
    srand(time(NULL));
    cout<<m<<" "<<n<<endl;
    for(int i=0;i<m;i++){
        cout<<rand()%30<<" ";
    }cout<<endl;
    for(int i=0;i<n;i++){
        int op = rand()%2;
        if(op==0)
            cout<<op+1<<" "<< rand()%100<<" "<< rand()%30<<endl;
        else {
            int s = rand()%100;
            int t = rand()%(100-s)+1;
            cout<<op+1<<" "<<s<<" "<<s+t<<endl;
        }
    }



    return 0;
}