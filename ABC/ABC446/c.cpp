#include <bits/stdc++.h>
using namespace std;

long long T, N, D, A[200009], B[200009], syori_sum[200009], eggs[200009];

int main()
{
    // input T
    cin >> T;

    vector<long long> ans = {};

    // T個のテストケース
    while (T > 0)
    {
        T--;

        // 初期化
        for (int i = 1; i <= 200000; i++)
        {
            eggs[i] = 0;
            syori_sum[i] = 0;
        }

        // input
        cin >> N >> D;
        for (int i = 1; i <= N; i++)
        {
            cin >> A[i];
        }
        for (int i = 1; i <= N; i++)
        {
            cin >> B[i];
        }

        // 累積和を使って処理（くさった卵の処理はまだ）
        // 腐った卵の処理のために、i日目までに仕入れた卵の数、i日目までに使用した卵の数を数える必要がある。
        for (int i = 1; i <= N; i++)
        {
            A[i] += A[i - 1];
            B[i] += B[i - 1];
        }

        // 腐った卵の処理を考えつつ、i日目の終わりに所有している卵の数を考える
        long long syori = 0;
        for (int i = 1; i <= N; i++)
        {
            if (i <= D) // 処理する卵はない
            {
                eggs[i] = A[i] - B[i] - syori;
            }
            else // 処理する卵が存在する可能性がある
            {
                long long a = A[i - D];
                long long b = B[i] + syori_sum[i - 1];

                if (a >= b)
                {
                    syori = a - b;
                    eggs[i] = A[i] - B[i] - syori_sum[i - 1] - syori;
                }
                else
                {
                    syori = 0;
                    eggs[i] = A[i] - B[i] - syori_sum[i - 1] - syori;
                }

                syori_sum[i] = syori_sum[i - 1] + syori;
            }
        }

        ans.push_back(eggs[N]);
    }

    // output
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}