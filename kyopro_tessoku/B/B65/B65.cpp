#include <bits/stdc++.h>
using namespace std;

int N, T;
int A[100009], B[100009];
vector<vector<int>> G(100009, vector<int>());
vector<pair<int, int>> member; // 社長からの距離、番号
queue<int> Q;
vector<bool> check(100009, false);
int kaikyu[100009];

int main() {
    // input
    cin >> N >> T;
    for (int i = 1; i < N; i++)
    {
        cin >> A[i] >> B[i];
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }

    // initialize
    for (int i = 1; i <= N; i++)
    {
        member.push_back(make_pair(-1, i));
    }

    // BFSで社長からの距離を求める
    Q.push(T-1);
    member[T-1].first = 0;
    while (!Q.empty())
    {
        int pos = Q.front() + 1;

        for (int i = 0; i < G[pos].size(); i++)
        {
            if (member[G[pos][i] - 1].first == -1)
            {
                member[G[pos][i] - 1].first = member[pos - 1].first + 1;
                Q.push(G[pos][i] - 1);
            }
        }
        Q.pop();
    }

    // membersをfirstで小さい順にソート
    sort(member.begin(), member.end());

    // memberは階級の高い順に並んでいるので、部下から配る動的計画法
    for (int i = N - 1; i >= 0; i--)
    {
        int my_num = member[i].second;
        check[my_num] = true; // すでに誰かの部下であることが確定した

        for (int j = 0; j < G[my_num].size(); j++)
        {
            if (check[G[my_num][j]] == false)
            {
                kaikyu[G[my_num][j]] = max(kaikyu[G[my_num][j]], kaikyu[my_num] + 1);
            }
        }
    }

    // output
    for (int i = 1; i <= N; i++)
    {
        cout << kaikyu[i] << " ";
    }
    cout << flush;
    return 0;
}