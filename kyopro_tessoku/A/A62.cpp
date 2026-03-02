#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[100009], B[100009];
vector<vector<int>> G(100009, vector<int>());
bool visited[100009];

// dfsの関数
void dfs(int pos) { // posは現在の頂点
    visited[pos] = true;
    for (int i = 0; i < G[pos].size(); i++)
    {
        if (!visited[G[pos][i]])
        {
            int next = G[pos][i];
            if (!visited[next]) dfs(next);
        }
    }
    return;
}

int main() {
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

    // 頂点をdfs
    dfs(1);

    // visitedを参照してすべての頂点にたどり着けるか（連結か）を判定して出力
    string ans = "The graph is connected.";
    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            ans = "The graph is not connected.";
            break;
        }
    }
    cout << ans << endl;
    return 0;

}