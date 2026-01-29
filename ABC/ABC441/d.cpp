#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// グラフの辺を表す構造体
struct Edge
{
    int to;
    long long cost;
};

// グローバル変数
int N, M, L;
long long S, T;
vector<vector<Edge>> adj;     // 隣接リスト
vector<bool> is_valid_vertex; // 条件を満たす頂点を記録

// 深さ優先探索 (DFS)
void dfs(int u, long long current_cost, int depth)
{
    // 枝刈り: すでにコストがTを超えていたらこれ以上探索しない
    if (current_cost > T)
    {
        return;
    }

    // ちょうどL回移動した時点での判定
    if (depth == L)
    {
        if (current_cost >= S)
        {
            is_valid_vertex[u] = true;
        }
        return;
    }

    // 次の頂点へ (出次数は最大4なのでループ回数は少ない)
    for (const auto &edge : adj[u])
    {
        dfs(edge.to, current_cost + edge.cost, depth + 1);
    }
}

int main()
{
    // 高速化
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 入力受け取り
    if (!(cin >> N >> M))
        return 0;
    cin >> L >> S >> T;

    adj.resize(N + 1);
    is_valid_vertex.resize(N + 1, false);

    for (int i = 0; i < M; ++i)
    {
        int u, v;
        long long c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
    }

    // 探索開始 (頂点1から、コスト0、深さ0)
    dfs(1, 0, 0);

    // 答えの集計
    vector<int> result;
    for (int i = 1; i <= N; ++i)
    {
        if (is_valid_vertex[i])
        {
            result.push_back(i);
        }
    }

    // 出力処理（空白区切り）
    // resultが空の場合はループに入らず改行のみ出力される（空行）
    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i];
        if (i != result.size() - 1)
        {
            cout << " "; // 最後の要素以外には空白を入れる
        }
    }
    cout << endl; // 最後に改行

    return 0;
}