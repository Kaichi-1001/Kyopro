// 最後の状態は(1, 1)にすべてのコマがおかれている状態で、コマiの座標を(A_i, B_i)とするとき、
// ニム和は０である。
// 各操作のたびにニム和が=0, >0を繰り返す（1マス以上、好きな数移動できるから）ため、最初の状態でA_iとB_iのニム和が>0のときは先手が勝利、=0のときは後手が勝利となる。

#include <bits/stdc++.h>
using namespace std;

long long n, h, w, A[100009], B[100009];

int main()
{
    // 入力
    cin >> n >> h >> w;
    for (long long i = 1; i <= n; i++)
    {
        cin >> A[i] >> B[i];
    }

    // ニム和を計算する
    long long nim_sum = (A[1] - 1) ^ (B[1] - 1);
    if (n >= 2)
    {
        for (long long i = 2; i <= n; i++)
        {
            nim_sum ^= (A[i] - 1) ^ (B[i] - 1);
        }
    }

    // 答えを出力
    if (nim_sum)
    {
        cout << "First" << endl;
    }
    else
    {
        cout << "Second" << endl;
    }
}