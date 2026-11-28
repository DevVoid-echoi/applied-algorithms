#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

long long mem[1000005];

long long topdown_fib(int n){
    if(n<=2) return 1;
    if (mem[n] != -1) return mem[n];
    return mem[n] = (topdown_fib(n-1) + topdown_fib(n-2))%MOD;
}

long long bottomup_fib(int n){
    if (n <= 2) return 1;
    int a = 1, b = 1;
    for (int i=3; i<=n; i++){
        int c = (a+b)%MOD;
        a=b;
        b=c;
    }
    return b;
}

int main(){
    memset(mem, -1, sizeof(mem));
    int n; cin >> n;
    cout << topdown_fib(n) << endl;
    cout << bottomup_fib(n);
}