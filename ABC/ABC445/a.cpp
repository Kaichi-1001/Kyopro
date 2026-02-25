#include <bits/stdc++.h>
using namespace std;

string S;

int main()
{
    // input
    cin >> S;

    // 先頭と末尾が同じか判定して出力
    if (S[0] == S[S.size() - 1])
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}