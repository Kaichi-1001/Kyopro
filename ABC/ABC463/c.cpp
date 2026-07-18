#include <bits/stdc++.h>
using namespace std;

long long N, Q;
vector<pair<long long, long long>> takahashi;
vector<long long> change_time;
vector<long long> max_tall;

int main()
{
    // input
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        static long long h, l;
        cin >> h >> l;
        takahashi.push_back({h, l});
    }

    // takahashiをhの大きい順に並べ替える
    sort(takahashi.begin(), takahashi.end(), greater<pair<long long, long long>>());

    // change_time, max_tallをつくる
    long long current_time = 0;
    for (int i = 0; i < N; i++)
    {
        if (takahashi[i].second > current_time)
        {
            change_time.push_back(takahashi[i].second);
            max_tall.push_back(takahashi[i].first);
            current_time = takahashi[i].second;
        }
    }

    // Q個のクエリに回答
    cin >> Q;
    vector<long long> ans = {};
    long long T[Q] = {};
    for (int i = 0; i < Q; i++)
    {
        cin >> T[i];
    }

    for (int i = 0; i < Q; i++)
    {
        int pos = upper_bound(change_time.begin(), change_time.end(), T[i]) - change_time.begin();
        ans.push_back(max_tall[pos]);
    }

    // output
    for (int i = 0; i < Q; i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}