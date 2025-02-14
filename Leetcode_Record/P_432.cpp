#include <bits/stdc++.h>
using namespace std;

class AllOne {
public:
    vector<pair<int,string>> maxheap;
    unordered_map<string,int> table;
    AllOne() {
        maxheap.push_back({0,""});
    }
    
    void inc(string key) {
        if(table.find(key)==table.end()){table[key]=maxheap.size();maxheap.push_back({1,key});}
        else {
            int pos = table[key];
            maxheap[pos].first++;
            while((pos>>1)&&maxheap[pos].first>maxheap[pos>>1].first){
                swap(maxheap[pos],maxheap[pos>>1]);
                table[maxheap[pos].second]=pos;
                table[maxheap[pos>>1].second]=pos>>1;
                pos>>=1;
            }
        }
    }
    
    void dec(string key) {
        int pos = table[key];
        maxheap[pos].first--;
        while(pos*2<maxheap.size()){
            int nxt=pos*2;
            if(maxheap.size()>nxt+1&&maxheap[nxt+1].first>maxheap[nxt].first){
                nxt++;
            }
            if(maxheap[pos].first>=maxheap[nxt].first)break;
            swap(maxheap[pos],maxheap[nxt]);
            table[maxheap[pos].second]=pos;
            table[maxheap[nxt].second]=nxt;
            pos = nxt;
        }
        if(maxheap[pos].first==0){
            swap(maxheap[pos],maxheap.back());
            table[maxheap[pos].second]=pos;
            table.erase(maxheap.back().second);
            maxheap.pop_back();
        }
    }
    
    string getMaxKey() {
        if(maxheap.size()==1)return "";
        return maxheap[1].second;
    }
    
    string getMinKey() {
        return maxheap.back().second;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */