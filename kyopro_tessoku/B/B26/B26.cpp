#include <bits/stdc++.h>
using namespace std;

int N;

int main()
{
    // エラトステネスのふるいを使ってN以下の素数を列挙

    // 入力
    cin >> N;

    // エラトステネスのふるい
    vector<bool> is_prime(N + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i * i <= N; i++)
    {
        if (is_prime[i])
        {
            for (int j = 2 * i; j <= N; j += i)
            {
                is_prime[j] = false;
            }
        }
    }

    // 出力
    for (int i = 0; i <= N; i++)
    {
        if (is_prime[i])
        {
            cout << i << "\n";
        }
    }
    cout << flush;
    return 0;
}
