#include <bits/stdc++.h>
using namespace std;

char s1, s2, t1, t2;
int main() {
    // input
    cin >> s1 >> s2 >> t1 >> t2;
    
    // 長さが同じかを判定
    int l1 =  (s1-s2) > 0 ? (s1-s2) : (s2-s1);
    int l2 =  (t1-t2) > 0 ? (t1-t2) : (t2-t1);
    
    // output
    if (l1 == l2 || 5-l1 == l2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}