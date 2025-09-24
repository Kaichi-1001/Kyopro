#include <bits/stdc++.h>
using namespace std;

int n;
long long count_1,count_2;
vector<int> b={0};
string s;

int main() {
    cin>>n>>s;
    for (int i = 0; i < 2*n; i++)
    {
        if(s[i]=='B') b.push_back(i+1); 
    }
    for (int i = 1; i <= n; i++)
    {
        count_1+=abs(b[i]-2*i);
        count_2+=abs(b[i]-(2*i-1));
    }
    cout<<min(count_1,count_2)<<endl;
}