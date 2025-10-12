#include <bits/stdc++.h>
using namespace std;

int n;
long long A[109];

int main() {
    cin >> n;
    A[0] = 1;
    for (int i = 1; i <= 100; i++)
    {
        long long sum = 0;
        for (int j = 0; j <= i-1; j++)
        {
            string s = to_string(A[j]);
            for (char x: s)
            {
                sum += x - '0';
            }
        }
        A[i] = sum;
    }
    
    cout << A[n] << endl;
}