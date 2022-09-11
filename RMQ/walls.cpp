#include<bits/stdc++.h>
using namespace std;
struct node{
    int l,r;
    int big,small;
    bool lazyup,lazydown;
    node(){big = small=0; l= r=-1;lazyup=lazydown=0;}
};
int MAXN;
int zero = 0;
vector<node> seg;
void add(int l,int r,int v,int left,int right,int cur){
    if(left!=right&&seg[cur].l==-1){seg[cur].l=seg.size();seg.push_back(node());}
    if(left!=right&&seg[cur].r==-1){seg[cur].r=seg.size();seg.push_back(node());}
    if(left>=l&&right<=r){
       
        if(v>seg[cur].small){
            seg[cur].small = v;seg[cur].lazyup = true;
            if(v > seg[cur].big){
                seg[cur].lazydown =true;seg[cur].big = v;
            }
        } 
        return;
    }
    // bug here update below
    {
        if(seg[cur].lazyup){
            if(seg[cur].small>seg[seg[cur].l].small){
                seg[seg[cur].l].lazyup = true;seg[seg[cur].l].small = seg[cur].small;
                if(seg[cur].small>seg[seg[cur].l].big){
                    seg[seg[cur].l].lazydown = true;seg[seg[cur].l].big = seg[cur].small;
                }
            }
        }
        if(seg[cur].lazydown){
            
            if(seg[cur].big<seg[seg[cur].l].big){
                seg[seg[cur].l].lazydown = true;seg[seg[cur].l].big = seg[cur].big;
                if(seg[cur].big<seg[seg[cur].l].small){
                    seg[seg[cur].l].lazyup = true;seg[seg[cur].l].small = seg[cur].big;
                }
            }
        }
    }
    {
        if(seg[cur].lazyup){
            if(seg[cur].small>seg[seg[cur].r].small){
                seg[seg[cur].r].lazyup = true;seg[seg[cur].r].small = seg[cur].small;
                if(seg[cur].small>seg[seg[cur].r].big){
                    seg[seg[cur].r].lazydown = true;seg[seg[cur].r].big = seg[cur].small;
                }
            }
        }
        if(seg[cur].lazydown){
            if(seg[cur].big<seg[seg[cur].r].big){
                seg[seg[cur].r].lazydown = true;seg[seg[cur].r].big = seg[cur].big;
                if(seg[cur].big<seg[seg[cur].r].small){
                    seg[seg[cur].r].lazyup = true;seg[seg[cur].r].small = seg[cur].big;
                }
            }
        }
    }
    seg[cur].lazydown = seg[cur].lazyup = 0;
    int mid= (left+right)>>1;
    if(mid>=l)add(l,r,v,left,mid,seg[cur].l);
    if(mid<r)add(l,r,v,mid+1,right,seg[cur].r);
    seg[cur].big = max(seg[seg[cur].l].big,seg[seg[cur].r].big);
    seg[cur].small= min(seg[seg[cur].l].small,seg[seg[cur].r].small);
}
void remove(int l,int r,int v,int left,int right,int cur){
    if(left!=right&&seg[cur].l==-1){seg[cur].l=seg.size();seg.push_back(node());}
    if(left!=right&&seg[cur].r==-1){seg[cur].r=seg.size();seg.push_back(node());}
    if(left>=l&&right<=r){
    
        if(v<seg[cur].big){
            seg[cur].big = v;seg[cur].lazydown = true;
            if(v < seg[cur].small){
                seg[cur].lazyup =true;seg[cur].small = v;
            }
        } 
        return;
    }
    // bug here update below
    {
        if(seg[cur].lazyup){
            if(seg[cur].small>seg[seg[cur].l].small){
                seg[seg[cur].l].lazyup = true;seg[seg[cur].l].small = seg[cur].small;
                if(seg[cur].small>seg[seg[cur].l].big){
                    seg[seg[cur].l].lazydown = true;seg[seg[cur].l].big = seg[cur].small;
                }
            }
        }
        if(seg[cur].lazydown){
            
            if(seg[cur].big<seg[seg[cur].l].big){
                seg[seg[cur].l].lazydown = true;seg[seg[cur].l].big = seg[cur].big;
                if(seg[cur].big<seg[seg[cur].l].small){
                    seg[seg[cur].l].lazyup = true;seg[seg[cur].l].small = seg[cur].big;
                }
            }
        }
    }
    {
        if(seg[cur].lazyup){
            if(seg[cur].small>seg[seg[cur].r].small){
                seg[seg[cur].r].lazyup = true;seg[seg[cur].r].small = seg[cur].small;
                if(seg[cur].small>seg[seg[cur].r].big){
                    seg[seg[cur].r].lazydown = true;seg[seg[cur].r].big = seg[cur].small;
                }
            }
        }
        if(seg[cur].lazydown){
            if(seg[cur].big<seg[seg[cur].r].big){
                seg[seg[cur].r].lazydown = true;seg[seg[cur].r].big = seg[cur].big;
                if(seg[cur].big<seg[seg[cur].r].small){
                    seg[seg[cur].r].lazyup = true;seg[seg[cur].r].small = seg[cur].big;
                }
            }
        }
    }
    seg[cur].lazydown = seg[cur].lazyup = 0;
    int mid= (left+right)>>1;
    if(mid>=l)remove(l,r,v,left,mid,seg[cur].l);
    if(mid<r)remove(l,r,v,mid+1,right,seg[cur].r);
    seg[cur].big = max(seg[seg[cur].l].big,seg[seg[cur].r].big);
    seg[cur].small= min(seg[seg[cur].l].small,seg[seg[cur].r].small);
}

