#include <bits/stdc++.h>
using namespace std;

long long x,y,a,b,c;
string c_str;

int main() {
    cin>>x>>y;
    a=x;
    b=y;
    int q=8;
    while(q){
        q--;
        c=a+b;
        c_str=to_string(c);
        reverse(c_str.begin(),c_str.end());
        c = stoll(c_str);
        a=b;
        b=c;
    }
    cout<<c<<endl;
}