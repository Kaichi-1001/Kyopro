#include <bits/stdc++.h>
using namespace std;

int T;
int answer[100009];
long long t[100009], l[100009], u[100009];
int main()
{
    // 入力
    cin >> T;

    for (int j = 1; j <= T; j++)
    {
        long long N, H;
        cin >> N >> H;
        for (int i = 1; i <= N; i++)
        {
            cin >> t[i] >> l[i] >> u[i];
        }
        t[0] = 0;
        l[0] = H;
        u[0] = H;

        for (int i = 1; i <= N; i++)
        {
            long long high = u[i-1] + t[i] - t[i-1];
            long long low = l[i-1] - t[i] + t[i-1];
            
            if(high < l[i] || low > u[i]) {
                answer[j] = 1;
            }
            if(high >= l[i] && high <= u[i]){
                u[i] = high;
            }
            if(low >= l[i] && low <= u[i]){
                l[i] = low;
            }
        }
    }

    // 出力
    for (int i = 1; i <= T; i++)
    {
        if (answer[i] == 0)
        {
            cout << "Yes" << "\n";
        }
        if (answer[i] == 1)
        {
            cout << "No" << "\n";
        }
    }
    cout << flush;
}