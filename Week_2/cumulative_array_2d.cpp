#include <bits/stdc++.h>

using namespace std;

int a[6][6];
int s[6][6];

int cumulative_array(int m, int n){
    for (int i=1; i<=m; i++){
        for (int j=1; j<=n; j++){
            s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];
        }
    }
    return s[m][n];
}

int main(){
     int init[5][5] = {
        { 1,  2,  3,  4,  5},
        { 6,  7,  8,  9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 5; j++) a[i][j] = init[i-1][j-1];

    int m,n;

    cin >> m >> n;

    cout << cumulative_array(m, n);

}