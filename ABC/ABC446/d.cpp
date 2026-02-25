#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    // input
    int N;
    cin >> N;

    // dp[x] := 値 x を末尾とする条件を満たす部分列の最大長
    map<int, int> dp;
    int max_len = 0;

    for (int i = 0; i < N; ++i)
    {
        int a;
        cin >> a;

        // 値 a を追加する場合、値 (a-1) で終わる列の長さに 1 を足す
        // mapは存在しないキーにアクセスすると自動で 0 を返すので、初期化不要です
        dp[a] = dp[a - 1] + 1;

        // 全体の最大長を随時更新しておく
        max_len = max(max_len, dp[a]);
    }

    // 答えを出力
    cout << max_len << "\n";

    return 0;
}