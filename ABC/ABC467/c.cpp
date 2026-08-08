#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[200009], B[200009];
bool A1_even[200009], A1_odd[200009]; // true: odd, false: even

int main()
{
    // input
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < N - 1; i++)
    {
        cin >> B[i];
    }

    // initialize
    A1_even[0] = false;
    A1_odd[0] = true;

    // process
    for (int i = 0; i < N - 1; i++)
    {
        if (B[i] == 0)
        {
            A1_even[i + 1] = A1_even[i];
            A1_odd[i + 1] = A1_odd[i];
        }
        else
        {
            A1_even[i + 1] = !A1_even[i];
            A1_odd[i + 1] = !A1_odd[i];
        }
    }

    int A1_even_count = 0, A1_odd_count = 0;
    // A[0] is even
    for (int i = 0; i < N; i++)
    {
        if (A[i] % 2 == 0)
        {
            if (A1_even[i])
            {
                A1_even_count++;
            }
        }
        else
        {
            if (!A1_even[i])
            {
                A1_even_count++;
            }
        }
    }
    // A[0] is odd
    for (int i = 0; i < N; i++)
    {
        if (A[i] % 2 == 0)
        {
            if (A1_odd[i])
            {
                A1_odd_count++;
            }
        }
        else
        {
            if (!A1_odd[i])
            {
                A1_odd_count++;
            }
        }
    }

    cout << min(A1_even_count, A1_odd_count) << endl;

    return 0;
}