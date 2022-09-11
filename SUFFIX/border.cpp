#include<bits/stdc++.h>
using namespace std;
#define MAXN 400006
int strcheck(char *a,char *b,int len){
    for(;a[len]&&b[len]&&a[len]==b[len];len++);
    return len;
}

void solveSA(char *arr){
    int *sa = new int[MAXN],*space = new int[MAXN*4],*c = new int[MAXN];
    int *rank = space,*rank_new = space+MAXN*2,A =128,len = strlen(arr);
    for(int i=0;i<len;i++)c[i]=0,rank[i] = arr[i],rank[i+len] = rank_new[i+len] = -1;
    for(int i =0;i<len;i++)c[rank[i]]++;
    for(int i=1;i<A;i++)c[i] += c[i-1];
    for(int i=len-1;i>=0;i--)sa[--c[rank[i]]] = i;
    for(int i= 1; i<len;i<<=1){
        for(int j = 0;j<A;j++) c[j] = 0;
        for(int j=0;j<len;j++)c[rank[j]]++;
        for(int j=1;j<A;j++)c[j]+=c[j-1];
        int *sa2 = rank_new,r = 0;
        for(int j=len-i;j<len;j++)sa2[r++] = j;
        for(int j = 0;j<len;j++)if(sa[j]>=i)sa2[r++] = sa[j]-i;
        for(int j=len-1;j>=0;j--)sa[--c[rank[sa2[j]]]] = sa2[j];
        r=0,rank_new[sa[0]] = 0;
        for(int j=1;j<len;j++){
            if(!(rank[sa[j]]==rank[sa[j-1]]&&rank[sa[j]+i]==rank[sa[j-1]+i]))r++;
            rank_new[sa[j]] = r;
        }
        swap(rank,rank_new);
        if(r==len-1){
            for(int j=0;j<len;j++)c[j] = rank[j];
            rank = c;    
            break;
        }
        A= r+1;
    }
    //cout<<"SA: ";for(int i=0;i<len;i++)cout<<sa[i]<<" ";cout<<endl;
    int *lcp = space;
    for(int i=0;i<len;i++)lcp[i] = -1;
    for(int i=0;i<len;i++){
        int length=0,next = rank[i];
        while(lcp[next]==-1&&length>=0&&next<len-1){
            length = strcheck(arr+sa[next],arr+sa[next+1],length);
            lcp[next] = length;length--;next = rank[sa[next]+1];
        }
    }
    //cout<<"LCP: ";for(int i=0;i<len-1;i++)cout<<lcp[i]<<" ";cout<<endl;
    long long ans = 0;
    long long *record = new long long[MAXN];vector<long long> stac;stac.push_back(0);record[0] = -1;
    for(int i=0;i<len;i++){
        long long tall = stac.back(),pos = record[stac.back()];
        while(lcp[i]<tall){ 
            stac.pop_back();if(stac.size()==0)break;
            long long tmp1 = i-pos+1,tmp2 = i-pos;
            long long tmp = (tmp1*tmp2)/2;
            if(stac.back()>=lcp[i]){
                ans+= (tall-stac.back())*tmp;//cout<<"tall:"<<tall<<" lcp[i] "<<i<<" , "<<lcp[i]<<" pos: "<<pos<<"  ans: "<<ans<<"  --- \n";
                tall = stac.back();pos = record[stac.back()];
            }else break;
        }   
        if(tall>lcp[i]){
            long long tmp1 = i-pos+1,tmp2 = i-pos;
            long long tmp = (tmp1*tmp2)/2;
            ans+= (tall-lcp[i])*tmp;
            if(true)stac.push_back(lcp[i]),record[lcp[i]] = pos;
            //cout<<"tall:"<<tall<<" lcp[i] "<<i<<" , "<<lcp[i]<<" pos: "<<pos<<"  ans: "<<ans<<"  ---() \n";
        }
        else if(lcp[i]>tall){
            stac.push_back(lcp[i]),record[lcp[i]] = i;
        }
    }
    cout<<ans<<endl;
}


int main(){
    char *arr = new char[MAXN];
    cin>>arr;
    solveSA(arr);

    return 0;
}