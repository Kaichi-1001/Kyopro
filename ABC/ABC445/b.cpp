#include <bits/stdc++.h>
using namespace std;

int N;
string S[109], T[109];

int main()
{
    // input
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> S[i];
    }

    // S_iの最大の長さをmとしてとる
    int m = 0;
    for (int i = 1; i <= N; i++)
    {
        m = max(m, (int)S[i].size());
    }

    // T_iを一つずつ作成
    for (int i = 1; i <= N; i++)
    {
        int k = (m - S[i].size()) / 2;
        for (int j = 1; j <= k; j++)
        {
            T[i] += ".";
        }
        T[i] += S[i];
        for (int j = 1; j <= k; j++)
        {
            T[i] += ".";
        }

        
    }

    // Tをすべて出力
    for (int i = 1; i <= N; i++)
    {
            cout << T[i] << endl;
        }
        return 0;
}