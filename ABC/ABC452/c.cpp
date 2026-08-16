#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[19], B[19];
vector<string> S(200009, "");
vector<vector<vector<bool>>> can_use(19, vector<vector<bool>>(19, vector<bool>(26, false)));
// can_use[i][j][k] := i文字の文字列のj文字目に使用することができる文字k番目のアルファベット
vector<bool> ans(200009, true);

int main()
{
    // input
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i] >> B[i];
    }
    cin >> M;
    for (int i = 1; i <= M; i++)
    {
        cin >> S[i];
    }

    // 先にcan_useの情報を得る
    for (int i = 1; i <= M; i++)
    {
        int size = S[i].size();
        for (int j = 1; j <= size; j++)
        {
            int k = S[i][j - 1] - 'a';
            can_use[size][j][k] = true;
        }
    }

    // can_useの情報をもとに、Siが脊椎として使用できるかどうかを判定
    for (int i = 1; i <= M; i++)
    {

        int s_size = S[i].size();
        if (s_size == N)
        {
            for (int j = 1; j <= s_size; j++)
            {
                int s_k = S[i][j - 1] - 'a';
                if (!can_use[A[j]][B[j]][s_k])
                {
                    ans[i] = false;
                    break;
                }
            }
        }
        else
        {
            ans[i] = false;
        }
    }

    // output
    for (int i = 1; i <= M; i++)
    {
        if (ans[i])
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    cout << flush;
    return 0;
}