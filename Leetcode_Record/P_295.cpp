#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    struct heap{
        vector<int> h;
        bool is_maxheap;
        heap(bool is_maxheap){
            h.resize(1,0);
            this->is_maxheap=is_maxheap;
        }
        bool cmp(auto a,auto b){
            if(is_maxheap)return a<b;
            else return a>b;
        }
        int top(){return h[1];}
        void pop(){
            if(h.size()>1){
                h[1] = h.back();
                int cur =1,nxt = 2;
                while(nxt<h.size()){
                    if(nxt+1<h.size()&&cmp(h[nxt],h[nxt+1])){
                        nxt++;
                    }
                    if(cmp(h[cur],h[nxt]))swap(h[cur],h[nxt]);
                    else break;
                    cur= nxt;nxt = cur<<1;
                }
            }
            h.pop_back();
        }
        void insert(int v){
            int cur = h.size(),par = cur>>1;
            h.push_back(v);
            while(par&&cmp(h[par],h[cur])){
                swap(h[par],h[cur]);
                cur = par;par = cur>>1;
            }
        }
        int size(){return h.size()-1;}
    };

    heap max_heap = heap(1),min_heap = heap(0);
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(min_heap.size()==0||num>min_heap.top()){
            if(min_heap.size()>max_heap.size()){
                int tmp = min_heap.top();
                max_heap.insert(tmp);
                min_heap.pop();
            }
            min_heap.insert(num);

        }
        else {        
            max_heap.insert(num);    
            if(max_heap.size()>min_heap.size()){
                int tmp = max_heap.top();
                min_heap.insert(tmp);
                max_heap.pop();
            }


        }
    }
    
    double findMedian() {
        if(min_heap.size()>max_heap.size())return min_heap.top();
        else if(min_heap.size()<max_heap.size())return max_heap.top();
        else return (double(max_heap.top())+double(min_heap.top()))/2.0f;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */