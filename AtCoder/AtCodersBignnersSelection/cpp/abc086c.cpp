#include <bits/stdc++.h>
using namespace std;

bool plan(int t, int x, int y) {
    t = abs(t);
    x = abs(x);
    y = abs(y);
    if ((x + y <= t) && ((x + y - t) % 2 == 0)) {
        return true;
    }
    else {
        return false;
    }
}


int main() {
    int N;
    cin >> N;
    vector<int> t(N + 1);
    vector<int> x(N + 1);
    vector<int> y(N + 1);
    for (int i = 0; i < N; i++){
        int ti, xi, yi;
        cin >> ti >> xi >> yi;
        t.at(i + 1) = ti - t.at(i);
        x.at(i + 1) = xi - x.at(i);
        y.at(i + 1) = yi - y.at(i);
    }
    bool flag = true;
    for (int i = 0; i < N; i++){
        if (not plan(t.at(i + 1), x.at(i + 1), y.at(i + 1))){
            flag = false;
            cout << "No" << endl;
            break;
        }
    }
    if (flag) {
        cout << "Yes" << endl;
    }
}
