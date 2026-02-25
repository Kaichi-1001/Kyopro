#include <bits/stdc++.h>
using namespace std;

int N, M, L[109];
vector<vector<int>> want_list(109, vector<int>(109, 0));
vector<int> ans_list(109, 0);
vector<bool> took_list(109, false);

int main()
{
    // input
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int l;
        cin >> l;
        L[i] = l;
        for (int j = 0; j < l; j++)
        {
            cin >> want_list[i][j];
        }
    }

    // 客1から希望を満たしていく
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (took_list[want_list[i][j]] == false)
            {
                took_list[want_list[i][j]] = true;
                ans_list[i] = want_list[i][j];
                break;
            }

            if (j >= L[i])
            {
                ans_list[i] = 0;
                break;
            }
        }
    }

    // output
    for (int i = 0; i < N; i++)
    {
        cout << ans_list[i] << endl;
    }
    return 0;
}