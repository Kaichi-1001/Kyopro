#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<string>> answer;

int main() {
    // 入力
    cin >> N;
    
    // answerの初期化
    answer.resize(N+1);
    for (int i = 1; i <= N; i++){
        answer[i].resize(N+1);
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++) {
            answer[i][j] = ".";
        }
    }

    // 処理
    for (int i = 1; i <= N; i++){
        int j = N + 1 - i;
        if (i <= j) {
            if (i % 2 == 1) {
                for (int k = i; k <= j; k++) {
                    for (int l = i; l <= j; l++)
                    {
                        answer[k][l] = "#";
                    }
                    
                }
            }
            else {
                for (int k = i; k <= j; k++) {
                    for (int l = i; l <= j; l++)
                    {
                        answer[k][l] = ".";
                    }
                    
                }
            }
        }
    }
    
    // answerを出力
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            cout << answer[i][j];
        }
        cout << "\n";
    }
    cout << flush;
    return 0;
}