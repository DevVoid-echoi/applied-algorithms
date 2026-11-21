// RMQ (Sparse Table) - phien ban IN RA TUNG BUOC CHAY
// Input: n, a[0..n-1], roi 1 dong "x y"
#include <bits/stdc++.h>
using namespace std;

int M[20][1000];
int a[1000];

int better(int x, int y){
    return (a[x] <= a[y]) ? x : y;
}

void preprocessing(int n){
    cout << "===== TIEN XU LY =====\n";

    // Hang 0: doan dai 1
    for (int j = 0; j < n; j++) M[0][j] = j;
    cout << "\n[i = 0] Doan dai 1: M[0][j] = j\n";

    for (int i = 1; (1 << i) <= n; i++){
        int len  = 1 << i;          // do dai doan o hang i
        int half = 1 << (i-1);      // do dai moi nua
        cout << "\n[i = " << i << "] Doan dai " << len
             << " (ghep 2 nua, moi nua dai " << half << ")\n";

        for (int j = 0; j + len - 1 < n; j++){
            int L = M[i-1][j];          // chi so min cua nua trai
            int R = M[i-1][j + half];   // chi so min cua nua phai
            M[i][j] = better(L, R);

            cout << "  M[" << i << "][" << j << "] doan [" << j << "," << j + len - 1 << "]: "
                 << "trai M[" << i-1 << "][" << j << "]=" << L << " (a=" << a[L] << ")"
                 << " vs phai M[" << i-1 << "][" << j + half << "]=" << R << " (a=" << a[R] << ")"
                 << "  -> " << M[i][j] << "\n";
        }
    }

    // In ca bang M
    cout << "\n===== BANG M =====\n     j:";
    for (int j = 0; j < n; j++) cout << setw(4) << j;
    cout << "\n";
    for (int i = 0; (1 << i) <= n; i++){
        cout << "i = " << setw(2) << i << ":";
        for (int j = 0; j < n; j++){
            if (j + (1 << i) - 1 < n) cout << setw(4) << M[i][j];
            else cout << setw(4) << "-";
        }
        cout << "\n";
    }
}

int rmq(int i, int j){
    cout << "\n===== TRUY VAN RMQ(" << i << ", " << j << ") =====\n";

    int len = j - i + 1;
    int k = __lg(len);
    cout << "Buoc 1: do dai = " << j << " - " << i << " + 1 = " << len
         << ", k = floor(log2(" << len << ")) = " << k
         << "  -> dung 2 doan dai 2^" << k << " = " << (1 << k) << "\n";

    int s2 = j - (1 << k) + 1;
    int x = M[k][i];
    int y = M[k][s2];
    cout << "Buoc 2: doan 1 bat dau tai i = " << i
         << ": [" << i << "," << i + (1 << k) - 1 << "] -> M[" << k << "][" << i << "] = "
         << x << " (a=" << a[x] << ")\n";
    cout << "        doan 2 ket thuc tai j = " << j
         << ": [" << s2 << "," << j << "] -> M[" << k << "][" << s2 << "] = "
         << y << " (a=" << a[y] << ")\n";

    int res = better(x, y);
    cout << "Buoc 3: so sanh a=" << a[x] << " va a=" << a[y]
         << " -> RMQ(" << i << ", " << j << ") = " << res << " (a=" << a[res] << ")\n";
    return res;
}

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    int x, y;
    cin >> x >> y;

    cout << "Day a:\n  chi so:";
    for (int i = 0; i < n; i++) cout << setw(4) << i;
    cout << "\n  gia tri:";
    for (int i = 0; i < n; i++) cout << setw(4) << a[i];
    cout << "\n\n";

    preprocessing(n);

    int res = rmq(x, y);
    cout << "\nKET QUA: " << res << "\n";
}