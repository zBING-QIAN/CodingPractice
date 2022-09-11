#include<bits/stdc++.h>
using namespace std;
#define MAXN 400005

int strcheck(char *a,char *b,int len){
    for(;a[len]&&b[len]&&a[len]==b[len];len++);return len;
}
int searchST(int *ST[20],int a,int b,int len){
    if(a>b)swap(a,b);
    if(a==b) return len-a;
    int d = (int)log2(b-a);
   
    return min(ST[d][a],ST[d][b-(1<<d)]);
}
void solve(char *arr){
    int len = strlen(arr),A = 128,*space = new int[MAXN*20];
    int *sa = new int[MAXN],*rank = space,*rank_new = space + MAXN*2,*c = new int[MAXN];
    for(int i=0;i<len;i++)rank[i] = arr[i],rank[i+len]=rank_new[i+len]=-1,c[i] = 0;
    for(int i=0;i<len;i++)c[rank[i]]++;
    for(int i=1;i<A;i++)c[i]+=c[i-1];
    for(int i = len-1;i>=0;i--)sa[--c[rank[i]]] = i;
    for(int i=1;i<len;i<<=1){
        for(int j=0;j<A;j++)c[j] = 0;
        for(int j=0;j<len;j++)c[rank[j]]++;
        for(int j=1;j<A;j++)c[j]+=c[j-1];
        int *sa2= rank_new,r = 0;
        for(int j = len-i;j<len;j++)sa2[r++] = j;
        for(int j=0;j<len;j++)if(sa[j]>=i)sa2[r++] = sa[j]-i;
        for(int j=len-1;j>=0;j--)sa[--c[rank[sa2[j]]]] = sa2[j];
        r = 0,rank_new[sa[0]] = 0;
        for(int j = 1;j<len;j++){
            if(!(rank[sa[j]]==rank[sa[j-1]]&&rank[sa[j]+i]==rank[sa[j-1]+i]))r++;
            rank_new[sa[j]] = r;
        }
        swap(rank,rank_new);
        if(r==len-1){for(int j=0;j<len;j++)c[j] = rank[j];rank = c;break;}
        A = r+1;
    }
    int *lcp = space;for(int i=0;i<len;i++)lcp[i]=-1;
    for(int i=0;i<len;i++){
        int length = 0,next = rank[i];
        while(length>=0&&next<len-1&&lcp[next]==-1){
            length = strcheck(arr+sa[next],arr+sa[next+1],length);
            lcp[next] = length;length--;next = rank[sa[next]+1];
        }
    }lcp[len-1] = 0;
    //cout<<"sa : ";for(int i=0;i<len-1;i++)cout<<sa[i]<<" ";cout<<endl;
    int *ST[20],p = 1, k = 0;ST[0] = space;
    for(int i=1;p<len;i++,p<<=1){
        ST[i] = ST[i-1]+len-p+1;
        for(int j = 0;j<len-p;j++){
            ST[i][j] = min(ST[i-1][j],ST[i-1][j+p]);
        }
    }
    int ans = 1;
    vector<int> h,pos;h.push_back(0),pos.push_back(-1);
    for(int i=0;i<len;i++){
        if(lcp[i]>h.back())h.push_back(lcp[i]),pos.push_back(i);
        else{
            while(lcp[i]<h.back()){
                int height = h.back();
                h.pop_back(),pos.pop_back();
                int left = pos.back()+1,right = i,base = pos.back()+1;
               // cout<<arr+sa[base]<<"   with lcp "<<height<< " left right "<<left<<"  "<<right<<endl;
                while(left<right){
                    int mid = (right+left)>>1;
                  //  cout<<arr+sa[mid]<<endl<<arr+sa[mid]+height<<endl;
                    int per =(sa[mid]+height>=len)?1: 1 + searchST(ST,mid,rank[sa[mid]+height],len)/height;
                  //  cout<<"sa mid , sa mid + per * height "<<mid<<"  "<< sa[mid]+ per*height<<endl;
                  //  cout<<"period :"<<per<<endl;
                    ans = max(ans,per);
                    if((sa[mid] + per * height >= len || rank[sa[mid] + per * height] < base)){
                        left = mid+1;
                    }else {
                        right = mid;
                    }   
                }
                int per = 1 + searchST(ST,left,rank[sa[left]+height],len)/height;
                ans = max(ans,per);
            }
            if(lcp[i]==0||lcp[i]!=h.back())h.push_back(lcp[i]),pos.push_back(i);
        }
       

    }
   
    cout<<ans<<endl;
}

int main(){
    char *arr = new char[MAXN];
    cin>>arr;
    solve(arr);
    return 0;
}