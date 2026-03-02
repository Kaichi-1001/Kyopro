#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[100009], B[100009];
vector<vector<int>> G(100009, vector<int>());
vector<int> path;
bool visited[100009];

// dfs関数
// パスを保存できるように改良
bool dfs(int pos)
{
    visited[pos] = true;
    path.push_back(pos);
    if (path[path.size() - 1] == N) return true;

    for (int i = 0; i < G[pos].size(); i++)
    {
        if (!visited[G[pos][i]])
        {
            int next = G[pos][i];
            if (dfs(next)) return true;
        }
    }
    // 戻るときはpathの末尾を削除する
    path.pop_back();
    return false;
}
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

    
    // 単純パスを出力
    if (dfs(1))
    {
        for (int i = 0; i < path.size(); i++)
        {
            cout << path[i] << " ";
        }
        cout << endl;
        return 0;
    }   
}