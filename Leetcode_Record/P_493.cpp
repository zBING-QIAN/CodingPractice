#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct sgt{
        int value,cnt,s;
        sgt *l,*r;
        sgt(int v){value = v;cnt =1;s=1;l=0;r=0;}
    };
    void flatten(sgt *rt,vector<sgt*> &out){
        if(rt->l)flatten(rt->l,out);
        out.push_back(rt);
        if(rt->r)flatten(rt->r,out);
    }
    sgt* rebuild(vector<sgt*> &arr,int left,int right){
        if(left==right){arr[left]->l = 0;arr[left]->r=0;arr[left]->cnt=arr[left]->s;return arr[left];}
        if(left>right)return 0;
        int mid = (right+left)>>1;
        arr[mid]->l = rebuild(arr,left,mid-1);
        arr[mid]->r = rebuild(arr,mid+1,right);
        arr[mid]->cnt = arr[mid]->s;
        if(arr[mid]->l)arr[mid]->cnt += arr[mid]->l->cnt;
        if(arr[mid]->r)arr[mid]->cnt += arr[mid]->r->cnt;
        return arr[mid];
    }
    sgt* rebalance(sgt *cur){
        vector<sgt*> tmp;
        flatten(cur,tmp);
        return rebuild(tmp,0,tmp.size()-1);
    }

    sgt* insert(sgt *cur,int value,bool lock=0){
        cur->cnt++;
        bool reb = 0;
        if(!lock){
            int lc = (cur->l)?cur->l->cnt:1;
            int rc = (cur->r)?cur->r->cnt:1;
            if(lc>rc)swap(lc,rc);
            if(rc>=lc*3){
                reb = 1;lock = 1;
            }
        }
        if(cur->value==value){cur->s++;return cur;}
        if(cur->value<value){
            if(cur->r){
                cur->r = insert(cur->r,value,lock);
            }else{
                cur->r = new sgt(value);
            }
        }else{
            if(cur->l){
                cur->l = insert(cur->l,value,lock);
            }else{
                cur->l = new sgt(value);
            }
        }
        if(reb)return rebalance(cur);
        return cur;
    }
    int le_cnt(sgt *cur,int value){
        // cout<<cur->value<<" "<<value<<endl;
        if(cur->value<=value){
            if(cur->r==0)return 0;
            return le_cnt(cur->r,value);
        }else {
            int tmp = cur->s+((cur->r)?cur->r->cnt:0);
            if(cur->l == 0)return tmp;
            // cout<<cur->value<<" "<<cur->s<<" "<<tmp<<endl;
            return le_cnt(cur->l,value)+tmp;
        }
    }
    void print(sgt *cur){
        if(cur->l)print(cur->l);
        // cout<<cur->value<<" "<<cur->s<<" "<<cur->cnt<<endl;
        if(cur->r)print(cur->r);
    }


    int reversePairs(vector<int>& nums) {
        sgt *root = new sgt(nums[0]);
        int ans =0;
        for(int i=1;i<nums.size();i++){
            long long tmpv = (long long)(nums[i])*2;
            if(tmpv<=INT_MAX&&tmpv>=INT_MIN)
                ans +=le_cnt(root,nums[i]*2);
            if(tmpv<INT_MIN)ans+=i;
            root = insert(root,nums[i]);
            if(i==10)print(root);
        }
        return ans;
    }
};