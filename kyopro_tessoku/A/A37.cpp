#include <bits/stdc++.h>
using namespace std;

long long N, M, A[200009], B, C[200009];

int main()
{
    // 入力
    cin >> N >> M >> B;
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
    }
    for (int i = 1; i <= M; i++)
    {
        cin >> C[i];
    }

    // それぞれ何回足されるかを考えて計算
    long long sum = 0;
    for (int i = 1; i <= N; i++)
    {
        sum += A[i] * M;
    }
    sum += B * N * M;
    for (int i = 1; i <= M; i++)
    {
        sum += C[i] * N;
    }
    // 出力
    cout << sum << endl;
    return 0;
}