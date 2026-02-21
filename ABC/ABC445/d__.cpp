#include <bits/stdc++.h>
using namespace std;

long long H, W, N;
struct Piece
{
    long long h, w;
    // int id; // pieces[i]のインデックスがIDなのでメンバ変数は不要
};
struct result
{
    long long x, y;
};

int main()
{
    // 入力高速化
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // input
    cin >> H >> W >> N;
    vector<Piece> pieces(N);
    for (int i = 0; i < N; i++)
    {
        cin >> pieces[i].h >> pieces[i].w;
        // pieces[i].id = i;
    }

    // 準備参照用
    vector<int> order_h(N);
    vector<int> order_w(N);

    // ★重要：初期化（連番を入れる）
    iota(order_h.begin(), order_h.end(), 0); // 0, 1, 2...
    iota(order_w.begin(), order_w.end(), 0);

    // それぞれソート
    sort(order_h.begin(), order_h.end(), [&](int a, int b)
         { return pieces[a].h < pieces[b].h; });

    sort(order_w.begin(), order_w.end(), [&](int a, int b)
         { return pieces[a].w < pieces[b].w; });

    // 現在の状態
    long long current_h = H;
    long long current_w = W;
    long long current_x = 1;
    long long current_y = 1;

    vector<bool> used(N, false); // 使ったかどうかのフラグ
    vector<result> ans(N);       // 答え

    int count = 0; // 配置した個数

    // ピースを削っていく
    // N個すべて配置するまでループ
    while (count < N)
    {
        // --- 縦チェック ---
        // emptyチェックが必須
        if (!order_h.empty())
        {
            int idx = order_h.back(); // 末尾の要素（ID）

            // 既に使用済みなら捨てる
            if (used[idx])
            {
                order_h.pop_back();
                continue;
            }

            // 高さが一致するか？
            if (pieces[idx].h == current_h)
            {
                // 採用処理
                ans[idx].x = current_x;
                ans[idx].y = current_y;

                // 縦が一致した = 左端に置く = 幅(w)が減る
                current_w -= pieces[idx].w;
                current_y += pieces[idx].w;

                used[idx] = true;
                order_h.pop_back();
                count++;  // カウントアップ
                continue; // 次のループへ
            }
        }

        // --- 横チェック ---
        if (!order_w.empty())
        {
            int idx = order_w.back();

            if (used[idx])
            {
                order_w.pop_back();
                continue;
            }

            // 幅が一致するか？（縦チェックを通らなかったら必ずここに来るはず）
            if (pieces[idx].w == current_w)
            {
                // 採用処理
                ans[idx].x = current_x;
                ans[idx].y = current_y;

                // 横が一致した = 上端に置く = 高さ(h)が減る
                current_h -= pieces[idx].h;
                current_x += pieces[idx].h;

                used[idx] = true;
                order_w.pop_back();
                count++;
                continue;
            }
        }
    }

    // 答えを出力
    for (int i = 0; i < N; i++)
    {
        cout << ans[i].x << " " << ans[i].y << "\n";
    }
    return 0;
}