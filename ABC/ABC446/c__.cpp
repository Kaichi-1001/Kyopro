#include <bits/stdc++.h>
using namespace std;

long long T, N, D, A[200009], B[200009], eggs[200009];

int main()
{
    cin >> T;

    while (T > 0)
    {
        T--;

        cin >> N >> D;
        for (int i = 1; i <= N; i++)
        {
            cin >> A[i] >> B[i];
        }

        // 累積和を計算（仕入れた総数と、消費した総数）
        for (int i = 1; i <= N; i++)
        {
            A[i] += A[i - 1];
            B[i] += B[i - 1];
        }

        long long discarded = 0; // これまでに腐って破棄した卵の総数

        for (int i = 1; i <= N; i++)
        {
            // i日目の昼の時点で、すでに「消費された」または「破棄された」卵の合計
            long long exited = B[i] + discarded;

            // i日目の夜には、(i-D)日目以前に仕入れた卵はすべて無くなっていなければならない
            // ※もし「D日経過＝当日の夜を含めてD日目の夜」という意味なら、ここを A[i - D + 1] に変更してください。
            long long expired_target = 0;
            if (i - D >= 1)
            {
                expired_target = A[i - D];
            }

            // もし「無くなった卵(exited)」が「無くなっていなければならない卵(expired_target)」より少ないなら
            // その差分がまだ在庫に残ってしまっているので、ここで破棄する
            if (exited < expired_target)
            {
                discarded += (expired_target - exited);
                exited = expired_target; // 破棄したことで、無くなった卵の合計が目標値に追いつく
            }

            // i日目の終わりに残っている卵 ＝ (これまで仕入れた総数) - (これまで無くなった総数)
            eggs[i] = A[i] - exited;
        }

        cout << eggs[N] << "\n";
    }

    cout << flush;
    return 0;
}