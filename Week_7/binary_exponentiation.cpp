#include <bits/stdc++.h>

using namespace std;

long long power(int x, int n){
    if (n==0) return 1;
    if (n%2!=0){
        return x * power(x, n-1);
    }
    long long res = power(x, n/2);
    return res * res;
}

int main(){
    int x, n;
    cin >> x >> n;
    if (n<0){
        if (x==0) cout << "Undefined";
        else{
            double res = 1.0 / power(x, fabs(n));
            cout << res;
        }
    }
    else{
        long long res = power(x, n);
        cout << res;
    }
}