#include <bits/stdc++.h>
using namespace std;

int H, W;
vector<vector<char>> cookie(509, vector<char>(509, '.'));

int main()
{
    // 入力
    cin >> H >> W;
    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            cin >> cookie[i][j];
        }
    }

    // すぬけ君が食べたクッキーの位置を特定
    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (cookie[i][j] == '.')
            {
                if (cookie[i][j - 1] == '#' && cookie[i][j + 1] ==  '#')
                {
                    cout << i << " " << j << endl;
                }
                else if (cookie[i + 1][j] == '#' && cookie[i][j + 1] == '#')
                {
                    cout << i << " " << j << endl;
                }
                else if (cookie[i + 1][j] == '#' && cookie[i][j - 1] == '#')
                {
                    cout << i << " " << j << endl;
                }
                else if (cookie[i - 1][j] == '#' && cookie[i][j + 1] == '#')
                {
                    cout << i << " " << j << endl;
                }
                else if (cookie[i - 1][j] == '#' && cookie[i][j - 1] == '#')
                {
                    cout << i << " " << j << endl;
                }
                else if (cookie[i - 1][j] == '#' && cookie[i + 1][j] == '#')
                {
                    cout << i << " " << j << endl;
                }
            }
        }
    }
}