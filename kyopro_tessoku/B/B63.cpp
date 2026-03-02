#include <bits/stdc++.h>
using namespace std;

int R, C;
int sy, sx, gy, gx;
vector<vector<char>> c(59, vector<char>(59, '#'));
int dist[2509];
queue<int> Q;

int main() {
    // input
    cin >> R >> C >> sy >> sx >> gy >> gx;
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            cin >> c[i][j];
        }
    }

    // マス目に番号をつけて幅優先探索
    // initialize
    for (int i = 0; i < 2509; i++)
    {
        dist[i] = -1;
    }
    dist[(sy-1) * C + sx] = 0;
    Q.push((sy-1) * C + sx);
    while (!Q.empty())
    {
        int pos = Q.front();

        if (c[pos/C + 1][(pos%C ? pos%C : C) - 1] == '.' && dist[pos - 1] == -1)
        {
            Q.push(pos - 1);
            dist[pos - 1] = dist[pos] + 1;
        }
        if (c[pos/C + 1][(pos%C ? pos%C : C) + 1] == '.' && dist[pos + 1] == -1)
        {
            Q.push(pos + 1);
            dist[pos + 1] = dist[pos] + 1;
        }
        if (c[pos/C][pos%C ? pos%C : C] == '.' && dist[pos - C] == -1)
        {
            Q.push(pos - C);
            dist[pos - C] = dist[pos] + 1;
        }
        if (c[pos/C + 2][pos%C ? pos%C : C] == '.' && dist[pos + C] == -1)
        {
            Q.push(pos + C);
            dist[pos + C] = dist[pos] + 1;
        }

        Q.pop();
    }

    // output
    int goal = (gy - 1) * C + gx;
    cout << dist[goal] << endl;
    return 0;
}