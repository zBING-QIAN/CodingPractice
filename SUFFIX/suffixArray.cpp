#include<bits/stdc++.h>
using namespace std;
#define MAXN 400005
// O (n(lgn)^2)
void get_suf(char *s){
    int len = strlen(s);
    int *suf_arr= new int[100005],*ptr = new int[200005],*ptr_new= new int[200005]; 
    for(int i=0;i<len;i++)suf_arr[i] = i,ptr[i+len] = -1,ptr[i] =  s[i]-'a',ptr_new[i+len] = -1;
    for(int i=1;i<len;i<<=1){
        sort(suf_arr,suf_arr+len,[&](int a,int b){
            if(ptr[a]==ptr[b]){
                return ptr[a+i]<ptr[b+i];   
            }
            return ptr[a]<ptr[b];
        });
        
        for(int j=1,r = ptr_new[suf_arr[0]] = 0;j<len;j++){
            if(ptr[suf_arr[j-1]]<ptr[suf_arr[j]]||(ptr[suf_arr[j]]==ptr[suf_arr[j-1]]&&ptr[suf_arr[j-1]+i]<ptr[suf_arr[j]+i]))r++;
           
            ptr_new[suf_arr[j]] = r;
            
        }
        swap(ptr,ptr_new);
        
    }
    cout<<len;
    for(int i=0;i<len;i++)cout<<" "<<suf_arr[i];
    cout<<endl;


}
//radix sort
void get_suf_v2(char *s){
    int len = strlen(s);
    int *suf_arr= new int[MAXN],*rank = new int[MAXN*2],*rank_new= new int[MAXN*2],*count = new int[MAXN]; 
    int A=30;
    
    for(int i=0;i<len;i++)rank[i] = s[i]-'a'+1,rank[i+len]=rank_new[i+len]=-1,count[i]=0;
    for(int i=0;i<len;i++)count[rank[i]]++;
    for(int i=1;i<A;i++)count[i]+=count[i-1];
    for(int i=len-1;i>=0;i--)suf_arr[--count[rank[i]]] = i;
    for(int i=1;i<len;i<<=1){
       
        int r=0,*sa2 = rank_new;
        for(int j=0;j<A;j++)count[j]=0;
        for(int j=0;j<len;j++)count[rank[j]]++;
        for(int j=1;j<A;j++)count[j]+=count[j-1];
        for(int j = len-i;j<len;j++)sa2[r++] = j;
        for(int j = 0;j<len;j++)if(suf_arr[j]>=i)sa2[r++] = suf_arr[j]-i;
        for(int j=len-1;j>=0;j--){
            suf_arr[--count[rank[sa2[j]]]] = sa2[j];
        }

        r=0;rank_new[suf_arr[0]] = 0;
        for(int j = 1;j<len;j++){
            if(!(rank[suf_arr[j-1]] == rank[suf_arr[j]]&&rank[suf_arr[j-1]+i] == rank[suf_arr[j]+i]))r++;
            rank_new[suf_arr[j]] = r;
        }
        swap(rank,rank_new);
        A=r+1;
    }
    cout<<len;
    for(int i=0;i<len;i++)cout<<" "<<suf_arr[i];
    cout<<endl;


}





int main(){
    char s[MAXN];
    cin>>s;
    // get_suf(s);
    get_suf_v2(s);
    return 0;
}