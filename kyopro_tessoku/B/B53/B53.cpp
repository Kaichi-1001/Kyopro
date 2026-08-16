#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, D;
    priority_queue<int> salary;

    cin >> N >> D;
    vector<vector<int>> jobs(D + 1);

    int x, y;
    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;
        jobs[x].push_back(y);
    }

    long long total_income = 0;
    for (int current_day = 1; current_day <= D; current_day++)
    {
        if (jobs[current_day].size() > 0)
        {
            for (int z : jobs[current_day])
            {
                salary.push(z);
            }
        }
        if (!salary.empty())
        {
            total_income += salary.top();
            salary.pop();
        }
    }

    cout << total_income << endl;
    return 0;
}