#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[100009], B[100009];
int main()
{
    // input
    cin >> N >> M;
    for (int i = 1; i <= M; i++)
    {
        cin >> A[i] >> B[i];
    }

    // initialize
    vector<int> students(100009, 0);

    // 友達の数を数える
    for (int i = 1; i <= M; i++)
    {
        students[A[i]]++;
        students[B[i]]++;
    }

    // 友達の一番多い生徒の番号を出力
    int ans = 1;
    int max = 0;
    for (int i = 1; i <= N; i++)
    {
        if (students[i] > max)
        {
            max = students[i];
            ans = i;
        }
    }

    cout << ans << endl;
    return 0;
}