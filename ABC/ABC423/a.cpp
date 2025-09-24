#include <bits/stdc++.h>
using namespace std;

long long x,c;

int main() {
    cin>>x>>c;
    long long goukei = 0,answer = 0;

    while(goukei<=x){
        if(goukei+1000+c<=x){
            goukei+=1000+c;
            answer+=1000;
        }
        else break;
    }
    
    cout<<answer<<endl;
}