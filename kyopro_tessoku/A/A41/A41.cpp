#include <bits/stdc++.h>
using namespace std;

int N;
string S;

int main() {
    // input
    cin >> N >> S;

    // Sのようにタイルを塗り替えられるか判定
    bool ans = false;

    for (int i = 0; i < N - 2; i++) {
        if (S[i] == S[i+1] && S[i+1] == S[i+2]) {
            ans = true;
            break;
        }
    }
    
    // output
    if (ans) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}