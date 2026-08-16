// 方針は動的計画法の復元
// いったんA64と同じ方法でcurを計算する

#include <bits/stdc++.h>
using namespace std;

int N, M;
long long A[100009], B[100009], C[100009];
vector<vector<pair<int, int>>> G(100009, vector<pair<int, int>>());
vector<bool> kakutei(100009, false);
vector<long long> cur(100009, 2000000009);
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> Q;

int main()
{
    // 入力
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

        // 確定させる
        kakutei[pos] = true;

        // 頂点posから出る辺を確定させる
        for (int i = 0; i < G[pos].size(); i++)
        {
            int next = G[pos][i].first;
            long long cost = G[pos][i].second;
            if (cur[next] > cur[pos] + cost)
            {
                cur[next] = cur[pos] + cost;
                Q.push(make_pair(cur[next], next));
            }
        }
    }

    // ここから復元でさかのぼっていく
    vector<int> path = {N};
    int pos = N;
    while (pos != 1)
    {
        for (int i = 0; i < G[pos].size(); i++)
        {
            int next = G[pos][i].first;
            if (cur[next] + G[pos][i].second == cur[pos])
            {
                path.push_back(next);
                pos = next;
                break;
            }
        }
    }

    // output path from back
    for (int i = path.size() - 1; i >= 0; i--)
    {
        cout << path[i] << " ";
    }
    cout << endl;
    return 0;
}