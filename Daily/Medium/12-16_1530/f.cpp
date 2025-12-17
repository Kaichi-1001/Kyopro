#include <bits/stdc++.h>
using namespace std;

long long N;
int Q, T[200009], A[200009], B[200009];
vector<vector<int>> follow(1000000009, vector<int>(1000000009, 0));

int main()
{
    // 入力
    cin >> N >> Q;
    for (int i = 1; i <= Q; i++)
    {
        cin >> T[i] >> A[i] >> B[i];
    }

    // 前処理
    vector<string> answer = {};

    // クエリに回答
    for (int i = 1; i <= Q; i++)
    {
        if (T[i] == 1)
        {
            follow[A[i]][B[i]] = 1;
        }
        else if (T[i] == 2)
        {
            follow[A[i]][B[i]] = 0;
        }
        else if (T[i] == 3)
        {
            if (follow[A[i]][B[i]] == 1)
            {
                answer.push_back("Yes");
            }
            else
            {
                answer.push_back("No");
            }
        }
    }
    // 答えを出力
    for (string s : answer)
    {
        cout << s << endl;
    }
    return 0;
}