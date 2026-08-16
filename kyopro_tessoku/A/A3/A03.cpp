#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, r[109], b[109];
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> r[i];
    }
    for(int i=0;i<n;i++){
        cin >> b[i];
    }
    bool answer=false;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(r[i]+b[j]==k){
                answer=true;
            }
        }
    }
    if(answer==true){
        cout << "Yes" << "\n";
    } else{
        cout << "No" << "\n";
    }
    cout << flush;
}