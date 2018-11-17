#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> score(N);
    int sum;
    sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> score.at(i);
        sum += score.at(i);
    }
    int average;
    average = sum / N;
    for (int i = 0; i < N; i++) {
        cout << abs(score.at(i) - average) << endl;
    }
}
