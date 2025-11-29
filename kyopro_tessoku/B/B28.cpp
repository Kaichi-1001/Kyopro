#include <bits/stdc++.h>
using namespace std;

int N, fibonatti[10000009];

int main() {
    cin >> N;
    fibonatti[0] = 0;
    fibonatti[1] = 1;
    for (int i = 2; i <= N; i++) {
        fibonatti[i] = (fibonatti[i - 1] + fibonatti[i - 2]) % 1000000007LL;
    }
    cout << fibonatti[N] << endl;
    return 0;
}