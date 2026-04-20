#include <bits/stdc++.h>
using namespace std;

int Q;
stack<string> books;
vector<string> answer;

int main() {
    // input
    cin >> Q;

    int query = 0;
    string book;

    for (int i = 1; i <= Q; i++)
    {
        cin >> query;
        switch (query)
        {
            case 1:
                cin >> book;
                books.push(book);
                break;
            
            case 2:
                answer.push_back(books.top());
                break;
            
            case 3:
                books.pop();
                break;
            
            default:
                break;
        }
    }

    // output
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << "\n";
    }

    cout << flush;
    return 0;
}