#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long> a={0,0},b={0,0,0},answer;

int main() {
    cin>>n;
    answer.resize(n+1);
    for (int i = 2; i <= n; i++)
    {
        int A;
        cin>>A;
        a.push_back(A);
    }
    for (int i = 3; i <= n; i++)
    {
        int B;
        cin>>B;
        b.push_back(B);
    }
    answer[2]=a[2];
    if(n>2){
        long long tonari;
        long long tobasi;
        for (int i = 3; i <= n; i++)
        {
            tonari=answer[i-1]+a[i];
            tobasi=answer[i-2]+b[i];
            answer[i]=min(tonari,tobasi);
        }
    }
    cout<<answer[n]<<endl;
}