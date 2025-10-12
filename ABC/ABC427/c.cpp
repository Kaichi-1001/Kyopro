#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// 辺の情報を格納するための構造体
struct Edge {
    int u, v;
};

/**
 * グラフを二部グラフにするための最小削除辺数を計算する。
 * (N <= 10 の制約を利用したビット全探索)
 * * @param N 頂点数 (1..N)
 * @param M 辺の数
 * @param edges 辺のリスト
 * @return 最小削除辺数
 */
int solve() {
    int N, M;
    // N: 頂点数, M: 辺の数
    if (!(cin >> N >> M)) return 0; 

    vector<Edge> edges(M);
    for (int i = 0; i < M; ++i) {
        // 頂点番号は 1 始まりなので、コード内では 0 始まりに変換するため -1 する
        cin >> edges[i].u >> edges[i].v;
        edges[i].u--; 
        edges[i].v--;
    }

    int max_edges_count = 0; // 残せる辺の最大数

    // ビット全探索: N個の頂点を V1(黒) と V2(白) に分割するすべての方法を試す
    // ループは 0 から 2^N - 1 まで
    // i の k ビット目が立っていれば、頂点 k は V1 (黒) に属するとする。
    for (int i = 0; i < (1 << N); ++i) {
        int current_edges_count = 0;
        
        // V1 と V2 に分けたときの、残せる辺の数を数える
        for (const auto& edge : edges) {
            int u = edge.u;
            int v = edge.v;

            // 頂点 u と v が異なる集合に属するかどうかを判定する

            // (i >> u) & 1: 頂点 u が V1 に属するか (ビットが立っているか)
            // (i >> v) & 1: 頂点 v が V1 に属するか (ビットが立っているか)
            
            // 異なる集合に属する場合 (XOR で判定)
            // (V1, V2) または (V2, V1) の辺であれば残せる
            if (((i >> u) & 1) != ((i >> v) & 1)) {
                current_edges_count++;
            }
        }

        // 残せる辺の最大数を更新
        max_edges_count = max(max_edges_count, current_edges_count);
    }

    // 最小削除辺数 = 元の辺の数 M - 最大残存辺数 max_edges_count
    return M - max_edges_count;
}

int main() {
    // 高速化
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << solve() << endl;

    return 0;
}