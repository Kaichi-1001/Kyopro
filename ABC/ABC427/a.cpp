#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int l = s.size();
    s.erase((l+1)/2-1, 1);

    cout << s << endl;
}