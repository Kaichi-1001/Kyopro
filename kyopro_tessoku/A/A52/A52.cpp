#include <bits/stdc++.h>
using namespace std;

int main()
{
    int Q;
    cin >> Q;

    queue<string> line;
    int q;
    string name;
    for (int i = 0; i < Q; i++)
    {
        cin >> q;
        switch (q)
        {
        case 1:
            cin >> name;
            line.push(name);
            break;

        case 2:
            if (!line.empty())
            {
                cout << line.front() << '\n';
            }
            break;

        case 3:
            if (!line.empty())
            {
                line.pop();
            }
            break;
        }
    }

    cout << flush;
    return 0;
}