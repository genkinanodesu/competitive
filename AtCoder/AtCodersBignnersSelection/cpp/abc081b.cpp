#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1000000000;

int ord_2(int x) {
    int cnt = 0;
    while (x % 2 == 0) {
        x /= 2;
        cnt++;
    }
    return cnt;
}
int main() {
    int N;
    cin >> N;
    vector<int> vec(N);
    for (int i = 0; i < N; i++) {
        cin >> vec.at(i);
    }
    int ans = MAX_N;
    for (int i = 0; i < N; i++) {
        ans = min(ans, ord_2(vec.at(i)));
    }
    cout << ans << endl;

}
