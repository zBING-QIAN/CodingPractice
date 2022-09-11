#include<bits/stdc++.h>
using namespace std;
#define MAXN 300005
int strcheck(char *a,char*b){
    int i=0;
    for(;a[i]&&b[i]&&a[i]==b[i];i++);
    return i;
}

void solveSA(char *arr ){
    int *sa = new int[MAXN],*rank = new int[MAXN*2],*rank_new= new int[MAXN*2],*c = new int[MAXN],len = strlen(arr),A = 30;
    for(int i=0;i<len;i++)rank[i] = arr[i]-'a',rank[i+len] = rank_new[i+len] = -1,c[i]=0; 
    for(int i=0;i<len;i++)c[rank[i]]++;
    for(int i=1;i<A;i++)c[i] +=c[i-1];
    for(int i=len-1;i>=0;i--)sa[--c[rank[i]]]= i;
    for(int i=1;i<len;i<<=1){
        for(int j = 0;j<A;j++)c[j] = 0;
        for(int j= 0;j<len;j++)c[rank[j]]++;
        for(int j=1;j<A;j++)c[j] += c[j-1];
        int *sa2=rank_new,r=0;
        for(int j= len-i;j<len;j++)sa2[r++] = j;
        for(int j=0;j<len;j++){
            if(sa[j]-i>=0)sa2[r++] = sa[j]-i;
        }
        for(int j = len-1;j>=0;j--)sa[--c[rank[sa2[j]]]] = sa2[j];
        r = 0; rank_new[sa[0]] = 0;
        for(int j=1;j<len;j++){
            if(!(rank[sa[j-1]] == rank[sa[j]]&&rank[sa[j-1]+i] == rank[sa[j]+i]))r++;
            rank_new[sa[j]] = r;
        }
        swap(rank,rank_new);
        if(r == len-1)break;
        A = r+1;
        
    }
    int n;
    cin>>n;
    char *str = new char[MAXN];
    for(int i=0;i<n;i++){
        cin>>str;
        int left = 0,right = len-1,slen = strlen(str);
        while(left<right){
            int mid =(left+right)>>1,result = strcmp(str,arr+sa[mid]);
            if(result>0)left=mid+1;
            else right = mid;
        }

        if(strcheck(str,arr+sa[right])==slen){cout<<"Yes\n";}
        else cout<<"No\n";
    }

}


void solveSA_count(char *arr ){
    int *sa = new int[MAXN],*rank = new int[MAXN*2],*rank_new= new int[MAXN*2],*c = new int[MAXN],len = strlen(arr),A = 30;
    for(int i=0;i<len;i++)rank[i] = arr[i]-'a',rank[i+len] = rank_new[i+len] = -1,c[i]=0; 
    for(int i=0;i<len;i++)c[rank[i]]++;
    for(int i=1;i<A;i++)c[i] +=c[i-1];
    for(int i=len-1;i>=0;i--)sa[--c[rank[i]]]= i;
    for(int i=1;i<len;i<<=1){
        for(int j = 0;j<A;j++)c[j] = 0;
        for(int j= 0;j<len;j++)c[rank[j]]++;
        for(int j=1;j<A;j++)c[j] += c[j-1];
        int *sa2=rank_new,r=0;
        for(int j= len-i;j<len;j++)sa2[r++] = j;
        for(int j=0;j<len;j++){
            if(sa[j]-i>=0)sa2[r++] = sa[j]-i;
        }
        for(int j = len-1;j>=0;j--)sa[--c[rank[sa2[j]]]] = sa2[j];
        r = 0; rank_new[sa[0]] = 0;
        for(int j=1;j<len;j++){
            if(!(rank[sa[j-1]] == rank[sa[j]]&&rank[sa[j-1]+i] == rank[sa[j]+i]))r++;
            rank_new[sa[j]] = r;
        }
        swap(rank,rank_new);
        if(r == len-1)break;
        A = r+1;
        
    }
    int n;
    cin>>n;
    char *str = new char[MAXN];
    for(int i=0;i<n;i++){
        cin>>str;
        int left = 0,right = len-1,slen = strlen(str);
        while(left<right){
            int mid =(left+right)>>1,result = strcmp(str,arr+sa[mid]);
            if(result>0)left=mid+1;
            else right = mid;
        }
// bug asfadassa da
        if(strcheck(str,arr+sa[right])==slen){
            int base = right;right = len;
            while(left<right){
                int mid = (right+left)>>1;
                if(strcheck(str,arr+sa[mid])==slen)left=mid+1;
                else right =mid;
            }
            cout<<right-base<<endl;
        }
        else cout<<"0\n";
    }

}

int main(){
    char *arr;
    arr = new char[MAXN];
    cin>>arr;
    // solveSA(arr);
    solveSA_count(arr);
    return 0;
}