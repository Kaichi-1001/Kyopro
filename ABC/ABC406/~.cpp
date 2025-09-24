#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    vector<int> b={};
    for(int i=0;i<n;i++){
            if((v[i-1]<v[i])&&(v[i]>v[i+1])){
                b.push_back(i);
            } else if((v[i-1]>v[i])&&(v[i]<v[i+1])){
                b.push_back(-i);
            } else continue;
    }
    int x=0;
    int s=b.size();
    if((s<2)||((s==2)&&(b[0]<0))){
        x=0;
    } else if((b[0]>0)&&(b[s-1]>0)){
        x+=b[0]*(b[2]+b[1]);
        for(int i=2;i<s/2;i++){
            x+=(b[2*i]+b[2*i-1])*(b[2*(i-1)]+b[2*(i-1)-1]);
        }
    } else if((b[0]>0)&&(b[s-1]<0)){
        x+=b[0]*(b[2]+b[1]);
        for(int i=2;i<s/2;i++){
            x+=(b[2*i]+b[2*i-1])*(b[2*(i-1)]+b[2*(i-1)-1]);
        }
        x+=(n+b[s-1])*(b[s-2]+b[s-3]);
    } else if((b[0]<0)&&(b[s-1]<0)){
        for(int i=1;i<s/2-1;i++){
            x+=(b[2*i+1]+b[2*i])*(b[2*i-1]+b[2*i-2]);
        }
        x+=(n+b[s-1])*(b[s-2]+b[s-3]);
    } else if((b[0]<0)&&(b[s-1]>0)){
        for(int i=1;i<s/2+1;i++){
            x+=(b[2*i]+b[2*i-1])*(b[2*i-2]+b[2*i-3]);
        }
    }
    cout << x << endl;
}