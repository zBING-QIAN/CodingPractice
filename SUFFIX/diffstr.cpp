#include<bits/stdc++.h>
using namespace std;
#define MAXN 400005
int strcheck(char *a,char *b,int len=0){
    for(;a[len]&&b[len]&&a[len]==b[len];len++);
    return len;
}


void solveLCP(char *arr){
    int *c = new int[MAXN],*space = new int[MAXN*4],*sa = new int[MAXN],len = strlen(arr),A = 30;
    int *rank = space,*rank_new = space+MAXN*2;
    for(int i=0;i<len;i++)rank[i] = arr[i]-'a',rank[i+len]=rank_new[i+len]=-1,c[i]=0;
    for(int i=0;i<len;i++)c[rank[i]]++;
    for(int i=1;i<A;i++)c[i]+=c[i-1];
    for(int i=len-1;i>=0;i--)sa[--c[rank[i]]] = i;
    for(int i=1;i<len;i<<=1){
        for(int j=0;j<A;j++)c[j] = 0;
        for(int j=0;j<len;j++)c[rank[j]]++;
        for(int j = 1;j<A;j++)c[j]+=c[j-1];
        int *sa2 = rank_new,r = 0;
        for(int j=len - i;j<len;j++)sa2[r++] = j;
        for(int j=0;j<len;j++)if(sa[j]>=i)sa2[r++] = sa[j]-i;
        for(int j=len-1;j>=0;j--)sa[--c[rank[sa2[j]]]]= sa2[j]; 
        r = 0;rank_new[sa[0]] = 0;
        for(int j=1;j<len;j++){
            if(!(rank[sa[j]]==rank[sa[j-1]]&&rank[sa[j]+i] == rank[sa[j-1]+i]))r++;
            rank_new[sa[j]]= r;
        }
        swap(rank_new,rank);
        if(r==len-1)break;
        A = r+1;
    }
    int *lcp = c ;for(int i=0;i<len;i++)c[i]=-1;
    for(int i = 0;i<len;i++){
        int next = rank[i],length = 0;
        while(length >=0 && next<len-1&&lcp[next]==-1){
            length = strcheck(arr+sa[next],arr+sa[next+1],length);
            lcp[next] = length;length--;
            next = rank[sa[next]+1];
        }
    }
    c[len-1] = 0;
    long long ans1 =len - sa[len-1];
    //long long ans = len*(len+1)/2;     //有些問題 ...
    for(int i=0;i<len-1;i++){
        //ans-=lcp[i];
        ans1 += len-sa[i] - lcp[i];
    }
    //cout<<ans<<endl;
    cout<<ans1;
}


int main(){
    char *s = new char[MAXN];
    cin>>s;
    solveLCP(s);
    return 0;
}