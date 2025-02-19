#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct Trie
    {
        int word_id;
        vector<Trie *> nxt;
        Trie()
        {
            word_id = -1;
            nxt.resize(26, 0);
        }
    };

    int N, M;
    vector<int> ans_id;
    vector<vector<char>> bd;
    vector<vector<bool>> vis;
    vector<array<int, 2>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfs(Trie *cur, int x, int y)
    {
        if (cur->word_id >= 0)
            ans_id[cur->word_id] = 1;
        vis[x][y] = 1;
        for (auto &[dx, dy] : dirs)
        {
            int nx = dx + x, ny = dy + y;
            if (nx < N && nx >= 0 && ny < M && ny >= 0 && vis[nx][ny] == 0 && cur->nxt[bd[nx][ny] - 'a'])
            {
                dfs(cur->nxt[bd[nx][ny] - 'a'], x + dx, y + dy);
            }
        }
        vis[x][y] = 0;
    }
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        N = board.size();
        M = board[0].size();
        vis.resize(N, vector<bool>(M, 0));
        ans_id.resize(words.size(), 0);
        Trie root;
        bd = board;
        for (int i = 0; i < words.size(); i++)
        {
            Trie *cur = &root;
            for (auto c : words[i])
            {
                if (cur->nxt[c - 'a'] == 0)
                {
                    cur->nxt[c - 'a'] = new Trie();
                }
                cur = cur->nxt[c - 'a'];
            }
            cur->word_id = i;
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                Trie *cur = &root;
                if (cur->nxt[bd[i][j] - 'a'])
                    dfs(cur->nxt[bd[i][j] - 'a'], i, j);
            }
        }
        vector<string> ans;
        for (int i = 0; i < words.size(); i++)
        {
            if (ans_id[i])
                ans.push_back(words[i]);
        }
        return ans;
    }
};