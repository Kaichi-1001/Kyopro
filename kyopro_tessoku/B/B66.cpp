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
            par[i] = -1; // 最初は親が無い
            siz[i] = 1;  // 最初はグループの頂点数が1
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
            return; // すでに同じグループにいる
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

int N, M, A[100009], B[100009];
int Q, Query[100009], x[100009], u[100009], v[100009];
string Answer[100009];

UnionFind UF;
bool cancelled[100009];

int main()
{
    // input
    cin >> N >> M;
    for (int i = 1; i <= M; i++)
    {
        cin >> A[i] >> B[i];
    }
    cin >> Q;
    for (int i = 1; i <= Q; i++)
    {
        cin >> Query[i];
        if (Query[i] == 1)
        {
            cin >> x[i];
        }
        else
        {
            cin >> u[i] >> v[i];
        }
    }

    // 最初に運休になっている路線を求める
    for (int i = 1; i <= M; i++)
    {
        cancelled[i] = false;
    }
    for (int i = 1; i <= Q; i++)
    {
        if (Query[i] == 1)
        {
            cancelled[x[i]] = true;
        }
    }

    // その日の状態にする
    UF.init(N);
    for (int i = 1; i <= M; i++)
    {
        if (cancelled[i] == false && UF.same(A[i], B[i]) == false)
        {
            UF.unite(A[i], B[i]);
        }
    }

    // クエリを逆順で処理
    for (int i = Q; i >= 1; i--)
    {
        if (Query[i] == 1)
        {
            // 駅A[x[i]]とB[x[i]]を統合する路線が開通
            if (UF.same(A[x[i]], B[x[i]]) == false)
            {
                UF.unite(A[x[i]], B[x[i]]);
            }
        }
        if (Query[i] == 2)
        {
            if (UF.same(u[i], v[i]))
            {
                Answer[i] = "Yes";
            }
            else
            {
                Answer[i] = "No";
            }
        }
    }

    // output
    for (int i = 1; i <= Q; i++)
    {
        if (Query[i] == 2)
        {
            cout << Answer[i] << endl;
        }
    }

    return 0;
}