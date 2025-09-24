#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
    int n, l;
    cin >> n >> l;
    vector<int> d(n,0);
    for (int i = 1; i < n; i++) {
        cin >> d[i];
    }

    if (l % 3 == 0) {
        vector<int> e(n, 0);
        int acc = 0;
        for (int i = 0; i < n; i++) {
         acc += d[i];
         e[i] = acc % l;
        }

        int l3 = l / 3;
        vector<int> cnt0(l3, 0), cnt1(l3, 0), cnt2(l3, 0);

        for (int x : e) {
            if (x < l3)
                cnt0[x]++;
            else if (x < 2 * l3)
                cnt1[x - l3]++;
            else
                cnt2[x - 2 * l3]++;
        }

        long long count = 0;
        for (int x = 0; x < l3; x++) {
            count += 1LL * cnt0[x] * cnt1[x] * cnt2[x];
        }

        cout << count << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}