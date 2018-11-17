#include <bits/stdc++.h>
using namespace std;

vector<string> d{"dream", "dreamer", "erase", "eraser"};
vector<int> e{5, 7, 5, 6};

bool daydream(string s){
    int n = s.size();

    for (int i = 0; i < 4; i++){
        if (s == d.at(i)) {
            return true;
        }
        else if (n >= e.at(i)){
            if (s.substr(n - e.at(i), e.at(i)) == d.at(i)) {
                s.resize(n - e.at(i));
                return daydream(s);
            }
        }
    }
    return false;
}

int main() {
    string S;
    cin >> S;
    if (daydream(S)) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}
