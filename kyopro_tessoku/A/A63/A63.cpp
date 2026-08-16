#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[100009], B[100009];
vector<vector<int>> G(100009, vector<int>());
queue<int> Q;
int dist[100009];

int main()
{
    // input
    cin >> N >> M;
    for (int i = 1; i <= M; i++)
    {
        cin >> A[i] >> B[i];
    }

    // グラフを作成
    for (int i = 1; i <= M; i++)
    {
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }

    // 幅優先探索
    // initialize
    dist[1] = 0;
    for (int i = 2; i <= N; i++)
    {
        dist[i] = -1;
    }

    Q.push(1);
    while (!Q.empty())
    {
        for (int x : G[Q.front()])
        {
            if (dist[x] == -1)
            {
                dist[x] = dist[Q.front()] + 1;
                Q.push(x);
            }
        }
        Q.pop();
    }

    // output
    for (int i = 1; i <= N; i++)
    {
        cout << dist[i] << "\n";
    }
    cout << flush;
    return 0;
}