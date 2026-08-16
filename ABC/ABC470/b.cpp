#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> balls(n + 1, 0);
    vector<int> color(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> balls[i];
    }

    for (int i = 1; i <= n; i++)
    {
        color[balls[i]]++;
    }

    int max_color = 0;
    for (int i = 1; i <= n; i++)
    {
        max_color = max(max_color, color[i]);
    }

    cout << n - max_color << endl;
}