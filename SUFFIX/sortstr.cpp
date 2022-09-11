#include<bits/stdc++.h>
using namespace std;
#define MAXN 400005
int strcheck(char *a,char *b,int len){
    for(;a[len]&&b[len]&&a[len]==b[len];len++);
    return len;
}

int search(int p,int len,int *segTree,int A){
    int pos = p+A;
    while(pos&&segTree[pos]>=len){
        if(pos&1)pos>>=1;
        else pos--;
    }
    
    while(pos<A){
        
        if(segTree[(pos<<1)+1]<len){pos<<=1;pos++;}
        else pos<<=1;
    }
    return pos-A;
}

void solveSA(char *arr){
    int len = strlen(arr),*sa = new int[MAXN],*space = new int[MAXN*4],*c = new int[MAXN],A=128;
    int *rank = space,*rank_new = space+MAXN*2;
    for(int i=0;i<len;i++)rank[i] = arr[i],rank[i+len]=rank_new[i+len] = -1,c[i] = 0;
    for(int i=0;i<len;i++)c[rank[i]]++;
    for(int i=1;i<A;i++)c[i]+=c[i-1];
    for(int i=len-1;i>=0;i--)sa[--c[rank[i]]] = i;
    for(int i=1;i<len;i<<=1){
        for(int j = 0;j<A;j++)c[j] = 0;
        for(int j=0;j<len;j++)c[rank[j]]++;
        for(int j = 1;j<A;j++)c[j]+=c[j-1];
        int r= 0,*sa2 = rank_new;
        for(int j = len-i;j<len;j++)sa2[r++] = j;
        for(int j = 0;j<len;j++)if(sa[j]>=i)sa2[r++] = sa[j]-i;
        for(int j = len-1;j>=0;j--)sa[--c[rank[sa2[j]]]] = sa2[j];
        r = 0,rank_new[sa[0]] = 0;
        for(int j = 1;j<len;j++){
            if(!(rank[sa[j]]==rank[sa[j-1]]&&rank[sa[j]+i]==rank[sa[j-1]+i]))r++;
            rank_new[sa[j]] = r;
        }
        swap(rank,rank_new);
        if(r == len-1)break;
        A = r+1;
    }
    // for(int i=0;i<len;i++)cout<<sa[i]<<" ";cout<<endl;
    for(A = 1;A<len;A<<=1);
     int *segTree = space;
    int *lcp = segTree+A;
    for(int i=0;i<len;i++)c[i] = rank[i];
    rank = c;
    for(int i=0;i<A;i++)lcp[i] = 1e9;lcp[0] = 0;
    for(int i=0;i<len;i++){
        int length = 0,next = rank[i];
        while(next<len-1&&length>=0&&lcp[next+1] == 1e9){
            length = strcheck(arr+sa[next],arr+sa[next+1],length);
            lcp[next+1] = length;length--;
            next = rank[sa[next]+1];
        }
    } 
    for(int i=A-1;i;i--)segTree[i] = min(segTree[i<<1],segTree[(i<<1)+1]);
    // cout<<"segTree : ";for(int i=1;i<2*A;i++)cout<<segTree[i]<<" ";cout<<endl;
    vector<long long> no(len,0);
    long long total = len-sa[0];
    for(int i=1;i<len;i++){no[i] = total; total += len-sa[i]-lcp[i];}
    
    // for(int i=0;i<2*A;i++)cout<<no[i]<<" ";cout<<endl;

    // cout<<"total :"<<total<<endl; 
    // cout<<"LCP: ";
    // for(int i=0;i<len;i++)cout<<lcp[i]<<" ";cout<<endl;
    // cout<<"SA: ";
    // for(int i=0;i<len;i++)cout<<sa[i]<<" ";cout<<endl;

    int s;
    cin>>s;
    vector<int> left(s),right(s),idx(s);
    vector<long long>value(s);
    for(int i=0;i<s;i++){
        cin>>left[i]>>right[i];idx[i] = i;
        value[i] = search(rank[left[i]-1],right[i]-left[i]+1,segTree,A);        ///////////////
        value[i] = no[value[i]]+right[i]-left[i]-segTree[value[i]+A];    
    }
    sort(idx.begin(),idx.end(),[&](int a,int b){
        if(value[a] == value[b]){
            return left[a]<left[b]||(left[a]==left[b]&&right[a]<right[b]);
        }return value[a]<value[b];
    });
    for(int i=0;i<s;i++){
        cout<<left[idx[i]]<<" "<<right[idx[i]]<<endl;
    }
}








int main(){
    char *arr = new char[MAXN];
    cin>>arr;
    solveSA(arr);

    return 0;
}