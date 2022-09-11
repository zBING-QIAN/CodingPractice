#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
int strcheck(char *a,char *b, int len){
    for(;a[len]&&b[len]&&a[len]==b[len];len++);
    return len;
}


void solveSA(char *arr,int len1){
    int *sa = new int[MAXN*2],*rank = new int[MAXN*4],*rank_new = new int[MAXN*4],*c = new int[MAXN*2],len = strlen(arr),A = 30;
    for(int i=0;i<len;i++)rank[i] = arr[i] - 'a',rank[i+len] = -1,rank_new[i+len] = -1,c[i] = 0;
    for(int i=0;i<len;i++)c[rank[i]]++;
    for(int i=1;i<A;i++)c[i]+=c[i-1];
    for(int i=len-1;i>=0;i--)sa[--c[rank[i]]] = i;
    for(int i=1;i<len;i<<=1){
        for(int j = 0;j<A;j++)c[j] = 0;
        for(int j = 0;j<len;j++)c[rank[j]]++;
        for(int j=1;j<A;j++)c[j] += c[j-1];
        int r=0,*sa2 = rank_new;
        for(int j = len-i;j<len;j++)sa2[r++] = j;
        for(int j = 0;j<len;j++)if(sa[j]>=i)sa2[r++] = sa[j]-i;
        for(int j=len-1;j>=0;j--)sa[--c[rank[sa2[j]]]] = sa2[j];
        r = 0;rank_new[sa[0]] =0;
        for(int j=1;j<len;j++){
            if(!(rank[sa[j]]==rank[sa[j-1]]&&rank[sa[j]+i]==rank[sa[j-1]+i]))r++;
            rank_new[sa[j]] = r;
        }
        swap(rank,rank_new);
        if(r == len-1)break;
        A = r+1;
    }


    int ansp =0,ansl = 0,*lcp  = c;for(int i=0;i<len;i++)lcp[i] = -1;
    for(int i=0;i<len;i++){
        int length = 0,next =  rank[i];
        while(length>=0&&next<len-1&&lcp[next]==-1){
            length = strcheck(arr+sa[next],arr+sa[next+1],length);
            lcp[next] = length;length--;
            next = rank[sa[next]+1];
        }
    }
    for(int i=0;i<len-1;i++){
       
        if(sa[i]>len1^sa[i+1]>len1 && lcp[i]>ansl){
                ansl = lcp[i],ansp = sa[i];      
        }
    }
    for(int i = 0;i<ansl ; i++)cout<<arr[ansp+i];
   
}




int main(){
    char *s = new char[MAXN*2+1];
    char *s2,*s1 = s;
    cin>>s1;
    int len1 = strlen(s1);s[len1]='a'+27;s2 = s1+len1+1;
    cin>>s2;
    solveSA(s,len1);


    return 0;
}