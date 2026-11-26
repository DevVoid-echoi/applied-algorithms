#include <bits/stdc++.h>

using namespace std;

long long MOD = 1e9 + 7;
typedef array<array<long long, 2>, 2> Mat ;

Mat mul(const Mat &a, const Mat b){
    Mat c = {{{0, 0}, {0,0}}};
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            for(int k=0; k<2; k++){
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return c;
}

Mat power(Mat a, long long n){
    if (n==0) return {{{1, 0}, {0, 1}}};
    if (n%2!=0) return mul(a, power(a, n-1));
    Mat res = power(a, n/2);
    return mul(res, res);
}

int main(){
    int n; cin >> n;
    Mat m = {{{1, 1}, {1, 0}}};
    Mat r = power(m, n);
    cout << r[0][1];
}