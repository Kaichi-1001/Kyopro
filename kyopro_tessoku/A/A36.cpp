#include <bits/stdc++.h>
using namespace std;

long long n, k;

int main()
{
    // input
    cin >> n >> k;

    // k - (2*n - 2) が偶数ならゴールできる
    bool goal = false;
    if (k < 2*n - 2)
    {
        goal = false;
    }
    else if ((k - (2*n - 2)) % 2 == 0)
    {
        goal = true;
    }

    // output
    if (goal)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}