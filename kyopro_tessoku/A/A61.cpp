#include <bits/stdc++.h>
using namespace std;

int N, M, A[100009], B[100009];

int main()
{
    // input
    cin >> N >> M;
    for (int i = 1; i <= M; i++)
    {
        cin >> A[i] >> B[i];
    }

    // 2次元配列に頂点の隣接関係を保存
    vector<vector<int>> G(100009, vector<int>());
    for (int i = 1; i <= M; i++)
    {
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }

    // 指定の形で出力
    for (int i = 1; i <= N; i++)
    {
        cout << i << ": {";
        for (int j = 0; j < G[i].size(); j++)
        {
            if (j >= 1)
            {
                cout << ", ";
            }
            cout << G[i][j];
        }
        cout << "}\n";
    }
    return 0;
}