// 最小手数なのでBFSで計算

#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[19], X[109], Y[109], Z[109];
vector<vector<int>> G(2000, vector<int>());
vector<int> dist(2000, -1);
queue<int> Q;

int main() {
    // input
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    for (int i = 1; i <= M; i++)
    {
        cin >> X[i] >> Y[i] >> Z[i];
    }

    // start
    int start = 0;
    for (int i = 0; i < N; i++) {
        start += A[i] * (1 << i);
    }

    // goal
    int goal = (1 << N) - 1;

    // グラフを作成
    for (int i = 0; i < ((1<<N) - 1); i++) {
        for (int j = 1; j <= M; j++) {
            int next = i ^ (1 << (X[j] - 1));
            next ^= (1 << (Y[j] - 1));
            next ^= (1 << (Z[j] - 1));
            G[i].push_back(next);
        }
    }

    // BFS
    dist[start] = 0;
    Q.push(start);
    while(!Q.empty()) {
        int pos = Q.front();
        Q.pop();
        for (int i = 0; i < G[pos].size(); i++) {
            if (dist[G[pos][i]] == -1) {
                dist[G[pos][i]] = dist[pos] + 1;
                Q.push(G[pos][i]);
            }
        }
    }
        
    // output
    if (dist[goal] == -1) {
        cout << -1 << endl;
    } else {
        cout << dist[goal] << endl;
    }
    return 0;
}