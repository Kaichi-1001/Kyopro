#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    double a,b;
    cin >> a >> b;
    bool answer=false;

    for(int i=0;i<=b-a;i++){
        double ai = a+i;
        double x = 100/ai;
        if(x == (int)x){
            answer = true;
        }
    }
    if(answer==true){
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
    cout << flush;

}