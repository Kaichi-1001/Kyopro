#include <bits/stdc++.h>
using namespace std;

long long N, Q;
vector<vector<int>> A(509, vector<int>(509, 0));

int main()
{
    // input
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> A[i][j];
        }
    }
    cin >> Q;

    // 行の状態を表す状態配列
    vector<int> row(509, 0);

    // initialize
    for (int i = 1; i <= 500; i++)
    {
        row[i] = i;
    }

    // array for the answer
    vector<int> answer = {};

    // 各クエりに回答
    int q, x, y;
    while (Q)
    {
        Q--;
        cin >> q;
        switch (q)
        {
        case 1:
            cin >> x >> y;
            swap(row[x], row[y]);
            break;

        case 2:
            cin >> x >> y;
            answer.push_back(A[row[x]][y]);
            break;
        }
    }

    // output the answer
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << endl;
    }

    return 0;
}