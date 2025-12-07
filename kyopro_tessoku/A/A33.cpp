#include <bits/stdc++.h>
using namespace std;

long long n, A[100009];

int main() {
    // 入力
    cin >> n;
    for (long long i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    // A_iの排他的論理和（ニム和）を計算する
    long long nim_sum = A[1];
    for (long long i = 2; i <= n; i++) {
        nim_sum ^= A[i];
    }    
    
    // 答えを出力
    if (nim_sum) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }
}