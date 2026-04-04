#include <bits/stdc++.h>
using namespace std;

int H, W;
vector<vector<char>> C(19, vector<char>(19, '#'));

int main()
{
    // input
    cin >> H >> W;

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (i == 0 || i == H - 1)
            {
                C[i][j] = '#';
            }
            else if (W > 1 &&j > 0 && j < W - 1)
            {
                C[i][j] = '.';
            }
        }
    }

    // output
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cout << C[i][j];
        }
        cout << "\n";
    }
    cout << flush;
    return 0;
}