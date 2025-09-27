#include <bits/stdc++.h>
using namespace std;

int n, A[19], P[19],count_A[19];
bool answer = true;

int main() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> A[i];
        if(A[i]!=-1) count_A[A[i]]++;
    }
    for(int i=1; i<=10; i++) {
        if(count_A[i]>1) answer = false;
    }
    if(answer==false) {
        cout<<"No"<<endl;
    }
    else {
        cout<<"Yes"<<endl;
            for(int i=1; i<=n; i++){
                if(A[i]!=-1) P[i] = A[i];
                if(A[i]==-1) {
                    for(int j=1; j<=10; j++) {
                        if(count_A[j]==0) {
                            P[i] = j;
                            count_A[j]++;
                            break;
                        }
                    }       
                }
            }
            for(int i=1; i<=n; i++) {
                cout<<P[i]<<" ";
            }
        }
}