void dfs(int l,int r,int cur){
    if(seg[cur].small == seg[cur].big){
        for(int i = l;i <=r&&i<MAXN;i++)printf("%d\n",seg[cur].small);return;
    }
    {
        if(seg[cur].lazyup){
            if(seg[cur].small>seg[seg[cur].l].small){
                seg[seg[cur].l].lazyup = true;seg[seg[cur].l].small = seg[cur].small;
                if(seg[cur].small>seg[seg[cur].l].big){
                    seg[seg[cur].l].lazydown = true;seg[seg[cur].l].big = seg[cur].small;
                }
            }
        }
        if(seg[cur].lazydown){
            
            if(seg[cur].big<seg[seg[cur].l].big){
                seg[seg[cur].l].lazydown = true;seg[seg[cur].l].big = seg[cur].big;
                if(seg[cur].big<seg[seg[cur].l].small){
                    seg[seg[cur].l].lazyup = true;seg[seg[cur].l].small = seg[cur].big;
                }
            }
        }
    }
    {
        if(seg[cur].lazyup){
            if(seg[cur].small>seg[seg[cur].r].small){
                seg[seg[cur].r].lazyup = true;seg[seg[cur].r].small = seg[cur].small;
                if(seg[cur].small>seg[seg[cur].r].big){
                    seg[seg[cur].r].lazydown = true;seg[seg[cur].r].big = seg[cur].small;
                }
            }
        }
        if(seg[cur].lazydown){
            if(seg[cur].big<seg[seg[cur].r].big){
                seg[seg[cur].r].lazydown = true;seg[seg[cur].r].big = seg[cur].big;
                if(seg[cur].big<seg[seg[cur].r].small){
                    seg[seg[cur].r].lazyup = true;seg[seg[cur].r].small = seg[cur].big;
                }
            }
        }
    }
    seg[cur].lazydown = seg[cur].lazyup = 0;
    int mid = (l+r)>>1; 
    if(seg[cur].l==-1||seg[cur].r == -1){cout<<(1/seg[cur].lazyup);}
    dfs(l,mid,seg[cur].l);
    dfs(mid+1,r,seg[cur].r);
}

int main(){
    int m,p;cin>>MAXN>>m;
    for(p=1;p<MAXN;p<<=1);
    seg.push_back(node());
    for(int i=0;i<m;i++){
        int op,l,r,v;scanf("%d %d %d %d",&op,&l,&r,&v);
        if(op==1)add(l,r,v,0,p-1,0);
        else remove(l,r,v,0,p-1,0);
    }
    dfs(0,p-1,0);    
    return 0;
}