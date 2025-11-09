#include <bits/stdc++.h>
using namespace std;

int N, M, K;
vector<long long> H;
vector<long long> B;

int main() {
    // 入力
    cin >> N >> M >> K;
    H.resize(N+1);
    B.resize(M+1);
    for (int i = 1; i <= N; i++) {
        cin >> H[i];
    }
    for (int i = 1; i <= M; i++) {
        cin >> B[i];
    }

    // HとBをソート
    sort(H.begin(), H.end());
    sort(B.begin(), B.end());

    // 作れるロボットを数える（尺取り法をつかう）
    int L = min(N, M);
    int count = 0;
    int kokokara = 1;
    for (int i = 1; i <= L; i++) {
        int pos = lower_bound(B.begin() + kokokara, B.end(), H[i]) - B.begin();
        int s = B.size();
        kokokara = pos + 1;
        if (pos < s) {
            count++;
        }
    }

    // 出力
    if (count >= K) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}