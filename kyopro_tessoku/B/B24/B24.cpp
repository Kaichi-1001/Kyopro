#include <bits/stdc++.h>
using namespace std;

int n, X[500009], Y[500009];
// X[i]: i番目の箱のたての長さ, Y[i]: i番目の箱の横の長さ であり、今回はとりあえず重複がないとする

// 配列Aの部分増加列(LIS)の最大長さを求める関数
int Get_LISvalue(vector<int> A) {
    int LEN = 0;
    int L[A.size()+1];
    for (int i = 0; i <= A.size(); i++) L[i] = 0;

    // 動的計画法
    for (int i = 0; i < A.size(); i++) {
        int pos = lower_bound(L, L + LEN + 1, A[i]) - L;
        
        // Lの更新
        L[pos] = A[i];

        if(pos > LEN) LEN++;
    }
    return LEN;
}

int main() {
    // 入力
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> X[i] >> Y[i];
    }

    // (X[i], Y[i])をペアに持つ配列の作成
    vector<pair<int, int>> tmp;
    for (int i = 1; i <= n; i++) {
        tmp.push_back(make_pair(X[i], -Y[i]));
        //ここで-Y[i]としたのは、あとでX[i]でソートするときに、Xの重複がある場合にYを降順にするため
    }
    // tmpをXでソート
    sort(tmp.begin(), tmp.end());

    // LISを求めたいのはソート後のY
    vector<int> B;
    for (int i = 0; i < tmp.size(); i++) {
        B.push_back(-tmp[i].second);
    }

    // LISの長さを出力
    cout << Get_LISvalue(B) << endl;
    // ソート時にXが重複したときYを降順にしたことで、Xが同じ箱を重ねる心配がなくなる
}