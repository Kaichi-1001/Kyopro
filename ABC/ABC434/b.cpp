#include <bits/stdc++.h>
using namespace std;

int N, M, A[109], B[109];
double kazu[109], omosa[109];

int main() {
    // 入力
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        cin >> B[i];
    }

    // 各種類の重さの合計と数を計算（全探索）
    for (int i = 1; i <= N; i++) {
        kazu[A[i]]++;
        omosa[A[i]]+=B[i];
    }

    // 出力
    for (int i = 1; i <= M; i++)
    {
        cout << fixed << setprecision(10) << omosa[i]/kazu[i] << "\n";
    }
    cout << flush;
    
}