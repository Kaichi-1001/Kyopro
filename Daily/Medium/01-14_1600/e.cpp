#include <bits/stdc++.h>
using namespace std;

vector<bool> dp((1 << 18), false);
int T, N;
string S;

int main()
{
    // input
    cin >> T;

    vector<string> ans;
    // 各クエリに回答
    while (T)
    {
        T--;
        cin >> N >> S;
        S = "0" + S;

        vector<bool> dp_T = dp;
        dp_T[0] = true;
        for (int i = 0; i < (1 << N); i++)
        {
            if (dp_T[i] == false)
                continue;
            if (dp_T[i] == true)
            {
                for (int j = 0; j < N; j++)
                {
                    if (i & (1 << j))
                        continue;
                    if (S[i | (1 << j)] == '0')
                    {
                        dp_T[i | (1 << j)] = true;
                    }
                }
            }
        }
        if (dp_T[(1 << N) - 1])
        {
            ans.push_back("Yes");
        }
        else
        {
            ans.push_back("No");
        }
    }

    // output
    for (string s : ans)
    {
        cout << s << "\n";
    }
    cout << flush;
    return 0;
}