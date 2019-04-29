#include <bits/stdc++.h>
using namespace std;

double dist_Minkowski(const vector<double> &x, const vector<double> &y, int p){
    if(p == 0){
        double temp = 0.0;
        for(int i = 0; i < (int)x.size(); i++){
            if(abs(x[i] - y[i]) > temp) temp = abs(x[i] - y[i]);
        }
        return temp;
    }
    double temp = 0;
    for(int i = 0; i < (int) x.size(); i++){
        temp += pow(abs(x[i] - y[i]), (double)p);
    }
    return pow(temp, 1 / (double)p);
}
int main(){
    int n; cin >> n;
    vector<double> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    printf("%.10f\n", dist_Minkowski(a, b, 1));
    printf("%.10f\n", dist_Minkowski(a, b, 2));
    printf("%.10f\n", dist_Minkowski(a, b, 3));
    printf("%.10f\n", dist_Minkowski(a, b, 0));
}
