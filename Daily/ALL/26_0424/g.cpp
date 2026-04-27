#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

// グローバル変数のサイズは余裕を持つ
const int MAX = 300009;
vector<int> G[MAX];
bool black[MAX];

void fast_dfs(int start) {
    stack<int> st;
    st.push(start);
    // black[start] = true; // 呼び出し側で済ませる
    
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        for (int v : G[u]) {
            if (!black[v]) {
                black[v] = true;
                st.push(v);
            }
        }
    }
}

int main() {
    // 高速入出力
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N >> M)) return 0;

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        G[y].push_back(x); // 逆向き
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int a, b;
        cin >> a >> b;
        if (a == 1) {
            if (!black[b]) {
                black[b] = true;
                fast_dfs(b);
            }
        } else {
            cout << (black[b] ? "Yes\n" : "No\n");
        }
    }

    return 0;
}