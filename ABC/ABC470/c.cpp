#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // 入出力の高速化（競技プログラミングにおける必須処理）
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    if (!(cin >> N >> Q)) return 0;

    vector<int> A(N + 1, 0);
    vector<int> nonzero;
    // 拡張時の再確保オーバーヘッドを避けるため事前に予約
    nonzero.reserve(N);

    int current_xor = 0;

    for (int i = 1; i <= Q; i++)
    {
        int q;
        cin >> q;
        
        if (q == 1)
        {
            int x;
            cin >> x;
            current_xor ^= A[x];
            A[x]++;
            current_xor ^= A[x];

            // A[x] が 0 から 1 になった瞬間のみ、nonzeroに追加
            if (A[x] == 1)
            {
                nonzero.push_back(x);
            }
        }
        else if (q == 2)
        {
            int k = 0; // 生き残った要素を詰めるためのインデックス
            
            // インデックスアクセスによりイテレータ無効化を回避
            // 走査と同時に有効な要素のみを前方に詰める (In-place 更新)
            for (int j = 0; j < nonzero.size(); ++j)
            {
                int idx = nonzero[j];
                
                current_xor ^= A[idx];
                A[idx]--;
                current_xor ^= A[idx];

                // A[idx] が 1 以上であれば次回の走査対象として残す(新しいリストに更新)
                if (A[idx] > 0)
                {
                    nonzero[k++] = idx;
                }
            }
            // 配列のサイズを実際に生き残った要素数(k)に切り詰める (計算量 O(1))
            nonzero.resize(k);
        }
        
        // endlによるフラッシュを避け、高速な改行を使用する
        cout << current_xor << "\n";
    }

    return 0;
}