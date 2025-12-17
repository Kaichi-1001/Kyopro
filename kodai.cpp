#include <bits/stdc++.h>
using namespace std;

int N, length;
char syurui[30];

// Nのlength乗を返す関数
long long powN(int N, int length)
{
    long long result = 1;
    for (int i = 0; i < length; i++)
    {
        result *= N;
    }
    return result;
}

int main()
{
    // 入力
    cin >> N >> length;
    for (int i = 0; i < N; i++)
    {
        cin >> syurui[i];
    }

    vector<string> answer = {};

    // lengthの長さの文字列を全探索
    for (long long i = 0; i < powN(N, length); i++)
    {
        string youso = {};
        for (long long j = length-1; j >= 0; j--)
        {
            long long wari = powN(N, j);
            youso.push_back(syurui[(i / wari)%N]);
        }

        answer.push_back(youso);
        youso = {};
    }

    // 出力
    for (string s : answer)
    {
        cout << s << "\n";
    }
    cout << flush;
    return 0;
}