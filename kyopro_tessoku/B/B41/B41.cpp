#include <bits/stdc++.h>
using namespace std;

long long X, Y;
vector<long long> answer_X = {};
vector<long long> answer_Y = {};

int main()
{
    // input
    cin >> X >> Y;

    // 互除法を足し算のみの形式で
    int K = 0;
    while (X > 1 || Y > 1)
    {
        K++;
        if (X > Y)
        {
            answer_X.push_back(X);
            answer_Y.push_back(Y);
            X = X - Y;
        }
        else if (X < Y)
        {
            answer_X.push_back(X);
            answer_Y.push_back(Y);
            Y = Y - X;
        }
    }

    // output answer_X, answer_Yを後ろから出力
    cout << K << "\n";
    for (int i = K - 1; i >= 0; i--)
    {
        cout << answer_X[i] << " " << answer_Y[i] << "\n";
    }
    return 0;
}