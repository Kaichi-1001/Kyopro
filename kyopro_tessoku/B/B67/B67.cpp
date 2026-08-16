#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
public:
    int par[100009];
    int siz[100009];

    // N頂点のUnion-Findを作成
    void init(int N)
    {
        for (int i = 1; i <= N; i++)
        {
            par[i] = -1;
        }
        for (int i = 1; i <= N; i++)
        {
            siz[i] = 1;
        }
    }

    // 頂点xの根を返す関数
    int root(int x)
    {
        while (true)
        {
            if (par[x] == -1)
                break;
            x = par[x];
        }
        return x;
    }

    // 要素uとvを統合する関数
    void unite(int u, int v)
    {
        int RootU = root(u);
        int RootV = root(v);
        if (RootU == RootV)
            return;
        if (siz[RootU] < siz[RootV])
        {
            par[RootU] = RootV;
            siz[RootV] += siz[RootU];
        }
        else
        {
            par[RootV] = RootU;
            siz[RootU] += siz[RootV];
        }
    }

    // uとvが同一のグループかを返す関数
    bool same(int u, int v)
    {
        if (root(u) == root(v))
            return true;
        else
            return false;
    }
};

int N, M;
int A[100009], B[100009], C[100009];
UnionFind UF;

int main()
{
    // input
    cin >> N >> M;
    for (int i = 1; i <= M; i++)
    {
        cin >> A[i] >> B[i] >> C[i];
    }

    // 辺を長さの長い順にソート
    vector<pair<int, int>> edge = {};
    for (int i = 1; i <= M; i++)
    {
        edge.push_back(make_pair(C[i], i));
    }
    sort(edge.begin(), edge.end(), greater<pair<int, int>>());

    // 最大全域木の辺の長さの合計を計算
    int answer = 0;
    UF.init(N);
    // 辺の長い順から
    // 辺の端の頂点二つが同一グループに入っているかチェック
    for (int i = 0; i < M; i++)
    {
        int edge_index = edge[i].second;
        if (!UF.same(A[edge_index], B[edge_index]))
        {
            answer += edge[i].first;
            UF.unite(A[edge_index], B[edge_index]);
        }
    }

    // output
    cout << answer << endl;
    return 0;
}