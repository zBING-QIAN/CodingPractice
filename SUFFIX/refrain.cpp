#include<bits/stdc++.h>
using namespace std;
#define MAXN 400005
int strcheck(int *a,int *b,int len= 0){
    for(;a[len]&&b[len]&&a[len]==b[len];len++);return len;
}
void solveSA(int *arr,int len,int A){
    int *sa = new int[MAXN],*rank = new int[MAXN*2],*rank_new = new int[MAXN*2],*c = new int[MAXN];
    
    for(int i=0;i<len;i++)rank[i] = arr[i],rank[i+len]=rank_new[i+len]=-1,c[i]= 0;
    for(int i=0;i<len;i++)c[rank[i]]++;
    for(int i=1;i<A;i++)c[i]+=c[i-1];
    for(int i=len-1;i>=0;i--)sa[--c[rank[i]]] = i;
    for(int i=1;i<len;i<<=1){
        for(int j =0;j<A;j++)c[j]=0;
        for(int j = 0;j<len;j++)c[rank[j]]++;
        for(int j=1;j<A;j++)c[j]+=c[j-1];
        int *sa2 = rank_new,r =0;
        for(int j =len-i;j<len;j++)sa2[r++]=j;
        for(int j=0;j<len;j++)if(sa[j]>=i)sa2[r++]=sa[j]-i;
        for(int j=len-1;j>=0;j--)sa[--c[rank[sa2[j]]]] = sa2[j];
        r =0,rank_new[sa[0]]=0;
        for(int j=1;j<len;j++){
            if(!(rank[sa[j]]==rank[sa[j-1]]&&rank[sa[j]+i]==rank[sa[j-1]+i]))r++;
            rank_new[sa[j]]=r;
        }
        swap(rank,rank_new);if(r==len-1)break;
        A=r+1;
    }
//    cout<<"SA: ";for(int i=0;i<len;i++)cout<<sa[i]<<" ";cout<<endl;
    int *lcp = rank_new;for(int i=0;i<len;i++)lcp[i]=-1;
    for(int i=0;i<len;i++){
        int length = 0,next =rank[i];
        while(length>=0&&next<len-1&&lcp[next]==-1){
            length = strcheck(arr+sa[next],arr+sa[next+1],length);
            lcp[next] = length;length--;next = rank[sa[next]+1];
        }
    }
    //cout<<"lcp: ";for(int i=0;i<len;i++)cout<<lcp[i]<<" ";cout<<endl;
    int l=len,time=1,pos=0;
    long long ans = len;
    int *record = new int[MAXN];for(int i=0;i<len;i++)record[i]=0;
    vector<int> stac;stac.push_back(0);
    for(long long i=0;i<len;i++){
        long long tall = stac.back(),prevPos = record[stac.back()];
        while(stac.size()&&lcp[i]<stac.back()){
            tall = stac.back(),prevPos = record[stac.back()];
            long long tmp =  i-prevPos+1;tmp*=tall;
            if(tmp>ans){
                ans = tmp;
                pos = sa[record[tall]];
                time = i-prevPos+1;
                l = tall;
            }
            stac.pop_back();
        }   
        if(tall>lcp[i]&&(stac.size()&&stac.back()!=lcp[i])){
            stac.push_back(lcp[i]);record[lcp[i]] = prevPos;
        }else if(tall<lcp[i]){
            stac.push_back(lcp[i]);record[lcp[i]] = i;
        }
    }
    cout<<ans<<endl<<l<<endl;
    for(int i=0;i<l;i++)cout<<arr[pos+i]<<" ";
    cout<<endl;
}




int main(){
    int *arr = new int[MAXN];
    int m,n;cin>>m>>n;
    for(int i=0;i<m;i++)cin>>arr[i];
    solveSA(arr,m,n+1);

    return 0;
}