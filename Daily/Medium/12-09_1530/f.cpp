#include <bits/stdc++.h>
using namespace std;

int h, w;
vector<vector<char>> hw(509, vector<char>(509, '.'));

int main()
{
    // 入力
    cin >> h >> w;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            cin >> hw[i][j];
        }
    }

    // 処理
    bool move = true;
    int i = 1, j = 1;
    while (move)
    {
        if (hw[i][j] == 'U')
        {
            if (i == 1)
            {
                move = false;
            }
            else
            {
                hw[i][j] = '.';
                i--;
            }
        }
        if (hw[i][j] == 'D')
        {
            if (i == h)
            {
                move = false;
            }
            else
            {
                hw[i][j] = '.';
                i++;
            }
        }
        if (hw[i][j] == 'L')
        {
            if (j == 1)
            {
                move = false;
            }
            else
            {
                hw[i][j] = '.';
                j--;
            }
        }
        if (hw[i][j] == 'R')
        {
            if (j == w)
            {
                move = false;
            }
            else
            {
                hw[i][j] = '.';
                j++;
            }
        }
        if (hw[i][j] == '.')
        {
            break;
        }
    }

    // 出力
    if (move)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << i << " " << j << endl;
    }
    return 0;
}