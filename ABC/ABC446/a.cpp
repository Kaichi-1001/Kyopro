#include <bits/stdc++.h>
using namespace std;

string S;

int main()
{
    // input
    cin >> S;

    // S[0]を小文字に直す
    S[0] = tolower(S[0]);

    // 先頭にOfを追加して出力
    cout << "Of" << S << endl;
    return 0;
}