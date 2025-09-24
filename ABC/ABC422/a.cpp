#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
    cin>>s;

    int a = s[0] - '0';
    int b = s[2] - '0';

    if(b<8){
        cout<<a<<'-'<<b+1<<endl;
    }
    else if(b==8){
        if(a<8) cout<<a+1<<'-'<<1<<endl;
    }
}