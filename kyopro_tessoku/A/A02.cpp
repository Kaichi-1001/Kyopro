#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,x;
    cin >> n >> x;
    string answer;

    for(int i=0;i<n;i++){
        int ai;
        cin >> ai;
        if(ai==x){
            answer="Yes";
            break;
        } else {
            answer="No";
        }
    }
    cout << answer << endl;
}