#include <bits/stdc++.h>
using namespace std;


int main() {
    int N;
    cin >> N;
    set<int> mochi;
    for (int i = 0; i < N; i++){
        int di;
        cin >> di;
        mochi.insert(di);
    }
    cout << mochi.size() << endl;

}