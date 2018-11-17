#include <bits/stdc++.h>
using namespace std;

int digit_sum(int x) {
    if (0 <= x && x < 10) {
        return x;
    }
    else {
        return (x % 10) + digit_sum(x / 10);
    }
}

int main() {
    int N, A, B;
    cin >> N >> A >> B;
    int sum = 0;
    for (int i = 1; i < N + 1; i++) {
        if (A <= digit_sum(i) && digit_sum(i) <= B) {
            sum += i;
        }
    }
    cout << sum << endl;
}