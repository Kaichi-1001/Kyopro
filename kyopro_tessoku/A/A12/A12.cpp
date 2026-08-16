#include <iostream>
using namespace std;

long long n, k;
long long a[100009];

bool check(long long x){
    long long sum=0;
    for (long long i = 1; i <= n; i++)
    {
        sum += x/a[i];
    }
    if(sum>=k) return true;
    return false;
}

int main() {
    cin>>n>>k;
    for (long long i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    long long l=1,r=1'000'000'000; //答えは10^9を超えないという制約からrを設定
    while(l<r){
        long long mid=(l+r)/2;
        bool ans=check(mid);
        if(ans==false) l=mid+1;
        if(ans==true) r=mid;
    }

    cout<<r<<endl;
    
} 