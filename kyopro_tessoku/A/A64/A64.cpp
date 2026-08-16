#include <bits/stdc++.h>
using namespace std;
// 優先度付きキューを使って計算速度を上げる
int N, M;
int A[100009], B[100009], C[100009];
vector<vector<pair<int, int>>> G(100009, vector<pair<int, int>>());
vector<bool> kakutei(100009, false);
vector<long long> cur(100009, 2000000009);
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> Q;

int main()
{
    // input
    cin >> N >> M;
    for (int i = 1; i <= M; i++)
    {
        cin >> A[i] >> B[i] >> C[i];
    }

    // グラフを作成
    for (int i = 1; i <= M; i++)
    {
        G[A[i]].push_back(make_pair(B[i], C[i]));
        G[B[i]].push_back(make_pair(A[i], C[i]));
    }

    // ダイクストラ法で最短距離を確定させていく
    cur[1] = 0;
    Q.push(make_pair(cur[1], 1));

    while (!Q.empty())
    {
        // 次に確定させる頂点を決める
        int pos = Q.top().second;
        Q.pop();

        // Qの最小値がすでに確定した頂点の場合はスキップ
        if (kakutei[pos])
            continue;

        // posと隣接する頂点のcurの値を更新
        kakutei[pos] = true;
        for (int i = 0; i < G[pos].size(); i++)
        {
            int next = G[pos][i].first;
            long long cost = G[pos][i].second + cur[pos];

            if (cost < cur[next])
            {
                cur[next] = cost;
                Q.push(make_pair(cost, next));
            }
        }
    }

    // output
    for (int i = 1; i <= N; i++)
    {
        if (cur[i] == 2000000009)
            cout << -1 << "\n";
        else
        {
            cout << cur[i] << "\n";
        }
    }
    cout << flush;
    return 0;
}