#include <bits/stdc++.h>
using namespace std;


class MKAverage
{
public:
    long long sum = 0;
    int m, k, mid, skcnt, lkcnt, midcnt;
    queue<int> contain;
    map<int, int> smallk, largek, mids;

    MKAverage(int m, int k)
    {
        this->m = m;
        this->k = k;
        mid = m - 2 * k;
        sum = 0;
        skcnt = 0;
        lkcnt = 0;
        midcnt = 0;
    }

    void addElement(int num)
    {
        contain.push(num);
        if (skcnt < k || smallk.rbegin()->first >= num)
        {
            smallk[num]++;
            skcnt++;
        }
        else
        {
            if (midcnt < mid || mids.rbegin()->first >= num)
            {
                mids[num]++;
                midcnt++;
                sum += num;
            }
            else
            {
                lkcnt++;
                largek[num]++;
            }
        }
        // cout<<"small \n";for(auto &ss:smallk)cout<<ss.first<<" "<<ss.second<<endl;
        if (contain.size() > m)
        {
            int cf = contain.front();
            if (smallk.find(cf) != smallk.end())
            {
                // cout<<"gggggggggg "<<smallk[cf]<<" "<<cf<<endl;
                if (smallk[cf] == 1)
                    smallk.erase(cf);
                else
                    smallk[cf]--;
                skcnt--;
            }
            else if (mids.find(cf) != mids.end())
            {
                if (mids[cf] == 1)
                    mids.erase(cf);
                else
                    mids[cf]--;
                midcnt--;
                sum -= cf;
            }
            else
            {
                if (largek[cf] == 1)
                    largek.erase(cf);
                else
                    largek[cf]--;
                lkcnt--;
            }
            contain.pop();
        }
        if (skcnt > k)
        {
            skcnt--;
            mids[smallk.rbegin()->first]++;
            midcnt++;
            sum += smallk.rbegin()->first;
            smallk.rbegin()->second--;
            if (smallk.rbegin()->second == 0)
                smallk.erase(smallk.rbegin()->first);
        }
        if (lkcnt > k)
        {
            lkcnt--;
            mids[largek.begin()->first]++;
            midcnt++;
            sum += largek.begin()->first;
            largek.begin()->second--;
            if (largek.begin()->second == 0)
                largek.erase(largek.begin()->first);
        }
        if (midcnt > mid)
        {
            midcnt--;
            if (skcnt < k)
            {
                int midfront = mids.begin()->first;
                mids[midfront]--;
                sum -= midfront;
                if (mids[midfront] == 0)
                    mids.erase(midfront);

                smallk[midfront]++;
                skcnt++;
            }
            else
            {
                int midend = mids.rbegin()->first;
                mids[midend]--;
                sum -= midend;
                if (mids[midend] == 0)
                    mids.erase(midend);
                largek[midend]++;
                lkcnt++;
            }
        }
        // cout<<"small \n";for(auto &ss:smallk)cout<<ss.first<<" "<<ss.second<<endl;
        // cout<<"mid \n";for(auto &ss:mids)cout<<ss.first<<" "<<ss.second<<endl;
        // cout<<"large \n";for(auto &ss:largek)cout<<ss.first<<" "<<ss.second<<endl;
    }

    int calculateMKAverage()
    {
        if (contain.size() == m)
        {
            return sum / mid;
        }
        else
            return -1;
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */