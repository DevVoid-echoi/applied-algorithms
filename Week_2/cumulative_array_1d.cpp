#include <bits/stdc++.h>

using namespace std;

int main(){
    int a[101];
    for (int i=1; i<=100; i++){
        a[i] = i;
    }

    long long sum[101];
    sum[0] = 0;
    for (int i=1; i<=100; i++){
        sum[i] = sum[i-1] + a[i];
    }

    int i, j;
    cin >> i >> j;
    cout << sum[j] - sum[i-1];
}