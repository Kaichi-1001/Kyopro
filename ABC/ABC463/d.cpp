#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<pair<long long, char>> sheets;
vector<pair<long long, int>> Left;
vector<pair<long long, int>> Right;

int main()
{
    // input
    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        long long l, r;
        cin >> l >> r;
        Left.push_back(make_pair(l, i + 1));
        Right.push_back(make_pair(r, i + 1));
    }

    // sort
    vector<pair<long long, int>> L_sort = Left;
    sort(L_sort.begin(), L_sort.end());

    vector<pair<long long, int>> R_sort = Right;
    sort(R_sort.begin(), R_sort.end());

    // sheetsを作成
    int l_pos = 0, r_pos = 0;
    for (int i = 0; i < 2 * N; i++)
    {
        if (l_pos == N)
        {
            sheets.push_back(make_pair(R_sort[r_pos].second, 'R'));
            r_pos++;
        } else if (r_pos == N) {
            sheets.push_back(make_pair(L_sort[l_pos].second, 'L'));
            l_pos++;
        } else if (L_sort[l_pos].first < R_sort[r_pos].first)
        {
            sheets.push_back(make_pair(L_sort[l_pos].second, 'L'));
            l_pos++;
        }
        else
        {
            sheets.push_back(make_pair(R_sort[r_pos].second, 'R'));
            r_pos++;
        }
    }

    // シートの重なりを検証
    bool kasanari[N + 1];
    for (int i = 0; i < N; i++)
    {
        kasanari[i] = false;
    }

    int current_sheet_number = 0;
    for (int i = 0; i < 2 * N; i++)
    {
        if (current_sheet_number > 0)
        {
            if (sheets[i].first == current_sheet_number && sheets[i].second == 'R')
            {
                current_sheet_number = 0;
            }
            else if (sheets[i].second == 'L')
            {
                current_sheet_number = sheets[i].first;
                kasanari[sheets[i].first] = true;
                kasanari[current_sheet_number] = true;
            }
            else if (sheets[i].second == 'R')
            {
                kasanari[sheets[i].first] = true;
                kasanari[current_sheet_number] = true;
            }
        }
        else
        {
            if (sheets[i].second == 'L')
            {
                current_sheet_number = sheets[i].first;
            }
        }
    }

    // 重なっていない数をカウント
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        if (kasanari[i] == false)
        {
            cnt++;
        }
    }

    if (cnt >= K)
    {
        long long r_min = 0, l_max = 0;
        for (int i = 0; i < N; i++)
        {
            if (kasanari[R_sort[i].second] == false)
            {
                r_min = Right[R_sort[i].second - 1].first;
                break;
            }
        }
        for (int i = N - 1; i >= 0; i--)
        {
            if (kasanari[L_sort[i].second] == false)
            {
                l_max = Left[L_sort[i].second - 1].first;
                break;
            }
        }
        cout << l_max - r_min << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}