#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
    int n,k,x;
    cin>>n>>k>>x;
    int m=1;
    for (int i = 0; i < k; i++)
    {
        m*=n;
    }
    
    vector<string> s(n);

    for (int i = 0; i < n; i++)
    {
        cin>>s[i];
    }

    vector<int> c(n);

    for (int i = 0; i < n; i++)
    {
        int count=0;
        for (int j = 0; j < n; j++)
        {
            if(s[i]>s[j])count++;
        }
        c[i]=count;
    }
    
    vector<string> s_chisai(n,"nothing");

    for (int i = 0; i < n; i++)
    {
        if(s_chisai[c[i]]!=s[i])s_chisai[c[i]]=s[i];
    }
    if(n!=1){
        for (int i = 0; i < n-1; i++)
        {
            if(s_chisai[i+1]=="nothing")s_chisai[i+1]=s_chisai[i];
        }
    }
    vector<vector<string>> answer(5);
    for (int i1 = 0; i1 < n; i1++)
    {
        answer[0].push_back(s_chisai[i1]);
        for (int i2 = 0; i2 < n; i2++)
        {
            answer[1].push_back(s_chisai[i1]+s_chisai[i2]);
            for (int i3 = 0; i3 < n; i3++)
            {
                answer[2].push_back(s_chisai[i1]+s_chisai[i2]+s_chisai[i3]);
                for (int i4 = 0; i4 < n; i4++)
                {
                    answer[3].push_back(s_chisai[i1]+s_chisai[i2]+s_chisai[i3]+s_chisai[i4]);
                    for (int i5 = 0; i5 < n; i5++)
                    {
                        answer[4].push_back(s_chisai[i1]+s_chisai[i2]+s_chisai[i3]+s_chisai[i4]+s_chisai[i5]);
                    }
                    
                }
                
            }
            
        }
        
    }
    
    cout<<answer[k-1][x-1]<<endl;
}    