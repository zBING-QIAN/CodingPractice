#include <bits/stdc++.h>
using namespace std;

class SORTracker {
public:

    bool cmp(pair<int,string> &a,pair<int,string> &b){
        return (a.first<b.first)||(a.first==b.first&&a.second>b.second);
    }

    struct egt{
        pair<int,string> key;
        egt *l,*r;
        int cnt;
        egt(){
            l=0,r=0;key = {0,""};cnt = 1;
        }
        egt(pair<int,string> k){
            key = k;
            l=0,r=0;cnt = 1;
        }
    };
    void flatten(egt* cur,vector<egt*> &out){
        if(cur->l)flatten(cur->l,out);
        out.push_back(cur);
        if(cur->r)flatten(cur->r,out);
    }
    egt* rebuild(vector<egt*> &out,int l,int r){
        if(l==r){
            out[l]->cnt=1;out[l]->l=0;out[l]->r=0;return out[l];
        }if(l>r)return 0;
        int mid = (l+r)>>1;
        out[mid]->l=rebuild(out,l,mid-1);
        out[mid]->r = rebuild(out,mid+1,r);
        out[mid]->cnt=1;
        if(out[mid]->r)out[mid]->cnt += out[mid]->r->cnt;
        if(out[mid]->l)out[mid]->cnt += out[mid]->l->cnt;
        return out[mid];
    }
    egt* insert(egt *rt,pair<int,string> &k,bool lock){
        rt->cnt++;
        bool reb =0;
        if(lock){
            int lc=(rt->l)?rt->l->cnt:1;
            int rc=(rt->r)?rt->r->cnt:1;
            if(lc>rc)swap(lc,rc);
            if(lc*3<rc){reb=1;lock=0;}
        }
        if(cmp(k,rt->key)){
            if(rt->l)rt->l = insert(rt->l,k,lock);
            else rt->l = new egt(k); 
        }else{
            if(rt->r)rt->r = insert(rt->r,k,lock);
            else rt->r = new egt(k); 
        }
        if(reb){
            vector<egt*> tmp;
            flatten(rt,tmp);
            return rebuild(tmp,0,tmp.size()-1);
        }
        return rt;
    }
    string kth(egt *cur,int k){
        assert(k<=cur->cnt);
        if(cur->r){
            if(cur->r->cnt>=k)return kth(cur->r,k);
            else k-=cur->r->cnt;
        }
        if(k==1)return cur->key.second;
        else{
            k--;assert(cur->l);
            return kth(cur->l,k);
        }
    }
    egt *root;
    SORTracker() {
        root = 0;
    }
    
    void add(string name, int score) {
        if(root){
            pair<int,string> tmp = {score,name};
            root = insert(root,tmp,1);
        }else root = new egt({score,name});
        
    }
    int ask_k=1;
    string get() {
        return kth(root,ask_k++);
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */