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
    bool used[409];
    vector<Edge> G[409];

    // 頂点数Nの残余グラフを準備
    void init(int N)
    {
        size_ = N;
        for (int i = 0; i <= N; i++)
        {
            G[i].clear();
        }
    }

    // 頂点aからbに向かう、上限cリットル/秒の辺の情報を追加
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
        // ゴールに到着　フローを流せる
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

            // すでに訪問した頂点に移動しても意味がない
            if (used[G[pos][i].to])
            {
                continue;
            }

            // 以上を満たさない頂点の先でゴールへのパスを再帰的に探索
            int flow = dfs(G[pos][i].to, goal, min(F, G[pos][i].cap));

            // フローを流せる場合は残余グラフの辺の値を更新
            if (flow > 0)
            {
                G[pos][i].cap -= flow;
                G[G[pos][i].to][G[pos][i].rev].cap += flow;
                // フローの値は再帰で前に戻していく
                return flow;
            }
        }
        // すべての辺を探索してもパスが見つからなかった
        return 0;
    }

    // 頂点sからtまでの最大フローの総流量を返す
    int max_flow(int s, int t)
    {
        int Total_flow = 0;
        while (true)
        {
            for (int i = 0; i <= size_; i++)
            {
                used[i] = false;
            }

            int F = dfs(s, t, 1000000000);

            // フローを流せなくなったら強制終了
            if (F == 0)
            {
                break;
            }
            Total_flow += F;
        }
        return Total_flow;
    }
};

int N, M;
int A[409], B[409], C[409];
MaximumFlow MF;

int main()
{
    // input
    cin >> N >> M;
    for (int i = 1; i <= M; i++)
    {
        cin >> A[i] >> B[i] >> C[i];
    }

    // 辺を追加
    MF.init(N);
    for (int i = 1; i <= M; i++)
    {
        MF.add_edge(A[i], B[i], C[i]);
    }

    // output
    cout << MF.max_flow(1, N) << endl;
    return 0;
}