#include <bits/stdc++.h>
using namespace std;

int n,kakeru=1,sum;

int main() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        kakeru *= -1;
        sum += kakeru * i * i * i;
    }
    cout << sum << endl;
}