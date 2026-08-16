#include <bits/stdc++.h>
using namespace std;

long long N, X, Y;
long long A[200009], B[200009];

int main()
{
    // input
    cin >> N >> X >> Y;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> B[i];
    }

    // 甘さが超えるか、しょっぱさが超えるかの2通りしかないので、それぞれソートからの累積和で検証
    sort(A, A + N, greater<long long>());
    sort(B, B + N, greater<long long>());

    long long ans = 0;

    if (N > 1)
    {
        for (int i = 1; i < N; i++)
        {
            A[i] += A[i - 1];
            B[i] += B[i - 1];
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (A[i] > X || B[i] > Y)
        {
            ans = i + 1;
            break;
        }
    }

    if (ans == 0)
    {
        ans = N;
    }

    // output
    cout << ans << endl;
    return 0;
}