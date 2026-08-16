#include <bits/stdc++.h>
using namespace std;

vector<pair<long long, long long>> luxury;
long long N, K, M;

int main()
{
    // input
    cin >> N >> K >> M;
    long long C, V;
    for (int i = 0; i < N; i++)
    {
        cin >> C >> V;
        luxury.push_back(make_pair(C, V));
    }

    // luxury sort by value
    sort(luxury.begin(), luxury.end(), [](const pair<long long, long long> &a, const pair<long long, long long> &b)
         { return a.second > b.second; });

    // solve
    long long ans = 0, cnt = 0;
    stack<pair<long long, long long>> duplicate;
    bool color[200009];
    for (int i = 0; i < 200009; i++)
    {
        color[i] = false;
    }
    for (int i = 0; i < K; i++)
    {
        if (color[luxury[i].first])
        {
            duplicate.push(luxury[i]);
            ans += luxury[i].second;
        }
        else
        {
            color[luxury[i].first] = true;
            cnt++;
            ans += luxury[i].second;
        }
    }
    if (cnt < M)
    {
        int i = K;
        do
        {
            if (color[luxury[i].first])
            {
                i++;
            }
            else
            {
                color[luxury[i].first] = true;
                ans -= duplicate.top().second;
                duplicate.pop();
                ans += luxury[i].second;
                cnt++;
                i++;
            }
        } while (cnt < M);
    }

    // output
    cout << ans << endl;
    return 0;
}