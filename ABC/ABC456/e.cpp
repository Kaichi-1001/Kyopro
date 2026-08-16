#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m, w;
    cin >> n >> m >> w;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    // out_deg[u][d]: 状態 (u, d) から遷移できる有効な状態の数
    vector<vector<int>> out_deg(n, vector<int>(w, 0));
    queue<pair<int, int>> q;

    // グラフの構築と出次数の計算
    for (int u = 0; u < n; u++)
    {
        for (int d = 0; d < w; d++)
        {
            if (s[u][d] == 'x')
                continue;

            int nxt_d = (d + 1) % w;
            int count = 0;

            // 留まる場合
            if (s[u][nxt_d] == 'o')
                count++;
            // 隣接都市へ移動する場合
            for (int v : g[u])
            {
                if (s[v][nxt_d] == 'o')
                    count++;
            }

            out_deg[u][d] = count;
            // 行き止まりであればキューに追加
            if (count == 0)
            {
                q.push({u, d});
            }
        }
    }

    // 行き止まり状態の逆伝播 (BFS)
    while (!q.empty())
    {
        auto [u, d] = q.front();
        q.pop();

        int prv_d = (d - 1 + w) % w;

        // 留まる選択肢で (u, prv_d) から来ていた場合
        if (s[u][prv_d] == 'o')
        {
            out_deg[u][prv_d]--;
            if (out_deg[u][prv_d] == 0)
            {
                q.push({u, prv_d});
            }
        }

        // 隣接都市 v から (u, d) へ移動してきていた場合
        for (int v : g[u])
        {
            if (s[v][prv_d] == 'o')
            {
                out_deg[v][prv_d]--;
                if (out_deg[v][prv_d] == 0)
                {
                    q.push({v, prv_d});
                }
            }
        }
    }

    // 曜日0（問題文の曜日1）で、出次数が残っている有効な出発点があるか確認
    bool possible = false;
    for (int u = 0; u < n; u++)
    {
        if (s[u][0] == 'o' && out_deg[u][0] > 0)
        {
            possible = true;
            break;
        }
    }

    if (possible)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t)
    {
        while (t--)
        {
            solve();
        }
    }
    return 0;
}