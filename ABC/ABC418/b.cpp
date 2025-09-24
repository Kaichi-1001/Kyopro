#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin>>s;
    int n=s.size();
    if((n==1)||(n==2))cout<<0<<endl;
    double jutenritu=0,count=0;
    if(n>=3){
        for (int i = 0; i < n-2; i++)
        {
            if(s[i]=='t'){
                for (int j = i+2; j < n; j++)
                {
                    if(s[j]=='t'){
                        for (int k = i; k <= j; k++)
                        {
                            if(s[k]=='t') count++;
                        }
                        double next=(count-2)/(j-i-1);
                        if(next>=jutenritu) jutenritu=next;
                        count=0;
                    }
                }
                
            }
        }
        cout<<fixed<<setprecision(10)<<jutenritu<<endl;
    }
    
}
// 精度の制限があるときはdouble型でfixed<<setprecision(桁数)とすればうまく出力される