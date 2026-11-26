#include <bits/stdc++.h>

using namespace std;

long long len_[100];

char charAt(long long n, long long i){
    if(n==1) return 'A';
    if(n==2) return 'B';
    if (i <= len_[n-2]) return charAt(n-2, i);
    return charAt(n-1, i-len_[n-2]);
}

int main(){
    len_[1] = 1; len_[2] = 1;
    for (int k=3; k<100; k++){
        len_[k] = len_[k-1] + len_[k-2];
    }
    int n, i; cin >> n >> i;
    cout << charAt(n, i);
}