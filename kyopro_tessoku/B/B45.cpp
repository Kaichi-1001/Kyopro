// 3つのうち2つを選んで、片方に+1,もう片方に-1するとき、総和は変変化しないこと利用
#include <bits/stdc++.h>
using namespace std;

long long a, b, c;
int main(){
    // input
    cin >> a >> b >> c;

    // 判定して出力
    if (a + b + c == 0)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}