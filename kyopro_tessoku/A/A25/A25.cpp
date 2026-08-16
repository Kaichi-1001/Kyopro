#include <bits/stdc++.h>
using namespace std;

int h, w;
vector<vector<char>> c(39, vector<char>(39, '#'));
long long dp[39][39];

int main() {
    // 入力
    cin >> h >> w;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> c[i][j];
        }
    }
    
    // dpの初期化
    dp[1][1] = 1;
    
    // 貰う繊維形式の動的計画法
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (c[i][j] == '.' && (i != 1 || j != 1)) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    
    // 出力
    cout << dp[h][w] << endl;
}