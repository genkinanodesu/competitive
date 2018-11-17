#include <bits/stdc++.h>
using namespace std;

void otoshidama(int N, int Y){
    for (int i = 0; i < N + 1; i++) {
        for (int j = 0; j < N - i + 1; j++) {
            if (Y == 10000 * i + 5000 * j + 1000 * (N - i - j)){
                cout << i << " " << j << " " << N - i - j << endl;
                return;
            }
        }
    }
    cout << -1 << " " << -1 << " " << -1 << endl;
    return;
}
int main() {
    int N, Y;
    cin >> N >> Y;
    otoshidama(N, Y);
}