#include <bits/stdc++.h>
using namespace std;

int H, W, K, grid[509][509];
int A[509];
int bucket[509]; // ゼロクリアの対象なので、ここで定義しても問題ありません

int main()
{
    // 高速入出力
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> H >> W >> K)) return 0;
    
    string S;
    for (int i = 0; i < H; i++)
    {
        cin >> S;
        for (int j = 0; j < W; j++)
        {
            grid[i + 1][j + 1] = (S[j] == '1') ? 1 : 0;
        }
    }

    // 列の累積和
    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            grid[i][j] += grid[i - 1][j];
        }
    }

    long long ans = 0;
    // 修正1: r1 は H まで、r2 は r1 から開始する
    for (int r1 = 1; r1 <= H; r1++)
    {
        for (int r2 = r1; r2 <= H; r2++)
        {
            for (int j = 1; j <= W; j++)
            {
                A[j] = grid[r2][j] - grid[r1 - 1][j];
            }

            // バケットの初期化
            for (int i = 0; i <= 500; i++)
            {
                bucket[i] = 0;
            }
            
            // 修正2-1: 左端が1列目のときのために、初期累積和0をあらかじめセット
            bucket[0] = 1; 

            for (int j = 1; j <= W; j++)
            {
                A[j] += A[j - 1];
                
                // 修正2-2: 加算する前に、条件を満たす過去の累積和の数を答えに足す
                if (A[j] - K >= 0 && A[j] - K <= 500)
                {
                    ans += (long long)bucket[A[j] - K];
                }
                
                // 修正2-3: 答えに足し終わったあとに、現在の累積和を記録する
                if (A[j] <= 500)
                {
                    bucket[A[j]]++;
                }
            }

            // reset
            for (int j = 1; j <= W; j++)
            {
                A[j] = 0;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}