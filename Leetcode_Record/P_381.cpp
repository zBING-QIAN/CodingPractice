#include <bits/stdc++.h>
using namespace std;

class RandomizedCollection {
public:
    vector<int> prev,nxt,value;
    unordered_map<int,int> to;
    RandomizedCollection() {
        prev.clear();nxt.clear();value.clear();
    }
    
    bool insert(int val) {
        int last = value.size();
        if(to.find(val) != to.end()){
            int now = to[val];
            nxt[now] = last;
            nxt.push_back(last);
            prev.push_back(now);
            value.push_back(val);
            to[val]=last;
            return false;
        }else{
            nxt.push_back(last);
            prev.push_back(last);
            value.push_back(val);
            to[val]=last;
            return true;
        }
        
    }
    
    bool remove(int val) {
        if(to.find(val)!=to.end()){
            // for(int i=0;i<value.size();i++){printf("%d %d %d || ",value[i],nxt[i],prev[i]);}cout<<endl;
            int target = to[val],last_value=value.back();
            int target_prev = prev[target];
            if(to[last_value]==value.size()-1)to[last_value]=target;
            if(target_prev==target){to.erase(val);}
            else {
                to[val]=target_prev;
                nxt[target_prev] = target_prev;
            }
            swap(value[target],value.back());
            swap(nxt[target],nxt.back());
            swap(prev[target],prev.back());
            nxt[prev[target]] = target;
            prev[nxt[target]] = target;
            if(nxt[target]==nxt.size()-1)nxt[target] = target;
            if(prev[target] == prev.size()-1)prev[target] = target;
            value.pop_back();nxt.pop_back();prev.pop_back();
            
            return true;
        }else{
            return false;
        } 
    }
    
    int getRandom() {
        if(value.size()==0)return 0;
        int idx = rand()%value.size();
        return value[idx];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */