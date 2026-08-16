#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string n;
    cin >> n;
    int s=n.size();
    int answer=0;
    for (int i = 0; i < s; i++)
    {
        answer+=(n[s-1-i]-'0')*(1<<i);
    }
    cout << answer << endl;
}