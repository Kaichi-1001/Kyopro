#include <bits/stdc++.h>
using namespace std;

long long n,q,A[400009],c,l,r,k,sentou=1;
vector<long long> answer;

int main() {
    cin >> n >> q;
    for(int i=1; i<=n; i++) {
        cin >> A[i];
        A[i+n] = A[i];
    }
    for(int i=1; i<=2*n; i++) {
        A[i] += A[i-1];
    }
    while(q) {
        q--;
        cin >> k;
        if(k==1) {
            cin >> c;
            if(sentou + c <= n) sentou += c;
            else sentou = sentou + c - n;
        }
        if(k==2) {
            cin >> l >> r;
            answer.push_back(A[sentou + r - 1] - A[sentou + l - 2]);
        }
    }
    for(long long x : answer) cout << x << "\n";
    cout << flush;
}