#include <bits/stdc++.h>

using namespace std;

int N, K, Q;
int x[16];
int y[6];
int load[6];
int visited[16];
int d[16], c[16][16];
int f=0;
int fbest = INT_MAX;
int Cmin = INT_MAX;
int segments=0;
int nbr=0;

void updateBest(){
    if (f<fbest){
        fbest = f;
    }
}

bool checkX(int v, int k){
    if(v>0 && visited[v]) return false;
    if(load[k] + d[v] > Q) return false;
    return true;
}

void TRY_X(int s, int k){
    if (s==0){
        if(k<K){
            TRY_X(y[k+1], k+1);
        }
        return;
    }
    for (int v=0; v<=N; v++){
        if (!checkX(v, k)) continue;
        x[s] = v; visited[v] = true;
        f += c[s][v]; load[k] += d[v];
        segments++;
        if (v>0){
            if(f + (nbr+N-segments)*Cmin < fbest){
                TRY_X(v, k);
            } 
        }
        else{
            if(k==K){
                if (segments==nbr+N){
                    updateBest();
                }
            }
            else{
                if(f + (nbr+N-segments)*Cmin < fbest){
                    TRY_X(y[k+1], k+1);
                }
            }
        }
        visited[v] = false;
        f -= c[s][v]; load[k] -= d[v];
        segments--;

    }
} 

bool checkY(int v, int k){
    if (v==0) return true;
    if (load[k] + d[v] > Q) return false;
    if (visited[v]) return false;
    return true;
}

void TRY_Y(int k){
    int s=0;
    if(y[k-1] > 0) s = y[k-1] + 1;
    for(int v=s; v<=N; v++){
        if (!checkY(v, k)) continue;
        y[k] = v;
        if (v > 0) segments++;
        visited[v] = true; load[k] += d[v];
        f += c[0][v];
        if (k<K){
            TRY_Y(k+1);
        }
        else{
            nbr = segments;
            TRY_X(y[1], 1);
        }
        visited[v] = false; load[k] -= d[v];
        f -= c[0][v];
        if (v>0) segments--;
    }
}

int main(){
    cin >> N >> K >> Q;
    for (int i=1; i <= N; i++){
        cin >> d[i];
    }
    for(int i=0; i <= N; i++){
        for (int j=0; j <= N; j++){
            cin >> c[i][j];
            if (i!=j){
                Cmin = min(c[i][j], Cmin);
            }
        }
    }
    d[0] = 0; y[0] = 0;
    TRY_Y(1);
    cout << fbest;
}