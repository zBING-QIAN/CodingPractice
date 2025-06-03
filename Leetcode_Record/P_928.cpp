#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dfs(int cur, vector<vector<int>> &graph, vector<int> &visit)
    {
        visit[cur] = 1;
        int res = 1;
        for (int i = 0; i < graph.size(); i++)
        {
            if (graph[cur][i] && visit[i] == 0)
            {
                res += dfs(i, graph, visit);
            }
        }
        return res;
    }

    int minMalwareSpread(vector<vector<int>> &graph, vector<int> &initial)
    {
        int n = graph.size(), res = 1000, idx = 0;
        vector<int> ignore(initial.size(), 0);
        for (int i = 0; i < initial.size(); i++)
        {
            ignore[i] = 1;
            vector<int> visit(n, 0);
            int restmp = 0;
            vector<int> colbak(n, 0), rowbak(n, 0);
            for (int j = 0; j < n; j++)
            {
                colbak[j] = graph[initial[i]][j];
                rowbak[j] = graph[j][initial[i]];
                graph[initial[i]][j] = 0;
                graph[j][initial[i]] = 0;
            }
            for (int j = 0; j < initial.size(); j++)
            {
                if (ignore[j] == 0 && visit[initial[j]] == 0)
                {
                    restmp += dfs(initial[j], graph, visit);
                }
            }
            // cout<<i<<" "<<restmp<<endl;
            if (res > restmp || (res == restmp && initial[i] < initial[idx]))
            {
                idx = i;
                res = restmp;
            }
            ignore[i] = 0;

            for (int j = 0; j < n; j++)
            {
                graph[initial[i]][j] = colbak[j];
                graph[j][initial[i]] = rowbak[j];
            }
        }
        return initial[idx];
    }
};