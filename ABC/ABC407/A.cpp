#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
    int a, b;
    cin >> a >> b;

    int c = a/b, d = a/b + 1;
    double f = (double)a/b;

    if((f-c)<(d-f)){
        cout << c << "\n";
    } else {
        cout << d << "\n";
    }
    cout << flush;

}