#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> answer(10);
    int quotient = n;
    for (int i = 0; i < 10; i++)
    {
        answer[9-i]=quotient%2;
        quotient = quotient/2;
    }
    for (int i = 0; i < 10; i++)
    {
        cout << answer[i];
    }
}