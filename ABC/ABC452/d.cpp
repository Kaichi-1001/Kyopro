#include <bits/stdc++.h>
using namespace std;

string S, T;
vector<vector<int>> nxt(200009, vector<int>(26, 0));

int main()
{
    // input
    cin >> S >> T;

    // next配列を作成
    // S.size() 番目のインデックス（範囲外）を S.size() で初期化
    for (int j = 0; j < 26; j++)
    {
        nxt[S.size()][j] = S.size();
    }
    
    // S.size() - 1 から 0 に向かって埋める
    for (int i = S.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j < 26; j++) // 'z'-'a' ではなく 26 に修正
        {
            if (S[i] - 'a' == j)
            {
                nxt[i][j] = i;
            }
            else
            {
                nxt[i][j] = nxt[i + 1][j]; // nxt[S.size()][j] を正しく参照できる
            }
        }
    }

    // Sの各スタート地点iから条件を満たす部分列の個数を数える
    long long ans = 0;
    for (int i = 0; i < S.size(); i++)
    {
        int curr = i;
        bool found = true;

        for (int j = 0; j < T.size(); j++)
        {
            int target = T[j] - 'a';
            int match_pos = nxt[curr][target];

            if (match_pos == S.size())
            {
                found = false; // == ではなく = に修正
                break;
            }

            curr = match_pos + 1;
        }

        int E_L = 0;
        if (found)
        {
            E_L = curr - 1;
        }
        else
        {
            E_L = S.size();
        }

        ans += E_L - i;
    }

    // output
    cout << ans << endl;
    cout << flush;
    return 0;
}