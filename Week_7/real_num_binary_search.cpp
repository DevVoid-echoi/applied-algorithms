#include <bits/stdc++.h>

using namespace std;

double sqrtroot(int x){
    double lo = 0, hi = x;
    while (hi-lo > 1e-10){
        double mid = (lo+hi)/2;
        if (mid*mid >= x){
            hi = mid;
        }
        else{
            lo = mid;
        }
    }
    return lo;
}

int main(){
    int x; cin >> x;
    printf("%.10f", sqrtroot(x));
}