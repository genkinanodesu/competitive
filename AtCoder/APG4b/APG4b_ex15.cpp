#include <bits/stdc++.h>
using namespace std;

int sum(vector<int> scores) {
    int s;
    s = 0;
    for (int i = 0; i < scores.size(); i++) {
        s += scores.at(i);
    }
    return s;
}
void output(int sum_a, int sum_b, int sum_c) {
    cout << sum_a * sum_b * sum_c << endl;
    return;
}

vector<int> input(int N) {
    vector<int> vec(N);
    for (int i = 0; i < N; i++) {
        cin >> vec.at(i);
    }
    return vec;
}
int main() {
    int N;
    cin >> N;
    vector<int> A, B, C;
    A = input(N);
    B = input(N);
    C = input(N);
    output(sum(A), sum(B), sum(C));
}
