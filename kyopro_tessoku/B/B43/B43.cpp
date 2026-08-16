#include <bits/stdc++.h>
using namespace std;
// Ai以外が正解はAiだけがまちがいで、-1していけばいい
int N, M, A[200009];

int main()
{
    // input
    cin >> N >> M;
    for (int i = 1; i <= M; i++)
    {
        cin >> A[i];
    }

    // 全員M問正解から初めて、一人ずつ1を引いていけばいい
    vector<int> scores(200009, M);
    for (int i = 1; i <= M; i++)
    {
        scores[A[i]]--;
    }

    // output
    for (int i = 1; i <= N; i++)
    {
        cout << scores[i] << "\n";
    }
    cout << flush;
    return 0;
}