#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n,k;
    cin >>n>>k;
    int answer = 0;
    
    if(3*n<k)cout<<0<<endl;
    else{
    
        int minr = min(n,k-2);
        for (int r = 1; r <= minr; r++)
        {
            if(k-r>n*2)answer+=0;
            else{
                int minb = min(n,k-r-1);
                for (int b = 1; b <= minb; b++)
                {
                    if(k-r-b>n)answer+=0;
                    else answer+=1;
                }
                
            }
        }
    cout<<answer<<endl;
    }
}