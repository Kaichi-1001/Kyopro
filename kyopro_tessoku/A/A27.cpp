#include <bits/stdc++.h>
using namespace std;

long long A, B;

int main()
{
    // 入力
    cin >> A >> B;
    if (A < B)
    {
        swap(A, B);
    }
    // ユークリッドの互除法をもちいてA,Bの最大公約数を求める
    while (B != 0)
    {
        A = A % B;
        swap(A, B);
    }
    // 出力(Aが最大公約数になってる)
    cout << A << endl;
}