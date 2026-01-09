// ポイントはAによる影響とBによる影響を分けて、必要条件と必要条件を掛け合わせること
// 文字が切り替わるときにリセットされるから、何文字連続するかのみみればOK 
// 前から見ていって、i文字目まででAがm個連続する場合、i+1番目の草の長さはm+1以上であることが必要
// 後ろから見ていって、i文字目まででBがn個連続する場合、i番目の草の長さはn+1以上であることが必要
// これらから、i番目の草の長さはmax(m_i+1, n_i+1)以上であることが必要であり、逆にこのとき十分である
#include <bits/stdc++.h>
using namespace std;

long long N, M_i[3009], N_i[3009];
string S;

int main() {
    // input
    cin >> N >> S;

    // 初期化
    M_i[0] = 1;
    N_i[N-1] = 1;

    // 前から見て、Aの連続数を数える
    int A_renzoku = 1;
    for (int i = 0; i < N-1; i++) {
        if (S[i] == 'A') {
            A_renzoku++;
        }
        if (S[i] == 'B') {
            A_renzoku = 1;
        }
        M_i[i+1] = A_renzoku;
    }
    
    // 後ろから見て、Bの連続数を数える
    int B_renzoku = 1;
    for (int i = N-2; i >= 0; i--) {
        if (S[i] == 'B') {
            B_renzoku++;
        }
        if (S[i] == 'A') {
            B_renzoku = 1;
        }
        N_i[i] = B_renzoku;
    }

    // 答えを計算して出力
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans += max(M_i[i], N_i[i]);
    }
    cout << ans << endl;
    return 0;
}