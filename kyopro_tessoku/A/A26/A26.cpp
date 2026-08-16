#include <bits/stdc++.h>
using namespace std;

int Q, X[10009];

// 素数判定関数
bool isPrime(int p)
{
    // 調べるのはpの平方根まででok←背理法で証明可能
    auto p_sqrt = sqrt(p);
    for (int i = 2; i <= p_sqrt; i++)
    {
        if (p % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    // 入力
    cin >> Q;
    for (int i = 1; i <= Q; i++)
    {
        cin >> X[i];
    }

    // クエリに回答
    for (int i = 1; i <= Q; i++)
    {
        if (isPrime(X[i]))
        {
            cout << "Yes" << "\n";
        }
        else
        {
            cout << "No" << "\n";
        }
    }
    cout << flush;
    return 0;
}