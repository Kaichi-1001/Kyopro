#include <bits/stdc++.h>
using namespace std;

long long N, K, X;
vector<long long> A = {0};

int main()
{
    // intput
    cin >> N >> K >> X;
    long long a;
    for (int i = 0; i < N; i++)
    {
        cin >> a;
        A.push_back(a);
    }

    // Aをソート
    sort(A.begin(), A.end());

    // 条件を満たすかを判定
    bool possible = false;

    long long current_sake = 0;
    long long count = 0;
    for (int i = K; i > 0; i--)
    {
        current_sake += A[i];
        count++;
        if (current_sake >= X)
        {
            possible = true;
            break;
        }
    }

    // output
    if (possible)
    {
        cout << count + (N - K) << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}