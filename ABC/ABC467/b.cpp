#include <bits/stdc++.h>
using namespace std;

int N;
int A[109], B[109];
string S[109];

int main()
{
    int X = 10000, Y = 10000;

    // input
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i] >> B[i] >> S[i];
    }

    for (int i = 0; i < N; i++)
    {
        if (S[i] == "keep")
        {
            X -= B[i];
        }
        else if (S[i] == "take")
        {
            X -= A[i];
        }

        Y -= A[i];
    }

    // output
    cout << Y - X << endl;

    return 0;
}