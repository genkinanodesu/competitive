#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    while (S.size() > 0){
        if (S.substr(max(0, S.size() - 5), 5) == "dream") {
            S.erase(S.size() - 5, 5);
        }
        else if (S.substr(max(0, S.size() - 7), 7) == "dreamer") {
            S.erase(S.size() - 7, 7);
        }
        else if (S.substr(max(0, S.size() - 5), 5) == "erase") {
            S.erase(S.size() - 5, 5);
        }
        else if (S.substr(max(0, S.size() - 6), 6) == "eraser") {
            S.erase(S.size() - 6, 6);
        }
        else {
            cout << "NO" << endl;
        }
    }
    cout << "YES" << endl;
}