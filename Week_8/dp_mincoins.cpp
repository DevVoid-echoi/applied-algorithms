#include <bits/stdc++.h>

using namespace std;

long long INF = 1e9;
long long Coin[20], mem[20][100005];

long long minCoins(int i, int x){
    if (x==0) return 0;
    if (x<0 || i==0) return INF;
    if (mem[i][x] != -1) return mem[i][x];

    long long res = INF;
    res = min(res, 1 + minCoins(i,x-Coin[i]));
    res = min(res, minCoins(i-1, x));

    return mem[i][x] = res;
}

void trace(int i, int x){
    if(x<=0 || i==0) return;
    if (x >= Coin[i] && minCoins(i, x) == 1 + minCoins(i, x-Coin[i])){
        cout << Coin[i] << " ";
        trace(i, x-Coin[i]);
    }
    else trace(i-1, x);
}

int main(){
    memset(mem, -1, sizeof(mem));
    int n, x;
    cin >> n >> x;
    for (int i=1; i<=n; i++){
        cin >> Coin[i];
    }

    long long a = minCoins(n, x);
    if (a==INF){
        cout << -1;
        return 0;
    }
    else {
        cout << a << endl;
        trace(n, x);
    }
}