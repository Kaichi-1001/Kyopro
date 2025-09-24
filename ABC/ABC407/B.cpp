#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
    int x,y,a[6] = {1,2,3,4,5,6},b[6] = {1,2,3,4,5,6};
    cin >> x >> y;

    int count = 0;

    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            if(((a[i]+b[j])>=x)||((a[i]-b[j])>=y)||((a[i]-b[j])<=-y)){
                count+=1;
            }
        }
    }
    cout << fixed << setprecision(12); //小数点以下１２桁まで表示（（）内の数字は可変）
    cout << (double)count/36 << endl;
}