#include <bits/stdc++.h>
using namespace std;

long long N, A[100009], answer;
string T[100009];

int main()
{
    // 入力
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> T[i] >> A[i];

    // N個のクエリに回答
    for (int i = 1; i <= N; i++)
    {
        if (T[i] == "+")
        {
            answer += A[i];
        }
        else if (T[i] == "-")
        {
            answer -= A[i];
        }
        else if (T[i] == "*")
        {
            answer *= A[i];
        }

        answer = answer >= 10000 ? answer % 10000 : answer + 10000;

        cout << answer % 10000 << "\n";
    }

    cout << flush;
    return 0;
}