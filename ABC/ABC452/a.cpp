#include <bits/stdc++.h>
using namespace std;

int M, D;

int main() {
    // input
    cin >> M >> D;

    bool gosetu = false;

    if (M == 1 && D == 7) gosetu = true;
    if (M == 3 && D == 3) gosetu = true;
    if (M == 5 && D == 5) gosetu = true;
    if (M == 7 && D == 7) gosetu = true;
    if (M == 9 && D == 9) gosetu = true;
    
    // output
    if (gosetu) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    cout << flush;
    return 0;
}