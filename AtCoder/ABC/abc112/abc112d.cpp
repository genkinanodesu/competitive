#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> d_list(0);
    for (int i = 1; i * i <= m; i++){
        if (m % i == 0){
            d_list.push_back(i);
            if (i * i < m) {
                d_list.push_back(m / i);
            }
        }
    }
    sort(d_list.begin(), d_list.end());
    int d_max = m / n;
    int index = (upper_bound(d_list.begin(), d_list.end(), d_max) - d_list.begin() - 1);
    cout << d_list[index] << endl; 
}