#include <bits/stdc++.h>
using namespace std;
// 毎回逆順にすると時間がかかるから、今逆順かどうかをboolで判定し、インデックスで工夫
int N, Q;

int main() {
    // input
    cin >> N >> Q;

    // initialize array
    vector<long long> A(N, 0);
    for (int i = 0; i < N; i++)
    {
        A[i] = i + 1;
    }
    // 逆順かを参照
    bool rev = false;

    // for answer
    vector<int> answer = {};

    // Q個のクエリに回答
    while(Q)
    {
        Q--;

        // input
        int q, x, y;
        cin >> q;
        switch (q)
        {
        case 1:
            cin >> x >> y;
            if (rev)
            {
                x = N + 1 - x;
            }

            A[x - 1] = y;
            break;
        
        case 2:
            if (rev)
            {
                rev = false;
            }
            else
            {
                rev = true;
            }
            break;
        
        case 3:
            cin >> x;
            if (rev)
            {
                x = N + 1 - x;
            }
            answer.push_back(A[x-1]);
            break;
        }
    }

    // output
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << endl;
    }
    return 0;
}