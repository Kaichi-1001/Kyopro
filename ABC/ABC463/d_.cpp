#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Sheet {
    long long l, r;
};

int N, K;
vector<Sheet> sheets;
vector<long long> r_candidates;

// スコアを X 以下に抑えつつ、重ならないシートを K 個以上選べるか判定
bool check(long long X) {
    // 全ての R_min の候補（各シートの右端）を試す
    for (long long R_min : r_candidates) {
        // 条件を満たすシートを抽出
        vector<Sheet> valid_sheets;
        for (int i = 0; i < N; i++) {
            if (sheets[i].r >= R_min && sheets[i].l <= R_min + X) {
                valid_sheets.push_back(sheets[i]);
            }
        }

        // 区間スケジューリング（右端の昇順でソートして貪欲法）
        sort(valid_sheets.begin(), valid_sheets.end(), [](const Sheet& a, const Sheet& b) {
            return a.r < b.r;
        });

        int count = 0;
        long long current_r = -1; // 直前に選んだシートの右端

        for (const auto& s : valid_sheets) {
            if (s.l >= current_r) {
                count++;
                current_r = s.r;
            }
        }

        // K個以上選べる R_min が1つでもあれば達成可能
        if (count >= K) {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> N >> K)) return 0;

    sheets.resize(N);
    r_candidates.resize(N);
    
    long long max_l = 0;
    long long min_r = 1e18;

    for (int i = 0; i < N; i++) {
        cin >> sheets[i].l >> sheets[i].r;
        r_candidates[i] = sheets[i].r;
        max_l = max(max_l, sheets[i].l);
        min_r = min(min_r, sheets[i].r);
    }

    // R_min の候補の重複を削除
    sort(r_candidates.begin(), r_candidates.end());
    r_candidates.erase(unique(r_candidates.begin(), r_candidates.end()), r_candidates.end());

    // 二分探索の初期範囲を設定
    long long low = 0;
    long long high = max_l - min_r;
    long long ans = -1;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (check(mid)) {
            ans = mid;
            high = mid - 1; // より小さいスコアを目指す
        } else {
            low = mid + 1;  // スコアが小さすぎるので範囲を上げる
        }
    }

    cout << ans << "\n";

    return 0;
}