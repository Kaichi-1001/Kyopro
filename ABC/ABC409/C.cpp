#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
    int n,l,count=0;
    cin >> n >> l;
    int d[n];
    d[0]=0;
    for (int i = 1; i < n; i++)
    {
        cin >> d[i];
    }
    if(l%3==0){
       vector<int> e(n,0);
       for (int i = 0; i < n; i++)
       {
          for (int j = 0; j <= i; j++)
          {
            e[i]+=d[j];
          }
          e[i]=e[i]%l;
       }
       for (int i = 0; i < n; i++)
       {
          int r=0,L=0;
          for (int j = 0; j < n; j++)
          {
              if(e[i]<l/3){
                  if((e[j]>=l/3)&&(e[j]<2*l/3)&&(e[j]-e[i]==l/3)) r+=1;
                  if((e[j]>=2*l/3)&&(e[j]<l)&&(l-e[j]+e[i]==l/3)) L+=1;
                }
            
          }
          count+=r*L;
        }
        cout<<count<<endl;
    }
    else cout<<0<<endl;
    
}