#include <bits/stdc++.h>

using namespace std;

int M[1000][1000];
int a[1000];

int better(int x, int y){
    return (a[x] <= a[y]) ? x: y;
}

void preprocessing(int n){
    for (int j=0; j<n; j++){
        M[0][j] = j;
    }

    for (int i=1; (1 << i) <= n; i++){
        for (int j=0; j + (1 << i) - 1 < n; j++){
            M[i][j] = better(M[i-1][j], M[i-1][j + (1 << (i-1))]);
        }
    }
}

int rmq(int i, int j){
    int k = __lg(j-1+1);
    return better(M[k][i], M[k][j-(1<<k)+1]);
}

int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    preprocessing(n);
    int x, y;
    cin >> x >> y;
    cout << rmq(x, y);
}