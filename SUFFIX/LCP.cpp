#include<bits/stdc++.h>
using namespace std;

#define MAXN 400005
int strcheck(char *a,char *b,int l = 0){
    int i = l;
    for(;a[i]&&b[i]&&a[i]==b[i];i++);
    return i;
}


void LCP(char *arr){
    int A=30,len = strlen(arr),*sa = new int[MAXN],*space = new int[4*MAXN];
    int *rank = space,*rank_new = space+MAXN*2,*c = new int[MAXN];
    for(int i=0;i<len;i++)rank[i] = arr[i]-'a',rank[i+len] = rank_new[i+len] = -1,c[i]=0;
    for(int i=0;i<len;i++)c[rank[i]]++;
    for(int i=1;i<A;i++)c[i]+=c[i-1];
    for(int i = len-1;i>=0;i--)sa[--c[rank[i]]] = i;
    for(int i=1;i<len;i<<=1){
        for(int j=0;j<A;j++)c[j] = 0;
        for(int j = 0;j<len;j++)c[rank[j]]++;
        for(int j = 1;j<A;j++)c[j]+=c[j-1];
        int r = 0,*sa2 = rank_new;
        for(int j=len-i;j<len;j++)sa2[r++]=j;
        for(int j=0;j<len;j++)if(sa[j]>=i)sa2[r++] = sa[j]-i;
        for(int j=len-1;j>=0;j--)sa[--c[rank[sa2[j]]]] = sa2[j];
        r = 0,rank_new[sa[0]] = 0;
        for(int j= 1;j<len;j++){
            if(!(rank[sa[j]] == rank[sa[j-1]]&&rank[sa[j]+i]==rank[sa[j-1]+i]))r++;
            rank_new[sa[j]] = r;
        }
        swap(rank,rank_new);
        if(r==len-1)break;
        A=r+1;
    }
    cout<<len;
    for(int i=0;i<len;i++)cout<<" "<<sa[i];
    cout<<endl;

    // // seg tree
    // int p=1,*segTree = space;
    // for(;p<len;p<<=1);
    // segTree[0] = 0;
    // for(int i=1;i<len;i++)segTree[i+p] =  
    // for(int i = p-1;i^1;i--)segTree[i] = min(segTree[i<<1],segTree[(i<<1)+1]);
    cout<<"0 ";
    int *lcp = c;
    
    for(int i=0;i<len;i++)lcp[i]=-1;
    for(int i=0;i<len;i++){
        int next = rank[i],length = 0;
        while(length >=0&&next<len-1&&lcp[next]==-1){
            length = strcheck(arr+sa[next],arr+sa[next+1],length);
            lcp[next] = length;length--;next = rank[sa[next]+1];
        }
        
    }
    for(int i=0;i<len-1;i++)cout<<lcp[i]<<" ";cout<<endl;
    
}


int main(){
    char *arr = new char[MAXN];
    cin>>arr;
    LCP(arr);
    return 0;
}