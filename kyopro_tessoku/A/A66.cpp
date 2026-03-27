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
            par[i] = -1; // 最初は親が無い
        for (int i = 1; i <= N; i++)
            siz[i] = 1; // 最初はグループの頂点数が1
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
            return; // uとvが同グループのときは処理を行わない
        if (siz[RootU] < siz[RootV])
        {
            par[RootU] = RootV;
            siz[RootV] = siz[RootU] + siz[RootV];
        }
        else
        {
            par[RootV] = RootU;
            siz[RootU] = siz[RootU] + siz[RootV];
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

int N, Q;
int Query[100009], u[100009], v[100009];

int main()
{
    // input
    cin >> N >> Q;
    for (int i = 1; i <= Q; i++)
    {
        cin >> Query[i] >> u[i] >> v[i];
    }

    // クエリの処理
    UnionFind UF;
    UF.init(N);
    for (int i = 1; i <= Q; i++)
    {
        if (Query[i] == 1)
        {
            UF.unite(u[i], v[i]);
        }
        if (Query[i] == 2)
        {
            if (UF.same(u[i], v[i]))
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}