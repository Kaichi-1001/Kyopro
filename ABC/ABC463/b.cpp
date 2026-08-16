#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    char X;
    string S[109];
    cin >> N >> X;
    for (int i = 0; i < N; i++)
    {
        cin >> S[i];
    }

    bool vacant = false;

    int retu = X - 'A';
    for (int i = 0; i < N; i++)
    {
        if (S[i][retu] == 'o')
        {
            vacant = true;
            break;
        }
    }

    if (vacant)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}