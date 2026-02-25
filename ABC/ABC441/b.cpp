#include <bits/stdc++.h>
using namespace std;

int N, M;
string S, T;
int Q;
vector<string> w, ans;

int main()
{
    // input
    cin >> N >> M >> S >> T >> Q;
    w.resize(Q);
    for (int i = 0; i < Q; i++)
    {
        cin >> w[i];
    }

    // w_iが高橋語か青木語かを調べる
    bool takahasi = false, aoki = false;
    for (int i = 0; i < Q; i++)
    {
        for (char c : w[i])
        {
            takahasi = false;
            for (int j = 0; j < N; j++)
            {
                if (S[j] == c)
                {
                    takahasi = true;
                }
            }
            if (!takahasi)
            {
                break;
            }
        }
        for (char c : w[i])
        {
            aoki = false;
            for (int j = 0; j < M; j++)
            {
                if (T[j] == c)
                {
                    aoki = true;
                }
            }
            if (!aoki)
            {
                break;
            }
        }
        if (takahasi && aoki)
        {
            ans.push_back("Unknown");
        }
        else if (takahasi)
        {
            ans.push_back("Takahashi");
        }
        else if (aoki)
        {
            ans.push_back("Aoki");
        }
    }

    // output
    for (int i = 0; i < Q; i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}