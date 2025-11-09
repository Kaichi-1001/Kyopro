#include <bits/stdc++.h>
using namespace std;

int H, B;

int main()
{
    // 入力
    cin >> H >> B;
    // 出力
    if (H > B)
    {
        cout << H - B << endl;
    }
    else
    {
        cout << 0 << endl;
    }
    return 0;
}