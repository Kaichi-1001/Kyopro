#include <bits/stdc++.h>
using namespace std;

string S;
stack<pair<char, int>> parentheses;
vector<pair<int, int>> answer;

int main()
{
    // input
    cin >> S;

    long long N = S.size();

    for (long long i = 0; i < N; i++)
    {
        if (S[i] == '(')
        {
            parentheses.push(make_pair(S[i], i + 1));
        }
        else if (S[i] == ')')
        {
            answer.push_back(make_pair(parentheses.top().second, i + 1));
            parentheses.pop();
        }
    }

    // output
    for (long long i = 0; i < answer.size(); i++)
    {
        cout << answer[i].first << " " << answer[i].second << "\n";
    }

    cout << flush;
    return 0;
}