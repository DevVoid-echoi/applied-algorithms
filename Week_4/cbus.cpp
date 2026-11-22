#include <bits/stdc++.h>

using namespace std;

int n, k;
int d[30][30];
int x[30];
int bestRoute[30];
bool visited[30];
int load = 0;
int f = 0;
int fbest = INT_MAX;
int Cmin = INT_MAX;

bool check(int v){
    if (visited[v] == true){
        return false;
    }
    if (v > n){
        if (visited[v-n] == false) return false;
    }
   else{
        if (load + 1 > k){
            return false;
        }
    }
    return true;
}

void updateBest(){
    if (f + d[x[2*n]][0] < fbest){
        fbest = f + d[x[2*n]][0];
        for (int i=0; i<=2*n; i++){
            bestRoute[i] = x[i];
        }
    }
}

void TRY(int a){
    for (int v=1; v<=2*n; v++){
        if (!check(v)) continue;
        x[a] = v;
        f += d[x[a-1]][v];
        visited[v] = true;
        if (v<=n) load++; else load--;

        if (a==2*n){
            updateBest();
        }
        else if(f + Cmin * (2*n + 1 - a) < fbest){
            TRY(a+1);
        }

        f -= d[x[a-1]][v];
        visited[v] = false;
        if (v<=n) load--; else load++;
     }
}

int main(){
    cin >> n >> k;
    x[0] = 0;
    for (int i=0; i<=2*n; i++){
        for (int j=0; j<= 2*n; j++){
            cin >> d[i][j];
            if (i!=j){
                Cmin = min(Cmin, d[i][j]);
            }
        }
    }
    TRY(1);
    cout << fbest << endl;
    for (int i=0; i<=2*n; i++){
        cout << bestRoute[i] << " ";
    }
}

