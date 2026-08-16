#include <bits/stdc++.h>
using namespace std;

// Wはスコア0, Bはスコア1, Rはスコア2として合計を算出すると、各操作の前後でmod3の値は変わらない 
int N;
char C;
string A;

int main() {
    // input
    cin >> N >> C >> A;

    // スコアで処理
    int C_score = (C == 'W') ? 0 : (C == 'B') ? 1 : 2;
    int score = 0;
    for (char c : A)
    {
        score += (c == 'W') ? 0 : (c == 'B') ? 1 : 2;
    }

    // 判定して出力
    if (score % 3 == C_score)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}