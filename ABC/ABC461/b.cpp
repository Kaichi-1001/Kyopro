#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> A, B;
    int N;

    // input
    cin >> N;
    A.resize(N + 1);
    B.resize(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
    }
    for (int i = 1; i <= N; i++)
    {
        cin >> B[i];
    }

    for (int i = 1; i <= N; i++)
    {
        if (i != A[B[i]])
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}