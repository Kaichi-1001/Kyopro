#include <bits/stdc++.h>
using namespace std;

int main()
{
    // input
    int N, X;
    string A;
    cin >> N >> X >> A;

    queue<int> q;
    q.push(X);
    A[X - 1] = '@';
    while (!q.empty())
    {
        int pos = q.front();
        q.pop();
        if (pos > 1 && A[pos - 2] == '.')
        {
            A[pos - 2] = '@';
            q.push(pos - 1);
        }
        if (pos < N && A[pos] == '.')
        {
            A[pos] = '@';
            q.push(pos + 1);
        }
    }

    // output
    cout << A << endl;
    return 0;
}