#include <bits/stdc++.h>
using namespace std;

int N, K;
string S;

int main()
{
    // input
    cin >> N >> K>> S;

    // 豆電球をK個転倒させられるかを判定
    int count = 0;
    for (char c : S)
    {
        if (c == '1')
            count++;
    }

    unsigned int defference = (K - count) ? K - count : count - K;

    if (defference % 2 == 0)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}