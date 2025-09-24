#include "bits/stdc++.h"
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if(a<c){
        cout << "No" << "\n";
    } else if(a>c){
        cout << "Yes" << "\n";
     } else if(a==c){
        if(b<d){
            cout << "No" << "\n";
        } else {
            cout << "Yes" << "\n";
        }
     }
     cout << flush;
}
