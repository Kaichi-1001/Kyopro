#include <bits/stdc++.h>
using namespace std;

int main() {
    // input
    int Q;
    cin >> Q;
    priority_queue<int, vector<int>, greater<int>> merchandise;

    int q, price;
    for (int i = 0; i < Q; i++) {
        cin >> q;
        switch(q){
            case 1:
                cin >> price;
                merchandise.push(price);
                break;

            case 2:
                cout << merchandise.top() << '\n';
                break;

            case 3:
                merchandise.pop();
                break;
        }
    }

    cout << flush;
    return 0;
}