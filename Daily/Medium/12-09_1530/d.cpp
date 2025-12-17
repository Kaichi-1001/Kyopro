#include <bits/stdc++.h>
using namespace std;

int N, P, a[100009];

int main() {
    // 入力
    cin >> N >> P;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    
    // 不可の人数を数える
    int count = 0;
    for (int i = 1; i <= N; i++) {
        if (a[i] < P) {
            count++;
        }
    }
    
    // 不可の人数を出力
    cout << count << endl;
    return 0;
}