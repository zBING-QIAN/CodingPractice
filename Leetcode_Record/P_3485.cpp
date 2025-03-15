#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int K;
    struct Trie
    {
        vector<Trie *> nxt;
        int cnt, len;
        Trie()
        {
            cnt = 0;
            nxt.resize(26, 0);
            len = 0;
        }
    };
    void get_list(Trie *cur, vector<Trie *> &list)
    {
        if (cur->cnt >= K)
        {
            list.push_back(cur);
            for (auto &to : cur->nxt)
            {
                if (to && to->cnt >= K)
                    get_list(to, list);
            }
        }
    }
    vector<int> longestCommonPrefix(vector<string> &words, int k)
    {
        K = k;
        vector<int> ans;
        vector<Trie *> list;
        Trie *root = new Trie();
        for (auto &w : words)
        {
            Trie *cur = root;
            cur->cnt++;
            for (auto c : w)
            {
                if (cur->nxt[c - 'a'] == 0)
                {
                    cur->nxt[c - 'a'] = new Trie();
                    cur->nxt[c - 'a']->len = cur->len + 1;
                }
                cur = cur->nxt[c - 'a'];
                cur->cnt++;
            }
        }
        get_list(root, list);
        sort(list.begin(), list.end(), [&](auto a, auto b)
             { return a->len > b->len; });
        for (auto &w : words)
        {
            Trie *cur = root;
            for (auto c : w)
            {
                cur = cur->nxt[c - 'a'];
                cur->cnt--;
            }
            for (int i = 0; i < list.size(); i++)
            {
                if (list[i]->cnt >= k)
                {
                    ans.push_back(list[i]->len);
                    break;
                }
            }
            cur = root;
            for (auto c : w)
            {
                cur = cur->nxt[c - 'a'];
                cur->cnt++;
            }
        }
        return ans;
    }
};