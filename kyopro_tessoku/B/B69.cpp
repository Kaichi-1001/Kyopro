#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int to, cap, rev;
};

class MaximumFlow
{
public:
    int size_ = 0;
    bool used[309];
    vector<Edge> G[309];

    // 頂点数N＋2の残余グラフを作成
    void init(int N)
    {
        size_ = N;
        for (int i = 0; i <= N + 1; i++)
        {
            G[i].clear();
        }
    }

    // 辺を追加
    void add_edge(int a, int b, int c)
    {
        int Current_Ga = G[a].size();
        int Current_Gb = G[b].size();
        G[a].push_back(Edge{b, c, Current_Gb});
        G[b].push_back(Edge{a, 0, Current_Ga});
    }

    // 深さ優先探索（Fはスタートからposに到達するまでの”残余グラフの辺の容量”の最小値）
    // 返り値は流したフローの量（流せない場合は0)を返す
    int dfs(int pos, int goal, int F)
    {
        // ゴールに到着 フローを流せる
        if (pos == goal)
        {
            return F;
        }
        used[pos] = true;

        // 探索する
        for (int i = 0; i < G[pos].size(); i++)
        {
            // 容量0の辺は使えない
            if (G[pos][i].cap == 0)
            {
                continue;
            }

            // 既に訪問した頂点に移動しても意味がない
            if (used[G[pos][i].to])
            {
                continue;
            }

            // 目的地までのパスを探す
            int flow = dfs(G[pos][i].to, goal, min(F, G[pos][i].cap));

            // フローを流せる場合、流す
            if (flow > 0)
            {
                G[pos][i].cap -= flow;
                G[G[pos][i].to][G[pos][i].rev].cap += flow;
                return flow;
            }
        }

        // フローを流せない場合は0を返す
        return 0;
    }

    // 頂点sからtまでの最大フローの総流量を返す
    int MaxFlow(int s, int t)
    {
        int Total_Flow = 0;
        while (true)
        {
            for (int i = 0; i <= size_ + 1; i++)
            {
                used[i] = false;
            }

            int F = dfs(s, t, 1000000000);
            Total_Flow += F;

            // フローを流せなくなったら強制終了
            if (F == 0)
            {
                break;
            }
        }
        return Total_Flow;
    }
};

int N, M;
char C[59][30];

int main()
{
    // input
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= 23; j++)
        {
            cin >> C[i][j];
        }
    }

    // 二部マッチング問題として処理
    MaximumFlow MF;
    MF.init(N + 24 + 2);

    // 一人10時間しか働けないので0からiへの容量は10
    for (int i = 1; i <= N; i++)
    {
        MF.add_edge(0, i, 10);
    }

    // i時台はM人がいればいいのでi+1+NからN+24+1への容量はM
    for (int i = 0; i <= 23; i++)
    {
        MF.add_edge(i + 1 + N, N + 24 + 1, M);
    }

    // 人と時間帯の間の辺を追加
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= 23; j++)
        {
            if (C[i][j] == '1')
            {
                MF.add_edge(i, j + 1 + N, 1);
            }
        }
    }

    // 最大フローを計算したとき、総流量がM*24以上ならばOK
    if (MF.MaxFlow(0, N + 24 + 1) >= M * 24)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}