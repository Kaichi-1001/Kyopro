#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, Q;
    cin >> N >> Q;
    vector<int> P(N + 1, 0);
    vector<int> P_(N + 1, 0); // P_[i] = where i is in P

    for (int i = 1; i <= N; i++)
    {
        cin >> P[i];
        P_[P[i]] = i;
    }

    bool PorP_ = true; // true when the target is P
    int q, x, y;
    for (int i = 0; i < Q; i++)
    {
        cin >> q;
        if (q == 1)
        {
            cin >> x >> y;
            if (PorP_)
            {
                swap(P[x], P[y]);
                P_[P[x]] = x;
                P_[P[y]] = y;
            }
            else
            {
                swap(P_[x], P_[y]);
                P[P_[x]] = x;
                P[P_[y]] = y;
            }
        }
        else
        {
            PorP_ = !PorP_;
        }
    }

    // output
    if (PorP_)
    {
        for (int i = 1; i <= N; i++)
        {
            cout << P[i] << " ";
        }
    }
    else
    {
        for (int i = 1; i <= N; i++)
        {
            cout << P_[i] << " ";
        }
    }
    cout << endl;
}