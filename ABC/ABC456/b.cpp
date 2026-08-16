#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dice(4, vector<int>(7));
vector<vector<double>> cnt(4, vector<double>(7));

int main()
{
    // input
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            cin >> dice[i][j];
        }
    }

    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            cnt[i][dice[i][j]]++;
        }
    }

    // 確率を求める
    double ans = (cnt[1][4] / 6) * ((cnt[2][5] / 6) * (cnt[3][6] / 6) + (cnt[2][6] / 6) * (cnt[3][5] / 6)) +
                 (cnt[1][5] / 6) * ((cnt[2][4] / 6) * (cnt[3][6] / 6) + (cnt[2][6] / 6) * (cnt[3][4] / 6)) +
                 (cnt[1][6] / 6) * ((cnt[2][4] / 6) * (cnt[3][5] / 6) + (cnt[2][5] / 6) * (cnt[3][4] / 6));

    cout << fixed << setprecision(7) << ans << endl;
    return 0;
}