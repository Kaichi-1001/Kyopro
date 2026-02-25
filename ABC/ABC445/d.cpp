#include <bits/stdc++.h>
using namespace std;

long long H, W, N;
struct Piece
{
    long long h, w;
    int id;
};
struct result
{
    long long x, y;
};

int main()
{
    // input
    cin >> H >> W >> N;
    vector<Piece> pieces(N);
    for (int i = 0; i < N; i++)
    {
        cin >> pieces[i].h >> pieces[i].w;
        pieces[i].id = i;
    }

    // 準備参照用
    vector<int> order_h(N);
    vector<int> order_w(N);
    iota(order_h.begin(), order_h.end(), 0); 
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

    // ピースを削っていく
    while (current_h > 0 && current_w > 0)
    {
        if (pieces[order_h[order_h.size() - 1]].h == current_h)
        {
            if (used[order_h[order_h.size() - 1]])
            {
                order_h.pop_back();
                continue;
            }
            else
            {
                ans[pieces[order_h[order_h.size() - 1]].id].x = current_x;
                ans[pieces[order_h[order_h.size() - 1]].id].y = current_y;
                current_w -= pieces[order_h[order_h.size() - 1]].w;
                current_y += pieces[order_h[order_h.size() - 1]].w;
                used[order_h[order_h.size() - 1]] = true;
                order_h.pop_back();
                continue;
            }
        }
        if (pieces[order_w[order_w.size() - 1]].w == current_w)
        {
            if (used[order_w[order_w.size() - 1]])
            {
                order_w.pop_back();
                continue;
            }
            else
            {
                ans[pieces[order_w[order_w.size() - 1]].id].x = current_x;
                ans[pieces[order_w[order_w.size() - 1]].id].y = current_y;
                current_h -= pieces[order_w[order_w.size() - 1]].h;
                current_x += pieces[order_w[order_w.size() - 1]].h;
                used[order_w[order_w.size() - 1]] = true;
                order_w.pop_back();
                continue;
            }
        }
    }

    // 答えを出力
    for (int i = 0; i < N; i++)
    {
        cout << ans[i].x << " " << ans[i].y << endl;
    }
    return 0;
}