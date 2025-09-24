#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

string s;
vector<int> nimotu={};
int main() {
    cin >> s;
    int size = s.size();

    for (int i = 0; i < size; i++)
    {
        if (s[i]=='#')
        {
            nimotu.push_back(i+1);
        }
    }
    
    int ns = nimotu.size()/2;

    for (int i = 0; i < ns; i++)
    {
        cout << nimotu[2*i] << ',' << nimotu[2*i+1] << "\n";
    }
    cout << flush;
}