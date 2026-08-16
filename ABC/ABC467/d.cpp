#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long Px, Py, Qx, Qy, Rx, Ry, Sx, Sy;
    cin >> Px >> Py >> Qx >> Qy >> Rx >> Ry >> Sx >> Sy;

    // L_PQ: a1*x + b1*y = c1
    long long a1 = 2 * (Qx - Px);
    long long b1 = 2 * (Qy - Py);
    long long c1 = (Qx * Qx + Qy * Qy) - (Px * Px + Py * Py);

    // L_RS: a2*x + b2*y = c2
    long long a2 = 2 * (Sx - Rx);
    long long b2 = 2 * (Sy - Ry);
    long long c2 = (Sx * Sx + Sy * Sy) - (Rx * Rx + Ry * Ry);

    // 行列式（外積）の計算 (オーバーフロー防止のため __int128_t にキャスト)
    __int128_t det = (__int128_t)a1 * b2 - (__int128_t)a2 * b1;

    if (det != 0) {
        // 平行でないなら必ず1つの中心（交点）が存在する
        cout << "Yes\n";
    } else {
        // 平行な場合、垂直二等分線が完全に一致するかを判定
        __int128_t det_x = (__int128_t)c1 * b2 - (__int128_t)c2 * b1;
        __int128_t det_y = (__int128_t)a1 * c2 - (__int128_t)a2 * c1;
        
        if (det_x == 0 && det_y == 0) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}