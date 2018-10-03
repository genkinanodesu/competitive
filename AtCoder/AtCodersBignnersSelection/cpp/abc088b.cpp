#include <bits/stdc++.h>
using namespace std;


int main() {
    int N;
    cin >> N;
    vector<int> card(N);
    for (int i = 0; i < N; i++){
        cin >> card.at(i);
    }
    sort(card.begin(), card.end(), greater<int>());
    int score_diff = 0;
    for (int i = 0; i < N; i++){
        score_diff += card.at(i) * pow(-1, i);
    }
    cout << score_diff << endl;
}