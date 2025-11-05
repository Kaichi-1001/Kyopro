#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
    // 入力
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        if (i <= m) {
            cout << "OK" << "\n";
        }
        else {
            cout << "Too Many Requests" << "\n";
        }
    }
    cout << flush;
    return 0;
}