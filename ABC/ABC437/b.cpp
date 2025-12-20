#include <bits/stdc++.h>
using namespace std;

int h, w, n;
int A[4][6], B[100];

int main()
{
    // input
    cin >> h >> w >> n;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            cin >> A[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> B[i];
    }

    // 処理
    int ans = 0;
    int count = 0;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (A[i][j] == B[k])
                {
                    count++;
                }
            }
        }
        ans = max(ans, count);
        count = 0;
    }

    // output
    cout << ans << endl;
    return 0;
}