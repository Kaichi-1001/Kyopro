#include <bits/stdc++.h>
using namespace std;

// 任意の選び方において、表、裏それぞれの総和は正か負にしかならないことを利用し、4通りの全探索
long long N, A[100009], B[100009];

int main() {
    // input
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i] >> B[i];
    }
    
    // 4通りの全探索
    long long ans = 0;

    // 表、裏の総和がどちらも正で最大を目指す
    for (int i = 1; i <= N; i++)
    {
        if (A[i] + B[i] > 0)
        {
            ans += A[i] + B[i];
        }
    }
    long long ans_1 = ans;
    ans = 0;
    
    // 表が正、裏が負
    for(int i = 1; i <= N; i++)
    {
        if (A[i] - B[i] > 0)
        {
            ans += A[i] - B[i];
        }
    }
    long long ans_2 = ans;
    ans = 0;

    // 表が負、裏が正
    for (int i = 1; i <= N; i++)
    {
        if (A[i] - B[i] < 0)
        {
            ans += B[i] - A[i];
        }
    }
    long long ans_3 = ans;
    ans = 0;

    // 表も裏も負
    for (int i = 1; i <= N; i++)
    {
        if (A[i] + B[i] < 0)
        {
            ans += 0 - (A[i] + B[i]);
        }
    }
    long long ans_4 = ans;
    
    // 最大値を出力
    ans = max(ans_1, max(ans_2, max(ans_3, ans_4)));

    // output
    cout << ans << endl;
    return 0;
}