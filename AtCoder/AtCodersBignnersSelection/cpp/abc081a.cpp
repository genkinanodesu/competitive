#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int sum;
    sum = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s.at(i) == '1') {
            sum += 1;
        }
    }
    cout << sum << endl;
}
