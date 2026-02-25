#include <bits/stdc++.h>
using namespace std;

long long P, Q, X, Y;

int main()
{
    // input
    cin >> P >> Q >> X >> Y;

    // マス(X, Y)が黒いか
    if (X >= P && X < P + 100 && Y >= Q && Y < Q + 100)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}