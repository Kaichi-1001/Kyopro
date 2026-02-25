#include <bits/stdc++.h>
using namespace std;
// i <= A_i <= Nに注目して、後ろから決定
int N;
int A[500009], B[500009];

int main()
{
    // input
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
    }

    // 後ろからB（各sの移動後の位置が決まる）
    for (int i = N; i >= 1; i--)
    {
        if (A[i] == i)
        {
            B[i] = i;
        }
        else
        {
            B[i] = B[A[i]];
        }
    }

    // 答えを出力
    for (int i = 1; i <= N; i++)
    {
        cout << B[i] << " ";
    }
    cout << endl;
    return 0;
}