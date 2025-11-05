#include <bits/stdc++.h>
using namespace std;

int n, m, A[10009]; 

int main() {
    // 入力
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    // Aの合計をsumに入れる
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += A[i];
    }
    
    // 要素を一つとって合計がmになるか判定
    bool answer = false;
    for (int i = 1; i <= n; i++) {
        if (sum - A[i] == m) {
            answer = true;
        }
    }
    if (answer) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    cout << flush;
    return 0;
}