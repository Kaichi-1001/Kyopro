#include <bits/stdc++.h>
using namespace std;

int n, A;
char s;
vector<int> L, R;
int main()
{
    // input
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> A >> s;
        if (s == 'L')
        {
            L.push_back(A);
        }
        else
        {
            R.push_back(A);
        }
    }

    // 最小値を計算
    int answer = 0;
    if (L.size() > 1) {
        for (int i = 1; i <= L.size()-1; i++)
        {
            int L_plass = (L[i] - L[i - 1]) > 0 ? L[i] - L[i - 1] : L[i - 1] - L[i];
            answer += L_plass; 
        }
    }   
    if (R.size() > 1) {
        for (int i = 1; i <= R.size()-1; i++)
        {
            int R_plass = (R[i] - R[i - 1]) > 0 ? R[i] - R[i - 1] : R[i - 1] - R[i];
            answer += R_plass;
        }
    }

    // output
    cout << answer << endl;
}