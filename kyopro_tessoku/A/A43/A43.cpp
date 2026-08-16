#include <bits/stdc++.h>
using namespace std;

// ぶつかって反対方向に進むのは、すれ違うのと等価である
long long N, L;
long long A[200009];
char B[200009];

int main() {
    // input
    cin >> N >> L;
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i] >> B[i];
    }

    // i人目のトンネルを出るまでの距離を計算
    vector<long long> dist(N+1, 0);
    for (int i = 1; i <= N; i++)
    {
        if (B[i] == 'E')
        {
            dist[i] = L - A[i];
        }
        else if (B[i] == 'W')
        {
            dist[i] = A[i];
        }
    }

    // 最大値を探索して答えを出力
    long long ans = 0;
    for (int i = 1; i <= N; i++)
    {
        ans = max(ans, dist[i]);
    }

    cout << ans << endl;
    
}