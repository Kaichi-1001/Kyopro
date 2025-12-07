#include <bits/stdc++.h>
using namespace std;

int n;
double A[59], sum[59];

int main() {
    // 入力
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    // 累積和を求める
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i-1] + A[i];
    }
    
    // 条件を満たすl,rを探す
    int count =0;
    bool yakusu = true;
    for (int l = 1; l <= n; l++) {
        for (int r = l; r <= n; r++) {
            double goukei = sum[r] - sum[l-1];
            for (int i = l; i <= r; i++) {
                if (goukei/A[i] == int(goukei/A[i])) {
                    yakusu = false;
                }
            }
            if (yakusu) {
                count++;
            }
            yakusu = true;
        }
    }
    cout << count << endl;
    return 0;
}